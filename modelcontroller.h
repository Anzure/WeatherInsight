#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <dayinfo.h>
#include <weatherinfo.h>

class ModelController : public QObject
{
    Q_OBJECT
public:
    explicit ModelController(QObject *parent = nullptr);

signals:

public slots:
    void getWeatherData(QString city);

private slots:
    void onNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    QList<DayInfo*> dayInfoList;
};

#endif // MODELCONTROLLER_H
