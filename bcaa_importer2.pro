# needed to link the QDjango stuff
include(qdjango.pri)

TEMPLATE = app

QT += qml quick widgets sql xml

CONFIG += qtquickcompiler c++11

SOURCES += main.cpp \
    bcaadataimporter.cpp \
    dbconnectionsettings.cpp \
    logsource.cpp \
    bcaaxmlreader.cpp \
    DataAdvice.cxx \
    model/jurisdiction.cpp \
    model/folio.cpp \
    modelConverter/folioconverter.cpp \
    modelConverter/jurisdictionconverter.cpp \
    model/assessmentarea.cpp \
    model/folioaddress.cpp \
    modelConverter/folioaddressconverter.cpp \
    modelConverter/assessmentareaconverter.cpp \
    model/ownergroup.cpp \
    model/owner.cpp \
    modelConverter/ownershipgroupconverter.cpp \
    modelConverter/ownerconverter.cpp \
    saveerror.cpp \
    model/mailingaddress.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    bcaadataimporter.h \
    dbconnectionsettings.h \
    logsource.h \
    bcaaxmlreader.h \
    DataAdvice.hxx \
    model/jurisdiction.h \
    model/folio.h \
    modelConverter/folioconverter.h \
    modelConverter/jurisdictionconverter.h \
    model/assessmentarea.h \
    model/folioaddress.h \
    modelConverter/folioaddressconverter.h \
    modelConverter/assessmentareaconverter.h \
    model/ownergroup.h \
    model/owner.h \
    modelConverter/ownershipgroupconverter.h \
    modelConverter/ownerconverter.h \
    saveerror.h \
    model/mailingaddress.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3d
else:unix:!macx: LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c

win32:INCLUDEPATH += $$PWD/../libs/CodeSynthesis/include
win32:DEPENDPATH += $$PWD/../libs/CodeSynthesis/include

DISTFILES += \
    DataAdvice.xsd \
    qdjango.pri

mytarget.target = DataAdvice.hxx
mytarget.commands = xsd cxx-tree --namespace-map http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd=dataadvice --std c++11 --output-dir $$PWD $$PWD/DataAdvice.xsd
mytarget.depends = DataAdvice.xsd

schema.target = DataAdvice.xsd

QMAKE_EXTRA_TARGETS += mytarget schema

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/qdjango/lib/ -lqdjango-db0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/qdjango/lib/ -lqdjango-dbd0
else:unix: LIBS += -L/usr/local/lib -lqdjango-db

unix: INCLUDEPATH += /usr/local/include/qdjango/db
win32:INCLUDEPATH += $$PWD/../libs/qdjango/include
win32:DEPENDPATH += $$PWD/../libs/qdjango/include
