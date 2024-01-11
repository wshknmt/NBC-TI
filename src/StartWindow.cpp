#include "StartWindow.h"
#include "ui_StartWindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    QString directoryPath = "C:\\Users\\pawel\\Desktop\\medVSCODE 3\\MED\\data\\";
    QDir directory(directoryPath);
    QStringList fileList = directory.entryList(QDir::Files);
    ui->filesList->addItems(fileList);
}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_filesList_itemSelectionChanged() {
    ui->startButton->setEnabled(!ui->filesList->selectedItems().isEmpty());
}


void StartWindow::on_startButton_clicked() {
    ui->startButton->setEnabled(false);
    QString selectedFileName;
    if (ui->filesList->currentItem() != nullptr) {
        selectedFileName = ui->filesList->currentItem()->text();
    }
    int k;
    if (ui->kText->text().isEmpty())
        k = 50;
    else
        k = ui->kText->text().toInt();

    const int windowHeight = 900;
    MainWindow* mainWindow = new MainWindow;
    std::string dataSet = selectedFileName.toStdString();
    std::string path = "C:\\Users\\pawel\\Desktop\\medVSCODE 3\\MED\\data\\";
    bool TIEnabled = ui->checkBoxTI->isChecked();

    mainWindow->startAlghoritm(path + dataSet, ',', k, TIEnabled);
    mainWindow->setFixedSize(1500, windowHeight);
    QString dataSetQString = QString::fromStdString(dataSet);
    mainWindow->setWindowTitle(dataSetQString);
    mainWindow->show();

    // this->close();

}

void StartWindow::on_checkBoxTI_clicked() {
    ui->startButton->setEnabled(!ui->filesList->selectedItems().isEmpty());
}

