#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QTextEdit>
#include <QFont>
#include <random>
#include "NBC.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void startAlghoritm(std::string dataset, char delimiter, int k);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const unsigned int seed = 123456;
    std::vector <Point> points;
    int maxLabel;
    double minX, minY, maxX, maxY;
    QTextEdit *textGroupAmount;

};
#endif // MAINWINDOW_H
