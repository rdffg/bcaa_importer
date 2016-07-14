#include "bcaamodel.h"

namespace model {
    BcaaModel::BcaaModel(QObject *parent) :
        QDjangoModel(parent)
      , m_isDirty(true)
    {
        connect(this, &BcaaModel::propertyChanged, [=]() { m_isDirty = true; });
    }

    bool BcaaModel::save()
    {
        if (m_isDirty) return QDjangoModel::save();
        else return true;
    }

    bool BcaaModel::isDirty() const
    {
        return m_isDirty;
    }
}
