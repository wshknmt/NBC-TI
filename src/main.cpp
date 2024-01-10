#include <QApplication>
#include <QPainter>
#include <QWidget>
#include "MainWindow.h"
#include <filesystem>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    const int windowHeight = 900;
    MainWindow mainWindow;
    std::string dataSet = "my2.txt";
    std::string path = "C:\\Users\\pawel\\Desktop\\medVSCODE 3\\MED\\data\\";
    char delimiter = ',';

    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current directory: " << currentPath << std::endl;

    mainWindow.startAlghoritm(path + dataSet, delimiter, 50);
    mainWindow.setFixedSize(1500, windowHeight);
    QString dataSetQString = QString::fromStdString(dataSet);
    mainWindow.setWindowTitle(dataSetQString);
    mainWindow.show();

    return a.exec();
}
