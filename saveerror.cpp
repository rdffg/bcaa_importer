#include "saveerror.h"

SaveError::SaveError(const QString message): m_message(message)
{
}

QString SaveError::text() const
{
    return m_message;
}
