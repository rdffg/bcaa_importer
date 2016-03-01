#ifndef JURISDICTION_H
#define JURISDICTION_H

#include <QObject>
#include <memory>
#include "QDjangoModel.h"
#include "assessmentarea.h"

#define ASSESSMENT_AREA_PROPERTY "assessmentArea"
namespace model {
    class Jurisdiction : public QDjangoModel
    {
        Q_OBJECT
        Q_PROPERTY(QString code READ code WRITE setCode)
        Q_PROPERTY(QString description READ description WRITE setDescription)
        Q_PROPERTY(model::AssessmentArea *assessmentArea READ assessmentArea WRITE setAssessmentArea)

        Q_CLASSINFO("__meta__", "db_table=jurisdiction")
        Q_CLASSINFO("code", "max_length=16 primary_key=true")
        Q_CLASSINFO("description", "max_length=255 null=true blank=true")
    public:
        explicit Jurisdiction(QObject *parent=0);
        QString code();
        void setCode(QString code);
        QString description();
        void setDescription(QString desc);
        AssessmentArea *assessmentArea();
        void setAssessmentArea(AssessmentArea *area);
        void setAssessmentArea(std::shared_ptr<AssessmentArea> area);
        static Jurisdiction* fromXml(dataadvice::Jurisdiction const &jurisdiction);

    signals:

    public slots:

    private:
        QString m_code;
        QString m_description;
    };
}
#endif // JURISDICTION_H
