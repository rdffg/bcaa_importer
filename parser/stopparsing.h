#ifndef STOPPARSING_H
#define STOPPARSING_H
#include <exception>

namespace dataadvice
{
/**
 * @brief Indicates that file parsing stopped before the end of the file
 * was reached.
 */
typedef std::exception StopParsing;
}
#endif // STOPPARSING_H
