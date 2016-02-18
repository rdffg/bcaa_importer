#ifndef JURISDICTION_H
#define JURISDICTION_H

#include <QObject>
#include "QDjangoModel.h"

    class Jurisdiction : public QDjangoModel
    {
        Q_OBJECT
        Q_PROPERTY(QString code READ code WRITE setCode)
        Q_PROPERTY(QString description READ description WRITE setDescription)

        Q_CLASSINFO("__meta__", "db_table=jurisdiction")
        Q_CLASSINFO("code", "max_length=16 primary_key=true")
        Q_CLASSINFO("description", "max_length=255 null=true blank=true")
    public:
        explicit Jurisdiction(QObject *parent=0);
        QString code();
        void setCode(QString code);
        QString description();
        void setDescription(QString desc);

    signals:

    public slots:

    private:
        QString m_code;
        QString m_description;
    };

#endif // JURISDICTION_H
