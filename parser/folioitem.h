#ifndef BOOLEANITEM_H
#define BOOLEANITEM_H

#include <QString>
#include "model/action.h"
#include "model/model.h"

namespace model
{

class FolioItemGroup
{
public:
    FolioItemGroup(ActionCode::Code action);
    virtual ActionCode::Code action() const;
    virtual ~FolioItemGroup();
private:
    ActionCode::Code m_action;
};

template <class T>
class FolioItem: public FolioItemGroup
{
public:
    FolioItem(T value, T oldvalue, ActionCode::Code code);
    T value() const;
    T oldValue() const;
private:
    T m_value;
    T m_oldValue;
};


inline FolioItemGroup::FolioItemGroup(ActionCode::Code action): m_action(action)
{
}

inline FolioItemGroup::~FolioItemGroup() {}

inline ActionCode::Code FolioItemGroup::action() const
{
    return m_action;
}

template <class T>
inline FolioItem<T>::FolioItem(T value, T oldvalue, ActionCode::Code code) :
        FolioItemGroup(code)
      , m_value(value)
      , m_oldValue(oldvalue)
{
}

template <class T>
inline T FolioItem<T>::oldValue() const
{
    return m_oldValue;
}

template <class T>
inline T FolioItem<T>::value() const
{
    return m_value;
}

typedef FolioItem<bool> BooleanItem;
typedef FolioItem<double> DecimalItem;
typedef FolioItem<long long> IntegerItem;
typedef FolioItem<QDate> DateItem;

class StringItem: public FolioItem<QString>
{
public:
    StringItem(QString value, QString oldValue, ActionCode::Code);
};

inline StringItem::StringItem(QString value, QString oldValue, ActionCode::Code code) :
    FolioItem(value.trimmed().isEmpty() ? QString(): value, oldValue, code)
    {}

// PropertyValues
typedef std::pair<std::vector<std::unique_ptr<model::ValuesByETC> >,
    std::vector<std::unique_ptr<model::PropertyClassValue> > > PropertyValues;
}
#endif // BOOLEANITEM_H
