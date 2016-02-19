#ifndef ASSESSMENTAREA_H
#define ASSESSMENTAREA_H
#include "QDjangoModel.h"


class AssessmentArea : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(QString assessmentAreaCode READ assessmentAreaCode WRITE setAssessmentAreaCode)
    Q_PROPERTY(QString assessmentAreaDescription READ assessmentAreaDescription WRITE setAssessmentAreaDescription)
    Q_CLASSINFO("assessmentAreaCode", "max_length=16 primary_key=true")
    Q_CLASSINFO("assessmentAreaDescription", "max_length=255 blank=true null=true")

public:
    explicit AssessmentArea(QObject *parent = 0);
    QString assessmentAreaCode();
    void setAssessmentAreaCode(QString area);
    QString assessmentAreaDescription();
    void setAssessmentAreaDescription(QString descr);

signals:

public slots:
private:
    QString m_assessmentAreaCode;
    QString m_assessmentAreaDescription;
};

#endif // ASSESSMENTAREA_H
