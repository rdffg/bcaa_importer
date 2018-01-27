#ifndef PARSER_H
#define PARSER_H
#include "DataAdvice-pimpl.h"
#include "DataAdvice-pskel.h"
#include <QObject>
#include "model/deliverysummary.h"

/**
 * @brief The Parser class
 *
 * This class is reponsible for reading an XML data file, translating it into
 * model objects, and saving those objects to the database. The default QSql database
 * connection must already be open.
 */
class Parser: public QObject //, public IXmlFileReader
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param The filesystem path to the file to be imported
     * @param parent
     */
    explicit Parser(QString filePath, QObject *parent=0);
    /**
     * @brief getFileInfo
     * @return
     */
    std::unique_ptr<model::DataAdvice> getFileInfo();

    ~Parser();

public slots:
    /**
     * @brief Import the current file into the database
     */
    void import (); /**
     * @brief cancel
     *
     * Stop processing the input file. The cancel() method cannot be called from the
     * same thread that is executing import(), as it will block until import() is
     * finished.
     */
    void cancel();

signals:
    /**
     * @brief A informational message
     * @param msg
     */
    void message(QString msg);
    /**
     * @brief The job finished
     * @param success
     */
    void finished(bool success);
    /**
     * @brief A complete folio record was committed to the database
     * @param percent
     */
    void folioSaved(float percent);

private:
    std::unique_ptr<model::DataAdvice> readFile(const std::string& path, const std::string& xsdPath, bool forSummary=false);
    void writeMetadata(const std::unique_ptr<model::DataAdvice> &summary);
    QString filePath;
    std::string findXsdPath();
    std::unique_ptr<bool> m_cancel;
};

#endif // PARSER_H
