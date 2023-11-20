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
    int getTemperatureCel() const;
    void setTemperatureCel(int newTemperatureCel);
    QString getIconUrl() const;
    void setIconUrl(const QString &newIconUrl);
    QString getDescription() const;
    void setDescription(const QString &newDescription);

signals:

private:
    QDateTime timestamp;
    int temperatureCel;
    QString iconUrl;
    QString description;
};

#endif // WEATHERINFO_H
