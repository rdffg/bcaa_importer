TEMPLATE = app

QT += qml quick widgets sql xml

CONFIG += qtquickcompiler

SOURCES += main.cpp \
    bcaadataimporter.cpp \
    dbconnectionsettings.cpp \
    logsource.cpp \
    bcaaxmlreader.cpp \
    DataAdvice.cxx

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
    DataAdvice.hxx

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3d
else:unix:!macx: LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3

INCLUDEPATH += $$PWD/../libs/CodeSynthesis/include
DEPENDPATH += $$PWD/../libs/CodeSynthesis/include

DISTFILES += \
    DataAdvice.xsd

mytarget.target = DataAdvice.hxx
mytarget.commands = xsd cxx-tree --namespace-map http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd=dataadvice --std c++11 --output-dir $$PWD $$PWD/DataAdvice.xsd
mytarget.depends = DataAdvice.xsd

schema.target = DataAdvice.xsd

QMAKE_EXTRA_TARGETS += mytarget schema
