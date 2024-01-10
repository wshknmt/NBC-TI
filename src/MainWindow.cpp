#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    textGroupAmount = new QTextEdit(this);
    // Set the size policy if needed
    textGroupAmount->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Set initial text if needed
    textGroupAmount->setText("Group amount: 40");
    // textGroupAmount->setFontPointSize(50);
    QFont currentFont = textGroupAmount->font();
    currentFont.setPointSize(20); // Set the desired font size
    textGroupAmount->setFont(currentFont);

    // Set the position and size of the textEditWidget
    textGroupAmount->setGeometry(1100, 10, 250, 50);
    textGroupAmount->setEnabled(false);

     // Add the textEditWidget to the layout or directly to the main window
    //  setCentralWidget(textGroupAmount);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

//    std::random_device rd;
//    std::mt19937 g(rd());

    int pointSize = 5;
    QVector<QColor> colors;
//    int hueNumber = 30;
//    int valueNumber = 3;
    // Create an array of 100 different colors

//    for (int i = 0; i < hueNumber; ++i) {
//        for (int j = 0; j < valueNumber; j++) {
//            colors.append(QColor::fromHsv(i * 255 / hueNumber, 255, 255 - (j * 255 / valueNumber)));
//        }
//    }

      // Choose any value as the seed
    srand(seed);  // Set the seed
    for (int i = 0; i < maxLabel; ++i) {
        int r = rand()%256;
        int g = rand()%256;
        int b = rand()%256;
        QColor color(r, g, b);
        colors.append(color);
    }
//    std::shuffle(colors.begin(), colors.end(), g);

    // Draw points with different colors
//    for (int i = 0; i < colors.size(); ++i) {
//        painter.setPen(QPen(colors[i], pointSize));
//        painter.drawPoint(20 + i * 20, 20);
//    }
    const int windowHeight = 890;
    for (int i = 0; i < points.size(); ++i) {
        int label = points[i].getLabel();
//        painter.setPen(QPen(Qt::black, pointSize));
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
    std::cout<<"Udało się";
}

void MainWindow::startAlghoritm(std::string dataset, char delimiter, int k) {
    std::cout<<"name: "<<dataset;
    NBC nbc(dataset, delimiter, k);
    nbc.printPoints();
    nbc.printMaxLabel();

    points = nbc.getPoints();
    maxLabel = nbc.getGroupIndex();
    minX = nbc.getMinX();
    minY = nbc.getMinY();
    maxX = nbc.getMaxX();
    maxY = nbc.getMaxY();
    // int groups = nbc.getGroupIndex();
    textGroupAmount->setText("Group amount: " + QString::number(nbc.getGroupIndex()));

}

