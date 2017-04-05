#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString filePath = QFileDialog::getOpenFileName(
                this,
                "Open a file",
                QString(),
                "Images (*.png *.gif *.jpg *.jpeg)");

    pimg = new QImage(filePath);

    ui->FilePathLabel->setText( filePath );




    QPixmap pixmap(filePath);


    ui->DrawingLabel->setPixmap(pixmap);
}

void MainWindow::on_pushButton_2_clicked()
{
    saveFileName = "African.png";
    pimg->save(saveFileName);
}
