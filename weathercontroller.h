#ifndef WEATHERCONTROLLER_H
#define WEATHERCONTROLLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherController : public QObject
{
    Q_OBJECT
public:
    explicit WeatherController(QObject *parent = nullptr);

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &error);

public slots:
    void getCurrentWeather(QString city);

private slots:
    void onNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // WEATHERCONTROLLER_H
