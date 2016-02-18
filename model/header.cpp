#include "model/header.h"

qint32 Header::headerid() const {
    return m_headerid;
}

QString Header::assessmentrollno() const {
    return m_assessmentrollno;
}

QString Header::jurol() const {
    return m_jurol;
}

void Header::setJurol(QString jurol) {
    m_jurol = jurol;
}

void Header::setAssessmentRollNo(QString rollno) {
    m_assessmentrollno = rollno;
}

void Header::setHeaderId(qint32 headerid) {
    m_headerid = headerid;
}
