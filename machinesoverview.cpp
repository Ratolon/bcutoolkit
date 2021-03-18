#include "machinesoverview.h"
#include "ui_machinesoverview.h"

MachinesOverview::MachinesOverview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MachinesOverview)
{
    ui->setupUi(this);
}

MachinesOverview::~MachinesOverview()
{
    delete ui;
}
