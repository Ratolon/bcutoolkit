#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"
#include<QDebug>

QWidget* widgetActual;
QWidget* mainpage;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createActions();
    mainpage = new mainPage();

    this->ui->contenedorPrincipal->insertWidget(0, mainpage);
    qInfo() << "berga1\n";
    this->ui->contenedorPrincipal->removeWidget(this->ui->contenedorPrincipal->widget());
    qInfo() << "berga2\n";
}

void MainWindow::clearLayout(QLayout* layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearMainContainer(){
    clearLayout(this->ui->contenedorPrincipal);
}

void MainWindow::exit(){
    // Finalizar ejecucion
    exit();
}

void MainWindow::createActions()
{
    // Menu bar: exit
    connect(this->ui->actionExit, &QAction::triggered, this, &MainWindow::clearMainContainer);
}

