#ifndef RUNTYPEPARSER_H
#define RUNTYPEPARSER_H

#include "DataAdvice-pskel.h"
#include "stopparsing.h"
#include <QObject>

namespace dataadvice
{
/**
 * @brief The RunTypeParser class
 *
 * This implementation of the dataadvice::DataAdvice_pskel class begins
 * to read a data file, but aborts after reading the metadata at the top.
 */
class RunTypeParser : public QObject, public dataadvice::DataAdvice_pskel
{
    // DataAdvice_pskel interface
    Q_OBJECT
public:
    RunTypeParser();
    void pre() override;
    void RollYear(long long) override;
    void OwnershipYear(long long) override;
    void RunType(const QString &) override;
    void StartDate(const xml_schema::date &) override;
    void EndDate(const xml_schema::date &) override;
    void Version(const QString &) override;
    void RequestID(const QString &) override;
    void OrderID(const QString &) override;
    void RunDate(const xml_schema::date &) override;
    std::unique_ptr<model::DataAdvice> post_DataAdvice() override;
signals:
    void message(QString msg);

private:
    std::unique_ptr<model::DataAdvice> m_dataAdvice;
};
}
#endif // RUNTYPEPARSER_H
