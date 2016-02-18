#ifndef LOGSOURCE_H
#define LOGSOURCE_H

#include <QObject>

class LogSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString logtext READ logtext NOTIFY dataChanged)

public:
    explicit LogSource(QObject *parent = 0);
    QString logtext();

signals:
    void dataChanged();

public slots:
    void addLogText(QString text);
    void clearLogText();

private:
    QString m_logtext;
};

#endif // LOGSOURCE_H
