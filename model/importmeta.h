#ifndef IMPORTMETA_H
#define IMPORTMETA_H

#include <QDate>
#include "QDjangoModel.h"
#include "DataAdvice.hxx"

namespace model {
class ImportMeta : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QDate importDate READ importDate WRITE setImportDate)
    Q_PROPERTY(QDate runDate READ runDate WRITE setRunDate)
    Q_PROPERTY(QString runType READ runType WRITE setRunType)

    Q_CLASSINFO("__meta__", "db_table=import_meta")
    Q_CLASSINFO("importDate", "null=true")
    Q_CLASSINFO("runDate", "null=true")
    Q_CLASSINFO("runType", "null=true")

public:
    ImportMeta(QObject *parent=0);
    QDate importDate() const;
    void setImportDate(const QDate &importDate);

    QDate runDate() const;
    void setRunDate(const QDate &runDate);

    QString runType() const;
    void setRunType(const QString &runType);

    static ImportMeta *fromXml(dataadvice::DataAdvice const &da);

private:
    QDate m_importDate;
    QDate m_runDate;
    QString m_runType;
};
}
#endif // IMPORTMETA_H
