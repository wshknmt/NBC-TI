#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    const int windowHeight = 900;
    MainWindow mainWindow;

    std::string dataSet = "zelnik4.txt";
    std::string path = "C:\\Users\\pawel\\Desktop\\medVSCODE 3\\MED\\data\\";
    bool TIEnabled = true;

    mainWindow.startAlghoritm(path + dataSet, ',', 50, TIEnabled);
    mainWindow.setFixedSize(1500, windowHeight);
    QString dataSetQString = QString::fromStdString(dataSet);
    mainWindow.setWindowTitle(dataSetQString);
    mainWindow.show();

    return a.exec();
}
