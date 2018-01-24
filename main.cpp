#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "logsource.h"
#include "bcaadataimporter.h"
#include "dbconnectionsettings.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath());
    app.setApplicationVersion(QString(APP_VERSION));

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    auto logdata = new LogSource();
    auto importer = new BCAADataImporter();
    auto sqlconnection = new DbConnectionSettings();
    importer->setDbConnection(sqlconnection);
    QObject::connect(importer, &BCAADataImporter::statusChanged, logdata, &LogSource::addLogText);
    context->setContextProperty("logdata", logdata);
    context->setContextProperty("importer", importer);
    context->setContextProperty("sqlconnection", sqlconnection);
    context->setContextProperty("version", APP_VERSION);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
