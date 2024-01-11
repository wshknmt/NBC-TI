#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QDir>

#include "MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_filesList_itemSelectionChanged();

    void on_startButton_clicked();

    void on_checkBoxTI_clicked();

private:
    Ui::StartWindow *ui;
};
#endif // STARTWINDOW_H
