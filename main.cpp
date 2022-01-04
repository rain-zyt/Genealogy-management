#include "mainwindow.h"
#include "genealogy.h"

#include <QApplication>


int main(int argc, char *argv[])
{
/*    genealogy g1;
    g1.addperson("1","0",true,"0","0","0");
    g1.addperson("2","1",true,"0","0","0");
    g1.addperson("3","1",true,"0","0","0");
    g1.addperson("4","3",true,"0","0","0");
    g1.addperson("5","4",true,"0","0","0");
    system("pause");
    g1.deleteperson("3");
    system("pause");*/

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("家谱管理系统");
    w.show();
    return a.exec();
}
