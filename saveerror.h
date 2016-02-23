#ifndef SAVEERROR_H
#define SAVEERROR_H
#include <QtCore>

class SaveError
{
public:
    SaveError(const QString message);
    QString text() const;
private:
    QString m_message;
};

#endif // SAVEERROR_H
