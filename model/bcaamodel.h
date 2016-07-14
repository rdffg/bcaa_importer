#ifndef BCAAMODEL_H
#define BCAAMODEL_H
#include "QDjangoModel.h"
#include <QEvent>

namespace model
{
class BcaaModel: public QDjangoModel
{
    Q_OBJECT
public:
    explicit BcaaModel(QObject* parent);
public slots:
    bool save();
    bool isDirty() const;

signals:
    void propertyChanged();
private:
    bool m_isDirty;
};
}
#endif // BCAAMODEL_H
