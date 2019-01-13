#include "mainwindow.h"
#include <QApplication>
#include "dom.h"
#include <QDebug>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        //domdocuments dom;
        //dom.writexml();
        //dom.readxml();
    for(int i = -15; i < 46 ; i += 5)
    {
        for(int j = -i; j < 16; j += 5)
            qDebug() << i << j << endl;
    }
        qDebug() << "The Start";
        //dom.readxml2();
        QDir d;                  //创建一个目录的对象
        d.mkpath("./123");
        MainWindow w;
        w.show();
       // w.var_test(var_num);

    return a.exec();

}
