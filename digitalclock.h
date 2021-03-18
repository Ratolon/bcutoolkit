#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QObject>
#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>


class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DigitalClock(QWidget *parent = nullptr);

private slots:
    void showTime();
};

#endif // DIGITALCLOCK_H
