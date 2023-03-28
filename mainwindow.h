#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qdatetime.h"
#include "pgconnection.h"
#include "pgoperations.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct stFileDescription
{
    QString fName;
    QString fDesc;
    long long fSize;
    QDateTime downloadedDate;
    int DBIndex;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

Q_SLOT void updateProgress(int val);

private slots:
    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

    void on_pbPush_clicked();

    void on_pbPull_clicked();

private:
    void saveParamsToConfigFile() const;
    void loadParamsFromConfigFile();
    void setProgressBarParams(const stFileDescription& fd) const;

    Ui::MainWindow *ui;
    std::shared_ptr<PGConnection> DBConnection = nullptr;
    std::shared_ptr<PGOperations> DBOperations = nullptr;
};
#endif // MAINWINDOW_H
