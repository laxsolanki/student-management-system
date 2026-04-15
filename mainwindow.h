#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_Add_clicked();
    void on_ViewAll_clicked();
    void on_Search_clicked();
    void on_Delete_clicked();
    void on_Update_clicked();
    void on_Exit_clicked();
    void on_refreshButton_clicked();
    void on_tableWidget_cellClicked(int row, int column);


    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
