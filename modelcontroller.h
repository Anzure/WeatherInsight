#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ModelController : public QObject
{
    Q_OBJECT
public:
    explicit ModelController(QObject *parent = nullptr);

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &error);

public slots:
    void getWeatherData(QString city);

private slots:
    void onNetworkReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
};

#endif // MODELCONTROLLER_H
