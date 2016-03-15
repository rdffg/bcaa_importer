#include "folio.h"

using namespace model;

Folio::Folio(QObject *parent): QDjangoModel(parent) {

}

QString Folio::rollNumber() {
    return m_rollNumber;
}

void Folio::setRollNumber(QString num) {
    m_rollNumber = num;
}

QString Folio::status() {
    return m_status;
}

void Folio::setStatus(QString status) {
    m_status = status;
}

QString Folio::statusDescription() {
    return m_statusDescription;
}

void Folio::setStatusDescription(QString desc) {
    m_statusDescription = desc;
}

Jurisdiction *Folio::jurisdiction() const {
    return qobject_cast<Jurisdiction *>(foreignKey("jurisdiction"));
}

void Folio::setJurisdiction(Jurisdiction *juris) {
    setForeignKey(JURISDICTION_PROPERTY, juris);
}

model::Folio *Folio::fromXml(const dataadvice::FolioRecord &folio)
{
    auto foliomodel = new model::Folio();
    foliomodel->setRollNumber(QString::fromStdString(folio.RollNumber()));
    if (folio.FolioStatus().present())
        foliomodel->setStatus(
                    QString::fromStdString(folio.FolioStatus().get()));
    if (folio.FolioStatusDescription().present())
        foliomodel->setStatusDescription(
                    QString::fromStdString(folio.FolioStatusDescription().get()));

    return foliomodel;
}

