#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    textGroupAmount = new QTextEdit(this);
    textGroupAmount->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont currentFont = textGroupAmount->font();
    currentFont.setPointSize(20);
    textGroupAmount->setFont(currentFont);
    textGroupAmount->setGeometry(1100, 10, 300, 50);
    textGroupAmount->setEnabled(false);

    textElapsedTime = new QTextEdit(this);
    textElapsedTime->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    currentFont.setPointSize(15);
    textElapsedTime->setFont(currentFont);
    textElapsedTime->setGeometry(1100, 70, 300, 50);
    textElapsedTime->setEnabled(false);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    int pointSize = 5;
    QVector<QColor> colors;
    srand(seed);
    for (int i = 0; i < maxLabel; ++i) {
        int r = rand()%256;
        int g = rand()%256;
        int b = rand()%256;
        QColor color(r, g, b);
        colors.append(color);
    }

    const int windowHeight = 890;
    for (int i = 0; i < points.size(); ++i) {
        int label = points[i].getLabel();
        if (label <= 0)
            painter.setPen(QPen(Qt::black, pointSize));
        else
            painter.setPen(QPen(colors[label-1], pointSize));
        double x = (points[i].getX() - minX) / (maxX - minX) * (windowHeight - 5) + 5;
        double y = (points[i].getY() - minY) / (maxY - minY) * (windowHeight - 5) + 5;
        int x1 = std::round(x);
        int y1 = std::round(y);
        painter.drawPoint(x1,y1);
    }
}

void MainWindow::startAlghoritm(std::string dataset, char delimiter, int k, bool TIEnabled) {
    std::cout<<"name: "<<dataset;
    auto start_time = std::chrono::high_resolution_clock::now();
    NBC nbc(dataset, delimiter, k, TIEnabled);
    auto end_time  = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    points = nbc.getPoints();
    maxLabel = nbc.getGroupIndex();
    minX = nbc.getMinX();
    minY = nbc.getMinY();
    maxX = nbc.getMaxX();
    maxY = nbc.getMaxY();
    textGroupAmount->setText("Group amount: " + QString::number(nbc.getGroupIndex()));
    double truncatedTime = std::floor(duration.count() / 100.0) / 10000.0;
    textElapsedTime->setText("Elapsed time: " + QString::number(truncatedTime) + " seconds");

}

