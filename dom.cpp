#include "dom.h"
#include <QDebug>
#include <QDir>
domdocuments::domdocuments()
{
    filename="domparse.xml";
    file_all.setFileName("adawda.dat");
    QDir::setCurrent("./123");
}

domdocuments::~domdocuments()
{

}

int domdocuments::writexml()   //为了性能起见，只有在文件关闭时，数据才会真正写入，如果不想关闭文件可以使用file.plush()
{
    // QDir d;                  //创建一个目录的对象
//   d.mkpath("D:/123");      //在D盘创建一个文件夹名为123
//   QFile file(filename);
//   QDir::setCurrent("D:/123");   //将生成的文件filename放在此位置

    // d.mkpath("./123");           //在构建路径的上一级，也就是包含debug文件夹的那一级                               //创建一个文件夹名为123
     QFile file(filename);
     QDir::setCurrent("./123");   //将生成文件放在新建的文件夹下

     if(!file_all.open(QIODevice::WriteOnly|QIODevice::Truncate))
         return -2;
     QTextStream output(&file_all);
     output << "QOWDOW" << endl << "xagerrrrrrrrrrrrrrrrrr" << endl;

    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return -2;
    QTextStream out(&file);
    out << "alcalcnal" << endl;
    QDomDocument doc;        //表示一个XML文档，概念上讲是整个树的根节点
    QDomText text;           //表示xml文档解析后的内容
    QDomElement element;     //代表Dom树中的一个元素
    QDomAttr attr;
    QDomAttr attr1;
    //表示 Dom树中元素的属性
    QDomProcessingInstruction instruction;//表示一个xml处理指令，用来处理
                                            //或者存储特定的信息

    instruction = doc.createProcessingInstruction("xml" ,"version = \'1.0\'encoding=\'UTF-8'" );
    //doc.appendChild(element);//不太清楚加这一句的作用

    QDomElement root = doc.createElement( "COMMAND" );
       doc.appendChild(root);
       element = doc.createElement( "OBJECT" );
       text = doc.createTextNode( "USER" );
       element.appendChild(text);
       root.appendChild(element);

       element = doc.createElement( "ACTION" );
       text = doc.createTextNode( "LOGIN" );
       element.appendChild(text);
       root.appendChild(element);

       element = doc.createElement( "DATA" );
           root.appendChild(element);

           QDomElement userElement = doc.createElement( "USERINFO" );
           attr1 = doc.createAttribute( "NAME" );
           attr1.setValue("root");
           userElement.setAttributeNode(attr1);
           attr1 = doc.createAttribute( "PASSWORD" );
           attr1.setValue("123456");
           userElement.setAttributeNode(attr1);
           element.appendChild(userElement);


           element = doc.createElement( "MAYA" );
               root.appendChild(element);

               QDomElement useElement = doc.createElement( "USINFO" );
               attr = doc.createAttribute( "NME" );
               attr.setValue("rot");
               useElement.setAttributeNode(attr);
               attr = doc.createAttribute( "PASSORD" );
               attr.setValue("126");
               useElement.setAttributeNode(attr);
               element.appendChild(useElement);

               out << "aodoqdoq";
           doc.save(out, 4);       //each line space of file is 4
           return 0;


}

int domdocuments::readxml()
{
    QDomDocument doc;
    QFile file(filename);
    QString error = "";
    int row = 0, column = 0;
    if (!file.open(QIODevice::ReadOnly)) return -2;

    if(!doc.setContent(&file, false, &error, &row, &column)){
        qDebug() << "parse file failed:" << row << "---" << column <<":" <<error;
        file.close();
        return -1;
    }
    file.close();

    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    while(!node.isNull()) {
       QDomElement element = node.toElement(); // try to convert the node to an element.
       if(!element.isNull()) {
          qDebug()<<element.tagName() << ":" << element.text();
          QDomNode nodeson = element.firstChild();
          while(!nodeson.isNull()) {
              QDomElement elementson = nodeson.toElement();
              if(!elementson.isNull()) {
                  qDebug()<< "---" <<elementson.tagName();
                  if (elementson.hasAttribute("NAME")) {
                      qDebug()<< "---" << "NAME=" << elementson.attributeNode("NAME").value();
                  }
                  if (elementson.hasAttribute("PASSWORD")) {
                      qDebug()<< "---" << "PASSWORD=" << elementson.attributeNode("PASSWORD").value();
                  }
              }
              nodeson = nodeson.nextSibling();
          }
                }
                node = node.nextSibling();
             }
             return 0;
         }
int domdocuments::readxml2()
 {
     QDomDocument doc;
     QFile file(filename);
     QString error = "";
     int row = 0, column = 0;
     if (!file.open(QIODevice::ReadOnly)) return -2;
     if(!doc.setContent(&file, false, &error, &row, &column)){
         qDebug() << "parse file failed:" << row << "---" << column <<":" <<error;
         file.close();
         return -1;
     }
     file.close();

     QDomElement root = doc.documentElement();
     QDomNode node = root.firstChildElement();
     while(!node.isNull()) {
        QDomElement element = node.toElement(); // try to convert the node to an element.
        if(!element.isNull()) {
            if (element.tagName() == "DATA") {
                qDebug()<< "---" <<element.tagName();
                 QDomNodeList list = element.childNodes();
                 for(int index = 0; index < list.count(); index++) {
                     QDomNode list_node = list.item(index);
                     QDomElement list_element = list_node.toElement();
                     if (list_element.hasAttribute("NAME")) {
                         qDebug()<< "---" << "NAME =" << list_element.attributeNode("NAME").value();
                     }
                     if (list_element.hasAttribute("PASSWORD")) {
                         qDebug()<< "---" << "PASSWORD =" << list_element.attributeNode("PASSWORD").value();
                     }
                 }
            }
            else {
                           qDebug()<<element.tagName() << ":" << element.text();
                       }
                   }
                   node = node.nextSibling();
                }
                return 0;


}

void domdocuments::var_test(int var)
{
    qDebug() << var * 10;
}
