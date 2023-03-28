#include "dialogpullfile.h"
#include "pgoperations.h"
#include "ui_dialogpullfile.h"
#include <QMessageBox>

DialogPullFile::DialogPullFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPullFile)
{
    ui->setupUi(this);

    ui->twRecords->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID")));
    ui->twRecords->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Наименование")));
    ui->twRecords->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Краткое описание")));
    ui->twRecords->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Размер файла, байт")));
    ui->twRecords->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Дата загрузки")));
    ui->twRecords->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Oid файла")));

    ui->twRecords->setSelectionMode(QAbstractItemView::SingleSelection);
}

DialogPullFile::~DialogPullFile()
{
    delete ui;
}

void DialogPullFile::SetData(const std::vector<std::string> &values)
{
    auto rowsCnt = (int)(values.size() / (PARAMS_COUNT+1));    //не забываем про поле id
    auto colsCnt = PARAMS_COUNT+1;
    ui->twRecords->setRowCount(rowsCnt+1);
    ui->twRecords->setColumnCount(colsCnt);
    auto currInd = 0;
    for (auto i=0; i<rowsCnt; i++)
    {
        for (auto j=0; j<colsCnt; j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignCenter);
            item->setText(QString::fromStdString(values[currInd]));
            ui->twRecords->setItem(i+1,j,item);
            currInd++;
        }
    }
    ui->twRecords->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void DialogPullFile::on_buttonBox_accepted()
{
    try
    {
        accept();
    }
    catch (std::exception& ex)
    {
        QMessageBox::critical(this, this->windowTitle(), tr(ex.what()));
    }
}


void DialogPullFile::on_buttonBox_rejected()
{
    reject();
}


void DialogPullFile::on_twRecords_cellClicked(int row, int column)
{
    if (row!=0)
    {
        fd.fName = ui->twRecords->item(row,PARAMS_COUNT-4)->text();
        fd.fDesc = ui->twRecords->item(row,PARAMS_COUNT-3)->text();
        fd.fSize = ui->twRecords->item(row,PARAMS_COUNT-2)->text().toLongLong();
        fd.downloadedDate = QDateTime::fromString(ui->twRecords->item(row,PARAMS_COUNT-1)->text());
        fd.DBIndex = ui->twRecords->item(row,PARAMS_COUNT)->text().toInt();
    }
}

