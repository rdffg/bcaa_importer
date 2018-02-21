#include "mssqldrivers.h"
#include <Windows.h>
#ifdef WIN32
#include <regex>
#include <string>
#include <QString>

QString MssqlDrivers::GetBestMssqlDriver()
{
    std::wstring driver;
    int odbc_version = 0;
    float snac_version = 0.0;
    std::vector<std::wstring> drivers;

    try
    {
        drivers = GetMssqlDrivers();
    }
    catch (const std::string &e)
    {
        return QString();
    }

    for (auto &d : drivers)
    {
        // prefer new ODBC drivers
        std::wregex re(L".*ODBC Driver (\\d+).*");
        std::wsmatch match;
        if (std::regex_match(d, match, re))
        {
            if (match.size() > 1)
            {
                auto new_version = stoi(match[1]);
                if (driver.empty() || odbc_version < new_version)
                {
                    driver = d;
                    odbc_version = new_version;
                }
            }
        }
        // then snac driver
        re = std::wregex(L"SQL Server Native Client ([\\d\\.]+).*");
        if (std::regex_match(d, match, re))
        {
            if (match.size() > 1)
            {
                auto new_version = stof(match[1]);
                if (driver.empty() || (odbc_version == 0 && snac_version < new_version))
                {
                    snac_version = new_version;
                    driver = d;
                }
            }
        }

        // then the ancient Sql Server driver
        if (driver.empty())
        {
            driver = d;
        }
    }
    return QString::fromStdWString(driver);
}

std::vector<std::wstring> MssqlDrivers::GetMssqlDrivers()
{
    LPWSTR value = static_cast<LPWSTR>(calloc(1048576, sizeof(char)));
    LPBYTE data = static_cast<LPBYTE>(calloc(64, sizeof(char)));
    DWORD valueChars = 1048576 * sizeof(char) / sizeof(WCHAR);
    DWORD dataChars = 64;
    LPDWORD pDataChars = &dataChars;
    LPDWORD pValueChars = &valueChars;
    DWORD index = 0;

    std::vector<std::wstring> drivers;

    HKEY hKey;
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\ODBC\\ODBCINST.INI\\ODBC Drivers"), 0, KEY_READ, &hKey);
    if (lResult != ERROR_SUCCESS)
    {
        throw std::string("failed to open key");
    }
    while (lResult == ERROR_SUCCESS)
    {
        lResult = RegEnumValue(hKey, index, value, pValueChars, NULL, NULL, data, pDataChars);
        valueChars = 1048576 * sizeof(char) / sizeof(WCHAR);
        auto driver = std::wstring(value);
        auto sql = std::string("SQL Server");
        if (driver.find(L"SQL Server") != std::string::npos)
            drivers.push_back(std::wstring(value));
        index++;
    }
    if (lResult == ERROR_NO_MORE_ITEMS)
        return drivers;
    else if (lResult == ERROR_MORE_DATA)
    {
        throw std::string("need to get more data");
    }
    else
    {
        throw std::string("failed to get value");
    }
}
#else
std::vector<std::wstring> MssqlDrivers::GetMssqlDrivers()
{
    return vector<wstring>();
}

std::wstring MssqlDrivers::GetBestMssqlDriver()
{
    return std::wstring();
}

#endif
