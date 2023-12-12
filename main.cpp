#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "modelcontroller.h"
#include "weatherinfo.h"

int main(int argc, char *argv[])
{
    // Prepare startup
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icon.ico"));

    QQmlApplicationEngine engine;

    WeatherInfo weatherInfo;
    ModelController modelController;

    engine.rootContext()->setContextProperty("weatherInfo", &weatherInfo);
    engine.rootContext()->setContextProperty("modelController", &modelController);

    const QUrl url(u"qrc:Main/main.qml"_qs);
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    // Test weather API
    ModelController modelcontroller;
    modelcontroller.getWeatherData("Kongsberg");

    // Start application

    return app.exec();
}
