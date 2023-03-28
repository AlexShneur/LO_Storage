#include "mainwindow.h"
#include "dialogpullfile.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "dialogpushfile.h"
#include "qtextstream.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadParamsFromConfigFile();
    ui->progressBar->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveParamsToConfigFile() const
{
    QFile file("configParams.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << ui->leHostName->text() << "\n"
            << ui->lePort->text() << "\n"
            << ui->leDBName->text() << "\n"
            << ui->leUserName->text() << "\n"
            << ui->lePassword->text() << "\n";
    }
    //else
    //    QMessageBox::critical(this, this->windowTitle(),tr("Не удалось сохранить параметры подключения к БД в файл."));
}

void MainWindow::loadParamsFromConfigFile()
{
    QFile file("configParams.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        ui->leHostName->setText(in.readLine());
        ui->lePort->setText(in.readLine());
        ui->leDBName->setText(in.readLine());
        ui->leUserName->setText(in.readLine());
        ui->lePassword->setText(in.readLine());
    }
    //else
        //QMessageBox::critical(this, this->windowTitle(),tr("Не удалось открыть файл с параметрами подключения к БД"));
}

void MainWindow::on_pbConnect_clicked()
{
    try
    {
        DBConnection = std::make_shared<PGConnection>(ui->leHostName->text().toStdString(),
                                 ui->lePort->text().toInt(),
                                 ui->leDBName->text().toStdString(),
                                 ui->leUserName->text().toStdString(),
                                 ui->lePassword->text().toStdString());

        DBOperations = std::make_shared<PGOperations>(this);
        connect(DBOperations.get(), SIGNAL(inProgress(int)), this, SLOT(updateProgress(int)));

        //создаём таблицу files в бд
        std::string query = "CREATE TABLE IF NOT EXISTS files "
                            "(id SERIAL PRIMARY KEY, "
                            "name VARCHAR(256) NOT NULL, "
                            "description VARCHAR(1024), "
                            "size BIGINT NOT NULL, "
                            "downloaddate TIMESTAMP NOT NULL, "
                            "data OID NOT NULL)";

        if (DBOperations->ExecuteQuery(DBConnection->connection(),query))
        {
            auto err = DBOperations->GetLastError();
            QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось создать таблицу в БД. Ошибка: ").arg(QString::fromStdString(err)));
        }
        else
        {
            QMessageBox::information(this, this->windowTitle(),tr("Соединение с базой данных установлено."));

            saveParamsToConfigFile();

            ui->pbConnect->setDisabled(true);
            ui->wConnection->setDisabled(true);
            ui->pbDisconnect->setDisabled(false);
            ui->pbPush->setDisabled(false);
            ui->pbPull->setDisabled(false);
        }
    }
    catch (std::exception& ex)
    {
        QMessageBox::critical(this, this->windowTitle(), tr(ex.what()));
    }
}


void MainWindow::on_pbDisconnect_clicked()
{
    DBConnection = nullptr;
    DBOperations = nullptr;

    ui->pbConnect->setDisabled(false);
    ui->wConnection->setDisabled(false);
    ui->pbDisconnect->setDisabled(true);
    ui->pbPush->setDisabled(true);
    ui->pbPull->setDisabled(true);
}


void MainWindow::on_pbPush_clicked()
{
    QString dir = QDir::homePath();
    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Открыть файл"), dir,
        tr("Все файлы (*)"));

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Не удалось открыть файл!"),
                file.errorString());
        }
        else
        {
            QFileInfo fileInfo(file);
            stFileDescription fd;
            fd.fName = fileInfo.fileName();
            fd.fSize = fileInfo.size();

            auto query = "SELECT MAX(id) FROM files";
            std::vector<std::string> values;
            if (DBOperations->ExecuteQueryReturnValues(DBConnection->connection(),query, values))
            {
                auto err = DBOperations->GetLastError();
                QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось получить индекс последней записи из БД. Ошибка: ").arg(QString::fromStdString(err)));
            }
            else
            {
                fd.DBIndex = values[0].empty() ? 1 : stoi(values[0]);
                auto dialogPushFile = new DialogPushFile(this,fd);
                if (dialogPushFile->exec()==QDialog::Accepted)
                {
                    ui->progressBar->setVisible(true);
                    fd = dialogPushFile->GetFileDescription();
                    delete dialogPushFile;

                    setProgressBarParams(fd);

                    auto lo = DBOperations->ImportFile(DBConnection->connection(),file);
                    auto err = DBOperations->GetLastError();
                    if (err.empty())
                    {
                        query = "INSERT INTO files (name, description, size, downloaddate, data) "
                                " VALUES ($1::varchar, $2::varchar, $3::bigint, now(), $4::oid)";
                        const char* name = fd.fName.toStdString().c_str();
                        const char* desc = fd.fDesc.toStdString().c_str();
                        const char* size = std::to_string(fd.fSize).c_str();
                        const char* loObj = std::to_string(lo).c_str();

                        const char* params[PARAMS_COUNT-1] = {name, desc, size ,loObj};

                        if (DBOperations->ExecuteQueryWithParams(DBConnection->connection(),query, &params[0]))
                        {
                            auto err = DBOperations->GetLastError();
                            QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось загрузить файл в БД. Ошибка: ").arg(QString::fromStdString(err)));
                        }
                        else
                        {
                            ui->progressBar->setValue(ui->progressBar->maximum());
                            QMessageBox::information(this, this->windowTitle(),tr("Файл успешно загружен в БД."));
                        }
                    }
                    else
                    {
                        QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось загрузить файл в БД. Ошибка: ").arg(QString::fromStdString(err)));
                    }
                    ui->progressBar->setVisible(false);
                }
            }
        }
    }
}

void MainWindow::updateProgress(int val)
{
    ui->progressBar->setValue(ui->progressBar->value()+val);
}

void MainWindow::setProgressBarParams(const stFileDescription& fd) const
{
    int step_count = static_cast<int>(fd.fSize/BUFSIZE);
    ui->progressBar->setRange(0, step_count);
    ui->progressBar->setValue(0);
}

void MainWindow::on_pbPull_clicked()
{
    auto query = "SELECT id, name, description, size, downloaddate, data FROM files";
    std::vector<std::string> values;
    if (DBOperations->ExecuteQueryReturnValues(DBConnection->connection(),query,values))
    {
        auto err = DBOperations->GetLastError();
        QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось получить данные из БД. Ошибка: ").arg(QString::fromStdString(err)));
    }
    else
    {
        auto dialogPullFile = new DialogPullFile(this);
        dialogPullFile->SetData(values);
        dialogPullFile->show();
        if (dialogPullFile->exec()==QDialog::Accepted)
        {
            auto fileDesc = dialogPullFile->GetFileDescription();
            if (fileDesc.DBIndex!=-1)
            {
                ui->progressBar->setVisible(true);
                QString dir = QDir::homePath();
                auto fileName = QFileDialog::getSaveFileName(this,
                    tr("Сохранить файл"), dir+"/"+fileDesc.fName,
                    tr("Все файлы (*)"));
                if (!fileName.isEmpty())
                {
                    setProgressBarParams(fileDesc);

                    DBOperations->ExportFile(DBConnection->connection(),fileDesc.DBIndex,fileName);
                    auto err = DBOperations->GetLastError();
                    if (err.empty())
                    {
                        ui->progressBar->setValue(ui->progressBar->maximum());
                        QMessageBox::information(this, this->windowTitle(),tr("Файл успешно выгружен из БД."));
                    }
                    else
                    {
                        QMessageBox::critical(this, this->windowTitle(),QString("%1 %2").arg("Не удалось выгрузить файл из БД. Ошибка: ").arg(QString::fromStdString(err)));
                    }
                }
                ui->progressBar->setVisible(false);
            }
        }
    }
}

