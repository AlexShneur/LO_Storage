#ifndef DIALOGPULLFILE_H
#define DIALOGPULLFILE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class DialogPullFile;
}

class DialogPullFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPullFile(QWidget *parent = nullptr);
    ~DialogPullFile();

    void SetData(const std::vector<std::string>& values);

    const stFileDescription& GetFileDescription() const
    {
        return fd;
    }

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_twRecords_cellClicked(int row, int column);

private:
    Ui::DialogPullFile *ui;
    stFileDescription fd;
};

#endif // DIALOGPULLFILE_H
