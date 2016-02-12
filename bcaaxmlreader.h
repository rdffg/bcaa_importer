#ifndef BCAAXMLREADER_H
#define BCAAXMLREADER_H

#include <QObject>

class BcaaXmlReader : public QObject
{
    Q_OBJECT
public:
    explicit BcaaXmlReader(QString filePath, QObject *parent = 0);

signals:
    void message(QString msg);
    void finished();

public slots:
    void import();

private:
    QString m_filePath;
};

#endif // BCAAXMLREADER_H
