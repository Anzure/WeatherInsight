#ifndef CURRENTWEATHER_H
#define CURRENTWEATHER_H

#include <QObject>

class CurrentWeather : public QObject
{
    Q_OBJECT
public:
    explicit CurrentWeather(QObject *parent = nullptr);

signals:

};

#endif // CURRENTWEATHER_H
