#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"
#include<QDebug>

QWidget* widgetActual = NULL;
QWidget* mainpage = NULL;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createActions();

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
    if(widgetActual != NULL) clearLayout(this->ui->contenedorPrincipal);
    widgetActual = NULL;
}

void MainWindow::loadMainWindow(){
    if (widgetActual == NULL){
        mainpage = new mainPage();
        this->ui->contenedorPrincipal->addWidget(mainpage);
        widgetActual = mainpage;
    }
}

void MainWindow::exit(){
    // Finalizar ejecucion
    exit();
}

void MainWindow::createActions()
{
    // Menu bar: exit
    connect(this->ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
    connect(this->ui->actionViewEmpty, &QAction::triggered, this, &MainWindow::clearMainContainer);
    connect(this->ui->actionViewMain, &QAction::triggered, this, &MainWindow::loadMainWindow);
}

