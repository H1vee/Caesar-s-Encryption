#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/ApplicationController.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    
    QQmlApplicationEngine engine;

    ApplicationController affineCipher;
    engine.rootContext()->setContextProperty("affineCipher", &affineCipher);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    
    return app.exec();
}