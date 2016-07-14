#ifndef IXMLFILEREADER_H
#define IXMLFILEREADER_H
#include <QTCore>

class IXmlFileReader
{
public:
    bool continueJob;
    virtual void import() = 0;
    virtual ~IXmlFileReader() = 0;
signals:
    virtual void message(QString msg) = 0;
    virtual void finished() = 0;
    virtual void folioSaved() = 0;
protected:
    IXmlFileReader() {}
};

//IXmlFileReader::~IXmlFileReader() {}

#endif // IXMLFILEREADER_H
