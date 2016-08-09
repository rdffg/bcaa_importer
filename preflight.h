#ifndef PREFLIGHT_H
#define PREFLIGHT_H
#include <QString>

class PreFlight
{
public:
    static void prepareDatabase(const QString &runType);
};

#endif // PREFLIGHT_H
