#ifndef PARSER_H
#define PARSER_H
#include "DataAdvice-pimpl.h"
#include "DataAdvice-pskel.h"
#include <QObject>
#include "ixmlfilereader.h"
#include "model/deliverysummary.h"

class Parser: public QObject //, public IXmlFileReader
{
    Q_OBJECT
public:
    explicit Parser(QString filePath, QObject *parent=0);
    std::unique_ptr<model::DataAdvice> readFile(const std::string& path, const std::string& xsdPath, bool forSummary=false);
    std::unique_ptr<model::DataAdvice> getFileInfo();
    void cancel();
    ~Parser();

public slots:
    void import ();

signals:
    void message(QString msg);
    //void finished();
    void finished(bool success);
    void folioSaved(float percent);
    void fileInfo(model::DataAdvice*);

private:
    void writeMetadata(const std::unique_ptr<model::DataAdvice> &summary);
    QString filePath;
    std::string findXsdPath();
    std::unique_ptr<bool> m_cancel;
};

#endif // PARSER_H
