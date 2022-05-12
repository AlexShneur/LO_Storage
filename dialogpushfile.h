#ifndef DIALOGPUSHFILE_H
#define DIALOGPUSHFILE_H

#include <QDialog>
#include "mainwindow.h"
#include "qdatetime.h"

namespace Ui {
class DialogPushFile;
}

class DialogPushFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPushFile(QWidget *parent,
                            stFileDescription _fd);
    ~DialogPushFile();

    stFileDescription GetFileDescription() const
    {
        return fd;
    }

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogPushFile *ui;
    stFileDescription fd;
};

#endif // DIALOGPUSHFILE_H
