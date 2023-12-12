#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QObject>
#include <QDateTime>

class WeatherInfo : public QObject
{
    Q_OBJECT
public:
    explicit WeatherInfo(QObject *parent = nullptr);
    QDateTime getTimestamp() const;
    void setTimestamp(const QDateTime &newTimestamp);
    int getTemperature() const;
    void setTemperature(int newTemperature);
    QString getIconUrl() const;
    void setIconUrl(const QString &newIconUrl);
    QString getDescription() const;
    void setDescription(const QString &newDescription);

signals:

private:
    QDateTime timestamp;
    int temperature;
    QString iconUrl;
    QString description;
};

#endif // WEATHERINFO_H
