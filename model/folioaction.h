#ifndef MODEL_FOLIOACTION_H
#define MODEL_FOLIOACTION_H
#include <QtCore>
#include <memory>

namespace model {

class FolioRenumber
{
public:
    QString assessmentAreaCode() const;
    void setAssessmentAreaCode(const QString &assessmentAreaCode);

    QString assessmentAreaDescription() const;
    void setAssessmentAreaDescription(const QString &assessmentAreaDescription);

    QString jurisdictionCode() const;
    void setJurisdictionCode(const QString &jurisdictionCode);

    QString jurisdictionDescription() const;
    void setJurisdictionDescription(const QString &jurisdictionDescription);

    QString rollNumber() const;
    void setRollNumber(const QString &rollNumber);

private:
    QString m_assessmentAreaCode;
    QString m_assessmentAreaDescription;
    QString m_jurisdictionCode;
    QString m_jurisdictionDescription;
    QString m_rollNumber;
};

class FolioAction
{
public:
    enum ActionType
    {
        ADD,
        DELETE
    };

    ActionType actionType() const;
    FolioAction(const ActionType &type, const FolioRenumber &renumber);
    FolioAction(const ActionType &type, const QString &reasonCode, const QString &reasonDescr);
    FolioAction (const ActionType &type, const FolioRenumber&, const QString &reasonCode,const QString &reasonDescr);
    FolioAction(const ActionType &type);
    FolioAction();
    QString deleteReasonCode() const;
    QString deleteReasonDescription() const;
    const std::unique_ptr<FolioRenumber> &renumber() const;
    FolioAction& operator=(const FolioAction& other);
    FolioAction(FolioAction &other);

private:
    std::unique_ptr<FolioRenumber> m_renumber;
    ActionType m_actionType;
    QString m_deleteReasonCode;
    QString m_deleteReasonDescr;
};

} // namespace model

#endif // MODEL_FOLIOACTION_H
