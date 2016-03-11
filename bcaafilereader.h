#ifndef BCAAFILEREADER_H
#define BCAAFILEREADER_H
#include <QtCore>
#include <memory>
#include "DataAdvice.hxx"

class BCAAFileReader
{
public:
    static std::unique_ptr<dataadvice::DataAdvice> openFile(const QString &path);
};

#endif // BCAAFILEREADER_H
