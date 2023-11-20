#ifndef DAYINFO_H
#define DAYINFO_H

#include "qdatetime.h"
#include "weatherinfo.h"
#include <QObject>
#include <QTime>

class DayInfo : public QObject
{
    Q_OBJECT
public:
    explicit DayInfo(QObject *parent = nullptr);

signals:

private:
    QDate date;
    QMap<QTime, WeatherInfo*> forecast;
};

#endif // DAYINFO_H
