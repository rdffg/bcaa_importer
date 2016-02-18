#include "logsource.h"

LogSource::LogSource(QObject *parent) : QObject(parent)
  , m_logtext("")
{

}

void LogSource::addLogText(QString text) {
    m_logtext += "\n" + text;
    emit dataChanged();
}

void LogSource::clearLogText() {
    m_logtext = "";
    emit dataChanged();
}

QString LogSource::logtext() {
    return m_logtext;
}


