#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

namespace parser
{
    /**
     * @brief ParseError
     *
     * XML parsing failed.
     */
    typedef std::exception ParseError;
}
#endif // EXCEPTION_H
