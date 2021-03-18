#ifndef MACHINESOVERVIEW_H
#define MACHINESOVERVIEW_H

#include <QWidget>

namespace Ui {
class MachinesOverview;
}

class MachinesOverview : public QWidget
{
    Q_OBJECT

public:
    explicit MachinesOverview(QWidget *parent = nullptr);
    ~MachinesOverview();

private:
    Ui::MachinesOverview *ui;
};

#endif // MACHINESOVERVIEW_H
