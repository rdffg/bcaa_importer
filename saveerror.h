#ifndef SAVEERROR_H
#define SAVEERROR_H
#include <QtCore>

/**
 * @brief The SaveError class
 *
 * This error is thrown when a model could not be saved to the database.
 */
class SaveError
{
public:
    SaveError(const QString message);
    QString text() const;
private:
    QString m_message;
};

#endif // SAVEERROR_H
