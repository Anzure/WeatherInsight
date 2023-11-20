#include "modelcontroller.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QJsonValue>
#include <QDateTime>
#include <QTime>

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
    QString url(apiUrl + "/forecast?q=" + city + "&appid=" + apiKey);
    qInfo() << "GET " + url;
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
    qDebug() << "Response:" << responseStr;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(responseStr.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

    QJsonArray dataPointList = jsonObject["list"].toArray();
    for (const QJsonValue &value : dataPointList) {
        QJsonObject dataPointObj = value.toObject();

        QString timestamp = dataPointObj["dt_txt"].toString();
        QDateTime dateTime = QDateTime::fromString(timestamp, "yyyy-MM-dd HH:mm:ss");
        //if (dateTime.time().hour() != 15) continue;
        QString dateValue = dateTime.toString("dd.MM.yyyy HH:mm");
        QDate date = dateTime.date();

        QJsonArray weatherArray = dataPointObj["weather"].toArray();
        QJsonObject weatherObj = weatherArray.at(0).toObject();
        QString weatherIcon = weatherObj["icon"].toString();
        QString weatherDesc = weatherObj["description"].toString();
        QString iconUrl = "https://openweathermap.org/img/wn/" + weatherIcon + "@2x.png";

        QJsonObject mainDetailsObj = dataPointObj["main"].toObject();
        double temperature = mainDetailsObj["temp"].toDouble();

        WeatherInfo* weatherInfo = new WeatherInfo();
        weatherInfo->setTimestamp(dateTime);
        weatherInfo->setDescription(weatherDesc);
        weatherInfo->setTemperature(temperature);
        weatherInfo->setIconUrl(iconUrl);

        //DayInfo dayInfo = DayInfo();
        //for (const DayInfo *otherDay : dayInfoList) {
        //    if (otherDay-)
        //}

        //QMap<QTime, WeatherInfo> dayForecast = *new QMap<QTime, WeatherInfo>();
        //dayInfoList.append(dayInfo);
        //dayForecast.insert(dateTime.time(), *weatherInfo);

        qInfo() << dateValue + " -> " + weatherDesc + ", " + QString::number(temperature) + " degrees";

    }
}
