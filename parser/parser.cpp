#include <string.h>
#include <fstream>
#include "parser.h"
#include "DataAdvice-pimpl.h"
#include "DataAdvice-pskel.h"
#include "model/dataadvice.h"
#include "runtypeparser.h"
#include <QApplication>
#include <QFileInfo>
#include <QDebug>
#include "QDjango.h"
#include "saveerror.h"

Parser::Parser(QString filePath, QObject *parent):
    QObject(parent)
  , filePath(filePath)
{
    m_cancel = std::make_unique<bool>();
}

Parser::~Parser()
{
}

std::string Parser::findXsdPath()
{
    QString xsdName = "DataAdvice.xsd";
    auto xsdPath = QApplication::applicationDirPath() + "/" + xsdName;
    QFileInfo check_file(xsdPath);
    if (check_file.exists() && check_file.isReadable())
    {
        return xsdPath.toStdString();
    }
    else
    {
        QDir dir = QDir(filePath);
        dir.cdUp();
        xsdPath = dir.canonicalPath() + "/" + xsdName;
        check_file = QFileInfo(xsdPath);
        if (check_file.exists() && check_file.isReadable())
            return xsdPath.toStdString();
        else
            throw QString("DataAdvice.xsd was not found.");
    }
}

void Parser::import()
{
    *m_cancel = false;
    if (!QDjango::createTables())
    {
        this->message(QString("Did not create tables (this is okay if the tables already exist)"));
    }
    try
    {
        if (!QDjango::database().transaction())
            throw SaveError("Failed to create transaction.");
        message("Populating lookup tables...");
        model::PropertyClassValueType::populate();
        model::minortaxing::JurisdictionType::populate();
        message("Done.");
        message(QString("Importing records from ") + filePath + "...");
        std::unique_ptr<model::DataAdvice> dataAdvice;
        try
        {
            dataAdvice = readFile(filePath.toStdString(), findXsdPath(), false);
        }
        catch (SaveError &err)
        {
            QDjango::database().rollback();
            emit message(err.text());
            emit finished(false);
            return;
        }
        catch ( ... )
        {
            QDjango::database().rollback();
            qDebug() << "Stopped parsing the file.";
            emit finished(false);
            return;
        }

        writeMetadata(dataAdvice);
        emit folioSaved(-1); // set progressbar to indeterminate
        if (!QDjango::database().commit())
            throw SaveError("Failed to commit transaction.");
        message("Successfully imported the data file.");
        emit finished(true);
    }
    catch (SaveError &err)
    {
        this->message(err.text());
        emit finished(false);
    }
}

void Parser::writeMetadata(const std::unique_ptr<model::DataAdvice> &summary)
{
    model::ImportMeta meta;
    meta.setImportDate(QDate::currentDate());
    meta.setRunDate(summary->runDate());
    meta.setRunType(summary->runType());
    if (!meta.save())
        throw SaveError(meta.lastError().text());
}

void Parser::cancel()
{
    *m_cancel = true;
}

std::unique_ptr<model::DataAdvice> Parser::getFileInfo()
{
    auto xsdPath = findXsdPath();
    auto advice = readFile(filePath.toStdString(), findXsdPath(), true);
    return advice;
}

std::unique_ptr<model::DataAdvice> Parser::readFile(const std::string& path, const std::string& xsdPath, bool forSummary)
{
    // use a stream so we can calculate progress based on
    // position in the file stream
    std::ifstream file;
    long long size;
    file.open(path, std::ios::in | std::ios::ate); // open input stream at end of file
    if (file.is_open())
    {
        size = file.tellg();
        file.seekg(0, file.beg);
        qDebug() << "size of size_t: " << sizeof(size_t);
    }
    else
    {
        char *errbuf = new char[32];
        strerror_s(errbuf, 32, errno);
        throw(QString("Failed to open file.") + QString(errbuf));
    }
    std::unique_ptr<::dataadvice::DataAdvice_pskel> DataAdvice_p;
    //auto parser = registerParser(forSummary);

    ::xml_schema::integerImpl integer_p;
    ::dataadvice::RunTypeImpl RunType_p;
    ::xml_schema::dateImpl date_p;
    ::dataadvice::AssessmentAreaCollectionImpl AssessmentAreaCollection_p;
    ::dataadvice::AssessmentAreaImpl AssessmentArea_p;
    ::dataadvice::AssessmentAreaCodeImpl AssessmentAreaCode_p;
    ::dataadvice::String255Impl String255_p;
    ::dataadvice::JurisdictionCollectionImpl JurisdictionCollection_p;
    ::dataadvice::JurisdictionImpl Jurisdiction_p;
    ::dataadvice::JurisdictionCodeImpl JurisdictionCode_p;
    ::dataadvice::FolioRecordCollectionImpl FolioRecordCollection_p;
    ::dataadvice::FolioRecordImpl FolioRecord_p(file, size);
    ::dataadvice::FolioRollNumberImpl FolioRollNumber_p;
    ::dataadvice::ActionCodeImpl ActionCode_p;
    ::dataadvice::String32Impl String32_p;
    ::dataadvice::FolioLookupCodeItemImpl FolioLookupCodeItem_p;
    ::dataadvice::LookupCodeImpl LookupCode_p;
    ::dataadvice::FolioString255ItemImpl FolioString255Item_p;
    ::dataadvice::FolioActionImpl FolioAction_p;
    ::dataadvice::FolioAddImpl FolioAdd_p;
    ::dataadvice::FolioRenumberImpl FolioRenumber_p;
    ::dataadvice::FolioDeleteImpl FolioDelete_p;
    ::dataadvice::FolioAddressCollectionImpl FolioAddressCollection_p;
    ::dataadvice::FolioAddressImpl FolioAddress_p;
    ::dataadvice::FolioBooleanItemImpl FolioBooleanItem_p;
    ::xml_schema::booleanImpl boolean_p;
    ::dataadvice::UniqueIDImpl UniqueID_p;
    ::dataadvice::OwnershipGroupCollectionImpl OwnershipGroupCollection_p;
    ::dataadvice::OwnershipGroupImpl OwnershipGroup_p;
    ::dataadvice::FolioUniqueIDItemImpl FolioUniqueIDItem_p;
    ::dataadvice::FolioDateItemImpl FolioDateItem_p;
    ::dataadvice::OwnerCollectionImpl OwnerCollection_p;
    ::dataadvice::OwnerImpl Owner_p;
    ::dataadvice::FolioString1ItemImpl FolioString1Item_p;
    ::dataadvice::String1Impl String1_p;
    ::dataadvice::FormattedMailingAddressImpl FormattedMailingAddress_p;
    ::dataadvice::FormattedMailingAddressLineImpl FormattedMailingAddressLine_p;
    ::dataadvice::String40Impl String40_p;
    ::dataadvice::MailingAddressImpl MailingAddress_p;
    ::dataadvice::LegalDescriptionCollectionImpl LegalDescriptionCollection_p;
    ::dataadvice::LegalDescriptionImpl LegalDescription_p;
    ::dataadvice::FolioString1024ItemImpl FolioString1024Item_p;
    ::dataadvice::String1024Impl String1024_p;
    ::dataadvice::FolioDescriptionImpl FolioDescription_p;
    ::dataadvice::NeighbourhoodImpl Neighbourhood_p;
    ::dataadvice::LandMeasurementImpl LandMeasurement_p;
    ::dataadvice::SpecialDistrictImpl SpecialDistrict_p;
    ::dataadvice::ManualClassImpl ManualClass_p;
    ::dataadvice::FolioDecimalItemImpl FolioDecimalItem_p;
    ::xml_schema::decimalImpl decimal_p;
    ::dataadvice::SaleCollectionImpl SaleCollection_p;
    ::dataadvice::SaleImpl Sale_p;
    ::dataadvice::PropertyValuesImpl PropertyValues_p;
    ::dataadvice::PropertyClassValuesCollectionImpl PropertyClassValuesCollection_p;
    ::dataadvice::PropertyClassValuesCollectionImpl PropertyClassValuesSummaryCollection_p;
    ::dataadvice::PropertyClassValuesImpl PropertyClassValues_p;
    ::dataadvice::PropertyClassCodeImpl PropertyClassCode_p;
    ::dataadvice::PropertySubClassCodeImpl PropertySubClassCode_p;
    ::dataadvice::ValuationImpl Valuation_p;
    ::dataadvice::ValuationCollectionImpl ValuationCollection_p;
    ::dataadvice::ValuesByETCImpl ValuesByETC_p;
    ::dataadvice::FolioAmendmentCollectionImpl FolioAmendmentCollection_p;
    ::dataadvice::FolioAmendmentImpl FolioAmendment_p;
    ::dataadvice::MinorTaxingImpl MinorTaxing_p;
    ::dataadvice::MinorTaxingJurisdictionCollectionImpl MinorTaxingJurisdictionCollection_p;
    ::dataadvice::MinorTaxingJurisdictionImpl MinorTaxingJurisdiction_p;
    ::dataadvice::FarmCollectionImpl FarmCollection_p;
    ::dataadvice::FarmImpl Farm_p;
    ::dataadvice::ManufacturedHomeCollectionImpl ManufacturedHomeCollection_p;
    ::dataadvice::ManufacturedHomeImpl ManufacturedHome_p;
    ::dataadvice::ManagedForestCollectionImpl ManagedForestCollection_p;
    ::dataadvice::ManagedForestImpl ManagedForest_p;
    ::dataadvice::OilAndGasCollectionImpl OilAndGasCollection_p;
    ::dataadvice::OilAndGasImpl OilAndGas_p;
    ::dataadvice::LandCharacteristicCollectionImpl LandCharacteristicCollection_p;
    ::dataadvice::LandCharacteristicImpl LandCharacteristic_p;
    ::dataadvice::DeliverySummaryImpl DeliverySummary_p;
    ::dataadvice::FolioGroupValuesImpl FolioGroupValues_p;
    ::dataadvice::AmendmentReasonCountCollectionImpl AmendmentReasonCountCollection_p;
    ::dataadvice::AmendmentReasonCountImpl AmendmentReasonCount_p;
    ::dataadvice::DeleteReasonCountCollectionImpl DeleteReasonCountCollection_p;
    ::dataadvice::DeleteReasonCountImpl DeleteReasonCount_p;
    ::dataadvice::VersionImpl Version_p;


    // set the cancel flag
    FolioRecord_p.setCancelFlag(*m_cancel);

    // Connect the parsers together.
    //
    if (forSummary)
    {
        DataAdvice_p = std::make_unique<dataadvice::RunTypeParser>();
        DataAdvice_p->RunType_parser(RunType_p);
        DataAdvice_p->EndDate_parser(date_p);
        DataAdvice_p->Version_parser(Version_p);
        DataAdvice_p->StartDate_parser(date_p);
        DataAdvice_p->RunDate_parser(date_p);
        //DataAdvice_p->ReportSummary_parser(DeliverySummary_p);
    }
    else
    {
        DataAdvice_p = std::make_unique<::dataadvice::DataAdviceImpl>();
        DataAdvice_p->parsers (integer_p,
                               integer_p,
                               RunType_p,
                               date_p,
                               date_p,
                               AssessmentAreaCollection_p,
                               DeliverySummary_p,
                               Version_p,
                               UniqueID_p,
                               UniqueID_p,
                               date_p);


        AssessmentAreaCollection_p.parsers (AssessmentArea_p);

        AssessmentArea_p.parsers (AssessmentAreaCode_p,
                                  String255_p,
                                  JurisdictionCollection_p,
                                  DeliverySummary_p);

        JurisdictionCollection_p.parsers (Jurisdiction_p);

        Jurisdiction_p.parsers (JurisdictionCode_p,
                                String255_p,
                                FolioRecordCollection_p,
                                DeliverySummary_p);

        FolioRecordCollection_p.parsers (FolioRecord_p);

        FolioRecord_p.parsers (FolioRollNumber_p,
                               FolioLookupCodeItem_p,
                               FolioString255Item_p,
                               FolioAction_p,
                               FolioAddressCollection_p,
                               OwnershipGroupCollection_p,
                               LegalDescriptionCollection_p,
                               FolioDescription_p,
                               SaleCollection_p,
                               PropertyValues_p,
                               FolioAmendmentCollection_p,
                               MinorTaxing_p,
                               FarmCollection_p,
                               ManufacturedHomeCollection_p,
                               ManagedForestCollection_p,
                               OilAndGasCollection_p,
                               LandCharacteristicCollection_p,
                               UniqueID_p);

        FolioRollNumber_p.parsers (ActionCode_p,
                                   String32_p);

        FolioLookupCodeItem_p.parsers (ActionCode_p,
                                       LookupCode_p);

        FolioString255Item_p.parsers (ActionCode_p,
                                      String255_p);

        FolioAction_p.parsers (FolioAdd_p,
                               FolioDelete_p);

        FolioAdd_p.parsers (FolioRenumber_p);

        FolioRenumber_p.parsers (AssessmentAreaCode_p,
                                 String255_p,
                                 JurisdictionCode_p,
                                 String255_p,
                                 String32_p);

        FolioDelete_p.parsers (FolioRenumber_p,
                               LookupCode_p,
                               String255_p);

        FolioAddressCollection_p.parsers (ActionCode_p,
                                          FolioAddress_p);

        FolioAddress_p.parsers (ActionCode_p,
                                FolioBooleanItem_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                FolioString255Item_p,
                                UniqueID_p);

        FolioBooleanItem_p.parsers (ActionCode_p,
                                    boolean_p);

        OwnershipGroupCollection_p.parsers (ActionCode_p,
                                            OwnershipGroup_p);

        OwnershipGroup_p.parsers (ActionCode_p,
                                  FolioUniqueIDItem_p,
                                  FolioBooleanItem_p,
                                  FolioBooleanItem_p,
                                  FolioLookupCodeItem_p,
                                  FolioString255Item_p,
                                  FolioDateItem_p,
                                  FolioLookupCodeItem_p,
                                  FolioString255Item_p,
                                  OwnerCollection_p,
                                  FormattedMailingAddress_p,
                                  MailingAddress_p);

        FolioUniqueIDItem_p.parsers (ActionCode_p,
                                     UniqueID_p);

        FolioDateItem_p.parsers (ActionCode_p,
                                 date_p);

        OwnerCollection_p.parsers (ActionCode_p,
                                   Owner_p);

        Owner_p.parsers (ActionCode_p,
                         FolioString255Item_p,
                         FolioString255Item_p,
                         FolioString1Item_p,
                         FolioString255Item_p,
                         FolioUniqueIDItem_p,
                         FolioLookupCodeItem_p,
                         FolioString255Item_p,
                         UniqueID_p);

        FolioString1Item_p.parsers (ActionCode_p,
                                    String1_p);

        FormattedMailingAddress_p.parsers (ActionCode_p,
                                           FormattedMailingAddressLine_p,
                                           FormattedMailingAddressLine_p,
                                           FormattedMailingAddressLine_p,
                                           FormattedMailingAddressLine_p,
                                           FormattedMailingAddressLine_p,
                                           FormattedMailingAddressLine_p,
                                           UniqueID_p);

        FormattedMailingAddressLine_p.parsers (ActionCode_p,
                                               String40_p);

        MailingAddress_p.parsers (ActionCode_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  FolioString255Item_p,
                                  UniqueID_p);

        LegalDescriptionCollection_p.parsers (ActionCode_p,
                                              LegalDescription_p);

        LegalDescription_p.parsers (ActionCode_p,
                                    FolioString1024Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString1024Item_p,
                                    UniqueID_p);

        FolioString1024Item_p.parsers (ActionCode_p,
                                       String1024_p);

        FolioDescription_p.parsers (ActionCode_p,
                                    Neighbourhood_p,
                                    FolioLookupCodeItem_p,
                                    FolioString255Item_p,
                                    FolioBooleanItem_p,
                                    FolioBooleanItem_p,
                                    FolioBooleanItem_p,
                                    FolioLookupCodeItem_p,
                                    FolioString255Item_p,
                                    FolioLookupCodeItem_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    LandMeasurement_p,
                                    SpecialDistrict_p,
                                    SpecialDistrict_p,
                                    SpecialDistrict_p,
                                    ManualClass_p);

        Neighbourhood_p.parsers (ActionCode_p,
                                 FolioLookupCodeItem_p,
                                 FolioString255Item_p);

        LandMeasurement_p.parsers (ActionCode_p,
                                   FolioString255Item_p,
                                   FolioString255Item_p,
                                   FolioString255Item_p,
                                   FolioString255Item_p,
                                   FolioString255Item_p);

        SpecialDistrict_p.parsers (ActionCode_p,
                                   FolioLookupCodeItem_p,
                                   FolioString255Item_p);

        ManualClass_p.parsers (ActionCode_p,
                               FolioLookupCodeItem_p,
                               FolioString255Item_p,
                               FolioDecimalItem_p);

        FolioDecimalItem_p.parsers (ActionCode_p,
                                    decimal_p);

        SaleCollection_p.parsers (ActionCode_p,
                                  Sale_p);

        Sale_p.parsers (ActionCode_p,
                        FolioString255Item_p,
                        FolioDateItem_p,
                        FolioDecimalItem_p,
                        FolioLookupCodeItem_p,
                        FolioString255Item_p,
                        FolioLookupCodeItem_p,
                        FolioString255Item_p,
                        UniqueID_p);

        PropertyValues_p.parsers (PropertyClassValuesCollection_p,
                                  PropertyClassValuesCollection_p,
                                  PropertyClassValuesCollection_p,
                                  ValuationCollection_p);

        PropertyClassValuesCollection_p.parsers (PropertyClassValues_p);

        PropertyClassValues_p.parsers (PropertyClassCode_p,
                                       String255_p,
                                       PropertySubClassCode_p,
                                       String255_p,
                                       Valuation_p,
                                       Valuation_p,
                                       Valuation_p);

        Valuation_p.parsers (decimal_p,
                             decimal_p);

        ValuationCollection_p.parsers (ValuesByETC_p);

        ValuesByETC_p.parsers (LookupCode_p,
                               String255_p,
                               PropertyClassCode_p,
                               String255_p,
                               decimal_p,
                               decimal_p);

        FolioAmendmentCollection_p.parsers (ActionCode_p,
                                            FolioAmendment_p);

        FolioAmendment_p.parsers (ActionCode_p,
                                  FolioLookupCodeItem_p,
                                  FolioString255Item_p,
                                  FolioLookupCodeItem_p,
                                  FolioString255Item_p,
                                  FolioDateItem_p,
                                  FolioString1Item_p,
                                  UniqueID_p);

        MinorTaxing_p.parsers (ActionCode_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p,
                               MinorTaxingJurisdictionCollection_p);

        MinorTaxingJurisdictionCollection_p.parsers (ActionCode_p,
                                                     MinorTaxingJurisdiction_p);

        MinorTaxingJurisdiction_p.parsers (ActionCode_p,
                                           FolioLookupCodeItem_p,
                                           FolioString1Item_p,
                                           FolioString255Item_p,
                                           UniqueID_p);

        FarmCollection_p.parsers (ActionCode_p,
                                  Farm_p);

        Farm_p.parsers (ActionCode_p,
                        FolioString255Item_p,
                        UniqueID_p);

        ManufacturedHomeCollection_p.parsers (ActionCode_p,
                                              ManufacturedHome_p);

        ManufacturedHome_p.parsers (ActionCode_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    FolioString255Item_p,
                                    UniqueID_p);

        ManagedForestCollection_p.parsers (ActionCode_p,
                                           ManagedForest_p);

        ManagedForest_p.parsers (ActionCode_p,
                                 FolioString255Item_p,
                                 UniqueID_p);

        OilAndGasCollection_p.parsers (ActionCode_p,
                                       OilAndGas_p);

        OilAndGas_p.parsers (ActionCode_p,
                             FolioString255Item_p,
                             UniqueID_p);

        LandCharacteristicCollection_p.parsers (ActionCode_p,
                                                LandCharacteristic_p);

        LandCharacteristic_p.parsers (ActionCode_p,
                                      FolioLookupCodeItem_p,
                                      FolioString255Item_p);

        DeliverySummary_p.parsers (integer_p,
                                   integer_p,
                                   integer_p,
                                   FolioGroupValues_p,
                                   FolioGroupValues_p,
                                   FolioGroupValues_p,
                                   PropertyClassValuesSummaryCollection_p,
                                   PropertyClassValuesSummaryCollection_p,
                                   PropertyClassValuesSummaryCollection_p,
                                   AmendmentReasonCountCollection_p,
                                   DeleteReasonCountCollection_p);

        FolioGroupValues_p.parsers (decimal_p,
                                    decimal_p);

        AmendmentReasonCountCollection_p.parsers (AmendmentReasonCount_p);

        AmendmentReasonCount_p.parsers (LookupCode_p,
                                        String255_p,
                                        integer_p);

        DeleteReasonCountCollection_p.parsers (DeleteReasonCount_p);

        DeleteReasonCount_p.parsers (LookupCode_p,
                                     String255_p,
                                     integer_p);
    }

    // connect signals
    connect(&FolioRecord_p, &dataadvice::FolioRecordImpl::folioSaved, this, &Parser::folioSaved);
    connect(&FolioRecord_p, &dataadvice::FolioRecordImpl::message, this, &Parser::message);

    // configure XSD location
    ::xml_schema::document doc_p (*DataAdvice_p,
                                  "http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd",
                                  "DataAdvice");

    ::xml_schema::properties props;
    props.schema_location(
                            "http://data.bcassessment.ca/DataAdvice/Formats/DAX/DataAdvice.xsd",
                            xsdPath);

    try {
        DataAdvice_p->pre();
        doc_p.parse(file, 0, props);
        file.close();
        return std::unique_ptr<model::DataAdvice>(DataAdvice_p->post_DataAdvice());
    }
    catch (const ::xml_schema::parsing& e)
    {
        file.close();
        qDebug() << e.what();
        for (auto &&d: e.diagnostics())
        {
            qDebug() << "Parse error on line " << d.line() << ", column " << d.column();
            qDebug() << QString::fromStdString(d.message());
            emit message(QString("Parse error on line ")
                         + QString::number(d.line())
                         + ", column "
                         + QString::number(d.column()));
            emit message(QString::fromStdString(d.message()));
        }
        throw QString(*e.what());
    }

    catch (const ::xml_schema::exception& e)
    {
        file.close();
        qDebug() << e.what();
        message(QString("Parse error: ") + QString(*e.what()));
        throw e.what();
    }
    catch (const std::ios_base::failure&)
    {
        file.close();
        qDebug() << "IO failue.";
        emit message(QString("IO Failure"));
        throw QString("IO Failure");
    }
    catch (dataadvice::StopParsing&)
    {
        file.close();
        qDebug() << "Stopped parsing";
        //this is terrible, and should be refactored
        if (forSummary)
            return DataAdvice_p->post_DataAdvice();
        else
            throw;
    }
}
