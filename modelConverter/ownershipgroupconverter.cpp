#include "ownershipgroupconverter.h"
#include <QDate>

using namespace converter;
OwnershipGroup *OwnershipGroupConverter::convert(const dataadvice::OwnershipGroup &group) {
    auto groupmodel = new OwnershipGroup();
    groupmodel->setAssessmentNoticeReturned(group.AssessmentNoticeReturned());
    groupmodel->setAssessmentNoticeSuppressed(group.AssessmentNoticeSuppressed());
    if (group.ChangeDate().present()) {
        QDate date;
        date.setDate(group.ChangeDate().get().year()
                     , group.ChangeDate().get().month()
                     , group.ChangeDate().get().day());
        groupmodel->setChangeDate(date);
    }
    if (group.ChangeSource().present())
        groupmodel->setChangeSource(QString::fromStdString(group.ChangeSource().get()));
    if (group.ChangeSourceDescription().present())
        groupmodel->setChangeSourceDescription(QString::fromStdString(group.ChangeSourceDescription().get()));
    if (group.ChangeType().present())
        groupmodel->setChangeType(QString::fromStdString(group.ChangeType().get()));
    if (group.ChangeTypeDescription().present())
        groupmodel->setChangeTypeDescription(QString::fromStdString(group.ChangeTypeDescription().get()));
    if (group.TenureCode().present())
        groupmodel->setTenureCode(QString::fromStdString(group.TenureCode().get()));
    if (group.TenureDescription().present())
        groupmodel->setTenureDescription(QString::fromStdString(group.TenureDescription().get()));

    return groupmodel;
}
