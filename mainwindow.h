#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createActions();
    void clearLayout(QLayout* layout);
    Ui::MainWindow *ui;

private slots:
    void clearMainContainer();
    void loadMainWindow();
    void exit();
};
#endif // MAINWINDOW_H
