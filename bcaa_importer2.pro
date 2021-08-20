# needed to link the QDjango stuff
include(qdjango.pri)

TEMPLATE = app

QT += qml quick widgets sql

CONFIG += qtquickcompiler

VERSION = 2.3.6.0

DEFINES += APP_VERSION=\"\\\"$${VERSION}\\\"\"
DEFINES += SCHEMA_VERSION=\"1.8\"

SOURCES += main.cpp \
    bcaadataimporter.cpp \
    dbconnectionsettings.cpp \
    logsource.cpp \
    model/jurisdiction.cpp \
    model/folio.cpp \
    model/assessmentarea.cpp \
    model/folioaddress.cpp \
    model/ownergroup.cpp \
    model/owner.cpp \
    model/mailingaddress.cpp \
    model/formattedmailingaddress.cpp \
    model/legaldescription.cpp \
    model/foliodescription.cpp \
    model/landmeasurement.cpp \
    model/neighbourhood.cpp \
    model/specialdistrict.cpp \
    model/manualclass.cpp \
    model/minortaxing/minortaxing.cpp \
    model/minortaxing/minortaxingjurisdiction.cpp \
    model/importmeta.cpp \
    model/minortaxing/jurisdictiontype.cpp \
    model/manufacturedhome.cpp \
    model/sale.cpp \
    model/ivaluation.cpp \
    model/valuation.cpp \
    model/propertyclassvalue.cpp \
    model/farm.cpp \
    model/oilandgas.cpp \
    model/landcharacteristic.cpp \
    model/propertyclassvaluetype.cpp \
    model/managedforest.cpp \
    parser/DataAdvice-pimpl.cpp \
    parser/DataAdvice-pskel.cpp \
    parser/parser.cpp \
    model/deliverysummary.cpp \
    model/dataadvice.cpp \
    parser/folioitem.cpp \
    parser/runtypeparser.cpp \
    model/bcaamodel.cpp \
    model/valuesbyetc.cpp \
    preflight.cpp \
    model/folioaction.cpp \
    model/schoolclassconverter.cpp \
    model/ownershipgroupowner.cpp \
    mssqldrivers.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =


#PRECOMPILED_HEADER = global/pch.h

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    bcaadataimporter.h \
    dbconnectionsettings.h \
    logsource.h \
    model/jurisdiction.h \
    model/folio.h \
    model/assessmentarea.h \
    model/folioaddress.h \
    model/ownergroup.h \
    model/owner.h \
    saveerror.h \
    model/mailingaddress.h \
    model/formattedmailingaddress.h \
    model/legaldescription.h \
    model/foliodescription.h \
    model/landmeasurement.h \
    model/neighbourhood.h \
    model/specialdistrict.h \
    model/manualclass.h \
    model/minortaxing/minortaxing.h \
    model/minortaxing/minortaxingjurisdiction.h \
    model/importmeta.h \
    model/minortaxing/jurisdictiontype.h \
    model/manufacturedhome.h \
    model/sale.h \
    model/valuesbyetc.h \
    model/ivaluation.h \
    model/valuation.h \
    model/propertyclassvalue.h \
    model/farm.h \
    model/oilandgas.h \
    model/landcharacteristic.h \
    model/propertyclassvaluetype.h \
    model/model.h \
    model/managedforest.h \
    post_process_interface.h \
    parser/DataAdvice-pimpl.h \
    parser/DataAdvice-pskel.h \
    parser/parser.h \
    model/deliverysummary.h \
    model/dataadvice.h \
    model/action.h \
    parser/exception.h \
    parser/folioitem.h \
    parser/runtypeparser.h \
    model/bcaamodel.h \
    parser/stopparsing.h \
    preflight.h \
    model/folioaction.h \
    model/schoolclassconverter.h \
    model/ownershipgroupowner.h \
    mssqldrivers.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3 -lAdvapi32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c_3d -lAdvapi32
else:unix:!macx: LIBS += -L$$PWD/../libs/CodeSynthesis/lib64/vc-12.0/ -lxerces-c

win32:INCLUDEPATH += $$PWD/../libs/CodeSynthesis/include
win32:DEPENDPATH += $$PWD/../libs/CodeSynthesis/include

DISTFILES += \
    DataAdvice.xsd \
    qdjango.pri \
    DataAdvice.map \
    readme.md

#mytarget.target = DataAdvice.hxx
#mytarget.commands = xsd cxx-tree --namespace-map http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd=dataadvice --std c++11 --output-dir $$PWD $$PWD/DataAdvice.xsd
#mytarget.depends = DataAdvice.xsd

# command to generate parser files...
# xsd  cxx-parser  --namespace-map http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd=dataadvice --std c++11 --force-overwrite --type-map ..\DataAdvice.map --generate-test-driver --impl-type-suffix Impl --hxx-suffix .h --ixx-suffix .i --cxx-suffix .cpp  --hxx-prologue "#pragma warning(disable: 4239)" ..\DataAdvice.xsd

schema.target = DataAdvice.xsd

QMAKE_EXTRA_TARGETS += mytarget schema

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/qdjango/lib/ -lqdjango-db0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/qdjango/lib/ -lqdjango-dbd0
##else:unix: LIBS += -L/usr/local/lib -lqdjango-db
else:unix: LIBS += -L/home/dmahoney/src/qdjango/src/db -lqdjango-db

##unix: INCLUDEPATH += /usr/local/include/qdjango/db
unix: INCLUDEPATH += /home/dmahoney/src/qdjango/src/db
win32:INCLUDEPATH += $$PWD/../libs/qdjango/include
win32:DEPENDPATH += $$PWD/../libs/qdjango/include

EXTRA_BINFILES += $$PWD/DataAdvice.xsd
#QMAKE_POST_LINK += xcopy $$EXTRA_BINFILES $$OUT_DIR
CONFIG(debug, debug|release): QMAKE_POST_LINK += $$quote(copy /Y $$shell_path($$PWD/DataAdvice.xsd) $$shell_path($$OUT_PWD)\debug\\$$escape_expand(\\n))
CONFIG(release, debug|release): QMAKE_POST_LINK += $$quote(copy /Y $$shell_path($$PWD/DataAdvice.xsd) $$shell_path($$OUT_PWD)\release\\$$escape_expand(\\n))

# icon
RC_ICONS = bcaa_importer2.ico
