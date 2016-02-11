#ifndef BCAAXMLREADER_H
#define BCAAXMLREADER_H

#include <QObject>

class BcaaXmlReader : public QObject
{
    Q_OBJECT
public:
    explicit BcaaXmlReader(QString filePath, QObject *parent = 0);

signals:

public slots:

private:
    QString m_filePath;
};

#endif // BCAAXMLREADER_H
