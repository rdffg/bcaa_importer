#include "modelConverter/folioconverter.h"
#include "model/jurisdiction.h"

using namespace converter;

model::Folio *converter::FolioConverter::convert(const dataadvice::FolioRecord &folio)
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
