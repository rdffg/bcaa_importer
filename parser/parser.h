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

public slots:
    void import ();

signals:
    void message(QString msg);
    void finished();
    void folioSaved();
    void fileInfo(model::DataAdvice*);

private:
    static std::unique_ptr<::dataadvice::DataAdviceImpl> registerParser(bool forSummary);
    QString filePath;
    std::string findXsdPath();
    bool* m_cancel;
};

#endif // PARSER_H
