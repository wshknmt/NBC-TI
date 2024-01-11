#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QTextEdit>
#include <QFont>
#include <random>
#include <chrono>
#include "NBC.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void startAlghoritm(std::string dataset, char delimiter, int k, bool TIEnabled);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const unsigned int seed = 123456;
    std::vector <Point> points;
    int maxLabel;
    double minX, minY, maxX, maxY;
    QTextEdit *textGroupAmount;
    QTextEdit *textElapsedTime;
    QTextEdit *textDBQuality;
    QTextEdit *textSilhouetteQuality;


};
#endif // MAINWINDOW_H
