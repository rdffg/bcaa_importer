#ifndef FOLIOCONVERTER_H
#define FOLIOCONVERTER_H

#include "DataAdvice.hxx"
#include "model/folio.h"

namespace converter {
class FolioConverter : public QObject
{
public:
    static model::Folio *convert(const dataadvice::FolioRecord &folio);
};
}
#endif // FOLIOCONVERTER_H
