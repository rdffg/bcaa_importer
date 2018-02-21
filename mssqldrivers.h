#ifndef MSSQLDRIVERS_H
#define MSSQLDRIVERS_H
#include <vector>
#include <Qt>

class MssqlDrivers
{
public:
    QString GetBestMssqlDriver();
private:
    std::vector<std::wstring> GetMssqlDrivers();
};

#endif // MSSQLDRIVERS_H
