#ifndef DRIVES_H
#define DRIVES_H
//#include<QDomDocument>
#include<QString>
#include <QFile>
#include<QTextStream>
#include <QDomDocument>


class domdocuments
{
public:
    domdocuments();
    ~domdocuments();

    int writexml();
    int readxml();
    int readxml2();
    void var_test(int var);
private:
    QString filename;
    QFile file_all;
    //QTextStream output;
};

#endif // DRIVES_H
