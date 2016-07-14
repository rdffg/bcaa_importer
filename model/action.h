#ifndef ACTION_H
#define ACTION_H

#include <QtCore>
#include <sstream>

namespace model
{
class ActionCode: QObject
{
    Q_OBJECT
public:
enum Code
{
    Add,
    Change,
    Delete
};
Q_ENUM(Code)
static Code fromString(const QString& action);
};
}

inline model::ActionCode::Code model::ActionCode::fromString(const QString& action)
{
    const QMetaObject& mo = ActionCode::staticQtMetaObject;
    QMetaEnum me = mo.enumerator(0);
    bool *ok = 0;
    Code actionCode = static_cast<Code>(me.keyToValue(action.toStdString().c_str(), ok));
    if (ok)
        return actionCode;
    else
    {
        std::ostringstream msg;
        msg << "Could not parse " << action.toStdString() << " as an Action Code";
        throw std::invalid_argument(msg.str());
    }
}

#endif // ACTION_H
