#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dom.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_file_generate,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_file_generate_clicked()),Qt::UniqueConnection);
   // QObject::connect(ui->var_num_spinBox,SIGNAL(ui->var_num_spinBox->valueChanged(const QString "cde")),this,SIGNAL())
    //var_test(var_num);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_file_generate_clicked()
{
    var_num = ui->var_num_spinBox->text().toInt();
    domdocuments dom_xml;
    dom_xml.writexml();
    if(var_num == 0)
    {
      QMessageBox Message1;
      Message1.setText("The num can't be zero,please reset again");
      Message1.exec();
    }
    else
    {
        dom_xml.var_test(var_num);
        QMessageBox Message;
        Message.setText("The file has been generated successfuly");
        Message.exec();
        qDebug() << "The End";
    }

}

