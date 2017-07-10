/* SCOTS GUI Main code
 *
 * Created by: Aneesh Dahiya
 *
 * 10/July/2017
 *
 */


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
