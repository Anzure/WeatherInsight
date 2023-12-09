#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <QObject>

class ModelController : public QObject
{
    Q_OBJECT
public:
    explicit ModelController(QObject *parent = nullptr);

signals:

};

#endif // MODELCONTROLLER_H
