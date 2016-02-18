#ifndef HEADER_H
#define HEADER_H
#include "QDjangoModel.h"

class Header : public QDjangoModel
{
    Q_OBJECT
    Q_PROPERTY(qint32 headerid READ headerid WRITE setHeaderId)
    Q_PROPERTY(QString assessmentrollno READ assessmentrollno WRITE setAssessmentRollNo)
    Q_PROPERTY(QString jurol READ jurol WRITE setJurol)

public:
    QString assessmentrollno() const;
    void setAssessmentRollNo(QString rollno);
    QString jurol() const;
    void setJurol(QString jurol);
    qint32 headerid() const;
    void setHeaderId(qint32 headerid);

private:
    QString m_assessmentrollno;
    QString m_jurol;
    qint32 m_headerid;
};

#endif // HEADER_H
