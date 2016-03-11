#include "importmeta.h"

using namespace model;

ImportMeta::ImportMeta(QObject  *parent) : QDjangoModel(parent)
  , m_importDate(QDate())
  , m_runDate(QDate())
  , m_runType("")
{

}

QDate ImportMeta::importDate() const
{
    return m_importDate;
}

void ImportMeta::setImportDate(const QDate &importDate)
{
    m_importDate = importDate;
}

QDate ImportMeta::runDate() const
{
    return m_runDate;
}

void ImportMeta::setRunDate(const QDate &runDate)
{
    m_runDate = runDate;
}

QString ImportMeta::runType() const
{
    return m_runType;
}

void ImportMeta::setRunType(const QString &runType)
{
    m_runType = runType;
}

ImportMeta *ImportMeta::fromXml(const dataadvice::DataAdvice &da)
{
    auto meta = new ImportMeta();
    meta->setImportDate(QDate::currentDate());
    meta->setRunDate(QDate(da.RunDate().year(), da.RunDate().month(), da.RunDate().day()));
    meta->setRunType(QString::fromStdString(da.RunType()));
    return meta;
}
