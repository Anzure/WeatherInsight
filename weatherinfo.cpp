#include "weatherinfo.h"

WeatherInfo::WeatherInfo(QObject *parent)
    : QObject{parent}
{

}

QDateTime WeatherInfo::getTimestamp() const
{
    return timestamp;
}

void WeatherInfo::setTimestamp(const QDateTime &newTimestamp)
{
    timestamp = newTimestamp;
}

int WeatherInfo::getTemperature() const
{
    return temperature;
}

void WeatherInfo::setTemperature(int newTemperature)
{
    temperature = newTemperature;
}

QString WeatherInfo::getIconUrl() const
{
    return iconUrl;
}

void WeatherInfo::setIconUrl(const QString &newIconUrl)
{
    iconUrl = newIconUrl;
}

QString WeatherInfo::getDescription() const
{
    return description;
}

void WeatherInfo::setDescription(const QString &newDescription)
{
    description = newDescription;
}
