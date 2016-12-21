#ifndef PREFLIGHT_H
#define PREFLIGHT_H
#include <QString>

/**
 * @brief The PreFlight class
 *
 * The PreFlight class is responsible for preparing the database for the import job
 */
class PreFlight
{
public:
    /**
     * @brief prepareDatabase
     * @param runType
     */
    static void prepareDatabase(const QString &runType);
};

#endif // PREFLIGHT_H
