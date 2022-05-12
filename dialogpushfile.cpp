#include "dialogpushfile.h"
#include "mainwindow.h"
#include "ui_dialogpushfile.h"
#include <QMessageBox>

DialogPushFile::DialogPushFile(QWidget *parent,
                               stFileDescription _fd) :
    QDialog(parent),
    ui(new Ui::DialogPushFile)
{
    ui->setupUi(this);

    fd = _fd;

    ui->leFileName->setText(fd.fName);
    ui->leFileSize->setText(QString::number(fd.fSize));
    ui->leDB_Index->setText(QString::number(fd.DBIndex));

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dteDownloadDate->setDateTime(currentDateTime);

    fd.downloadedDate = currentDateTime;
}

DialogPushFile::~DialogPushFile()
{
    delete ui;
}

void DialogPushFile::on_buttonBox_accepted()
{
    try
    {
        fd.fName = ui->leFileName->text();
        fd.fDesc = ui->teFileDescription->toPlainText();
        fd.downloadedDate = ui->dteDownloadDate->dateTime();
        accept();
    }
    catch (std::exception& ex)
    {
        QMessageBox::critical(this, this->windowTitle(), tr(ex.what()));
    }
}


void DialogPushFile::on_buttonBox_rejected()
{
    reject();
}

