#ifndef DIALOGPULLFILE_H
#define DIALOGPULLFILE_H

#include <QDialog>

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
    std::pair<QString,int> GetSelectedFileNameAndOid() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_twRecords_cellClicked(int row, int column);

private:
    Ui::DialogPullFile *ui;
    QString fName;
    int fOid;
};

#endif // DIALOGPULLFILE_H
