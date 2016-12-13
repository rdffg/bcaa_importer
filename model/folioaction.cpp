#include "folioaction.h"

namespace model {

FolioAction::ActionType FolioAction::actionType() const
{
    return m_actionType;
}

FolioAction::FolioAction(ActionType type, const FolioRenumber &renumber) :
     m_renumber(std::make_unique<FolioRenumber>())
   , m_actionType(type)
   , m_deleteReasonCode(QString())
   , m_deleteReasonDescr(QString())
{
    *m_renumber = renumber;
}

FolioAction::FolioAction(FolioAction::ActionType type, const FolioRenumber &renumber, const QString &reasonCode, const QString &reasonDescr)
    : m_renumber(std::make_unique<FolioRenumber>())
    , m_actionType(type)
    , m_deleteReasonCode(reasonCode)
    , m_deleteReasonDescr(reasonDescr)
{
   *m_renumber = renumber;
}

FolioAction::FolioAction(ActionType type) :
    m_actionType(type)
  , m_deleteReasonCode(QString())
  , m_deleteReasonDescr(QString())
{
    m_renumber = std::unique_ptr<FolioRenumber>();
}

FolioAction& FolioAction::operator=(const FolioAction& other)
{
    if (&other == this)
        return *this;
    m_actionType = other.m_actionType;
    if (other.m_renumber)
    {
        m_renumber = std::make_unique<model::FolioRenumber>();
        *m_renumber = *other.m_renumber;
    }
    m_deleteReasonCode = other.m_deleteReasonCode;
    m_deleteReasonDescr = other.m_deleteReasonDescr;
    return *this;
}

FolioAction::FolioAction(FolioAction &other)
    : m_renumber(std::make_unique<model::FolioRenumber>())
    , m_actionType(other.m_actionType)
    , m_deleteReasonCode(other.m_deleteReasonCode)
    , m_deleteReasonDescr(other.m_deleteReasonDescr)
{
    *m_renumber = *other.m_renumber;
}

FolioAction::FolioAction()
    : m_renumber(std::unique_ptr<model::FolioRenumber>())
    , m_deleteReasonCode(QString())
    , m_deleteReasonDescr(QString())
{
}

const std::unique_ptr<FolioRenumber>& FolioAction::renumber() const
{
    return m_renumber;
}

QString FolioRenumber::assessmentAreaCode() const
{
    return m_assessmentAreaCode;
}

void FolioRenumber::setAssessmentAreaCode(const QString &assessmentAreaCode)
{
    m_assessmentAreaCode = assessmentAreaCode;
}

QString FolioRenumber::assessmentAreaDescription() const
{
    return m_assessmentAreaDescription;
}

void FolioRenumber::setAssessmentAreaDescription(const QString &assessmentAreaDescription)
{
    m_assessmentAreaDescription = assessmentAreaDescription;
}

QString FolioRenumber::jurisdictionCode() const
{
    return m_jurisdictionCode;
}

void FolioRenumber::setJurisdictionCode(const QString &jurisdictionCode)
{
    m_jurisdictionCode = jurisdictionCode;
}

QString FolioRenumber::jurisdictionDescription() const
{
    return m_jurisdictionDescription;
}

void FolioRenumber::setJurisdictionDescription(const QString &jurisdictionDescription)
{
    m_jurisdictionDescription = jurisdictionDescription;
}

QString FolioRenumber::rollNumber() const
{
    return m_rollNumber;
}

void FolioRenumber::setRollNumber(const QString &rollNumber)
{
    m_rollNumber = rollNumber;
}

} // namespace model
