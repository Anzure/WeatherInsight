#include "modelcontroller.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

ModelController::ModelController(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished,
            this, &ModelController::onNetworkReply);
}

void ModelController::getWeatherData(QString city)
{
    QString apiUrl = "https://api.openweathermap.org/data/2.5";
    QString apiKey = "22bd0da1b9e4b48079ec27a4b17235d6";
    QString url(apiUrl + "/weather?q=" + city + "&appid=" + apiKey);
    qInfo() << "GET " << url;
    QNetworkRequest request(url);
    networkManager->get(request);
}

void ModelController::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << "Error:" << reply->errorString();
        return;
    }

    QString responseStr = reply->readAll();
    qInfo() << "Response: " << responseStr;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseStr.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
}

