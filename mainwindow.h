#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSpinBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_file_generate_clicked();

    //void on_pushButton_Exit_clicked();

    //void on_var_num_spinBox_valueChanged(int arg1);

    //void var_test(int vec_var_test);
private:
    Ui::MainWindow *ui;
    int zhixing_value;
    int var_num;

};

#endif // MAINWINDOW_H
