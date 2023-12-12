#include "weathercontroller.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QDateTime>
#include <QTime>

WeatherController::WeatherController(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &WeatherController::onNetworkReply);
}

void WeatherController::getCurrentWeather(QString city)
{
    QString apiUrl = "https://api.openweathermap.org/data/2.5";
    QString apiKey = "22bd0da1b9e4b48079ec27a4b17235d6";
    QString url(apiUrl + "/weather?q=" + city + "&appid=" + apiKey + "&units=metric");
    qDebug() << "GET " + url;
    QNetworkRequest request(url);
    networkManager->get(request);
}

void WeatherController::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error()) {
        qInfo() << "Error:" << reply->errorString();
        emit errorOccurred(reply->errorString());
        return;
    }
    QString responseStr = reply->readAll();
    emit dataReceived(responseStr);
}
