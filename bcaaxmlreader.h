#ifndef BCAAXMLREADER_H
#define BCAAXMLREADER_H

#include <memory>
#include <QObject>
#include "DataAdvice.hxx"
#include "model/folio.h"
#include "model/minortaxing/electoralarea.h"
#include "model/minortaxing/servicearea.h"
#include "model/minortaxing/defined.h"
#include "model/minortaxing/minortaxingjurisdiction.h"

class BcaaXmlReader : public QObject
{
    Q_OBJECT
public:
    explicit BcaaXmlReader(QString filePath, QObject *parent = 0);
    //TODO: add a lock or something for this. This is a sentinel
    // value to determine if the job should be terminated.
    bool continueJob;

signals:
    void message(QString msg);
    void finished();
    void folioSaved();

public slots:
    void import();

private:
    void processAssessmentArea(const dataadvice::AssessmentArea &area);
    std::unique_ptr<model::Folio> processFolio(const dataadvice::FolioRecord &folio, model::Jurisdiction *juris_model);
    void processMinorTaxing(const dataadvice::FolioRecord &folio, model::Folio *foliomodel);
    void processOwnership(const dataadvice::FolioRecord &folio, model::Folio *foliomodel);
    void processMetaData(const dataadvice::DataAdvice &dataadvice);
    QString m_filePath;
};

#endif // BCAAXMLREADER_H
