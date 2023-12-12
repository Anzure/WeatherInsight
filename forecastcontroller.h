#ifndef FORECASTCONTROLLER_H
#define FORECASTCONTROLLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ForecastController : public QObject
{
    Q_OBJECT
public:
    explicit ForecastController(QObject *parent = nullptr);

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &error);

public slots:
    void getWeatherForecast(QString city);

private slots:
    void onNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // FORECASTCONTROLLER_H
