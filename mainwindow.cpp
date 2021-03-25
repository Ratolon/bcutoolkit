#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createActions();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::exit(){
    // Finalizar ejecucion
    exit();
}

void MainWindow::createActions()
{
    // Menu bar: exit
    connect(this->ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
}

