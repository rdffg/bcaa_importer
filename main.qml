import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("BC Assessment Importer 2.0")
    width: 640
    height: 480
    visible: true

    Settings {
        id: settingsWindow
        driverType.model: sqlconnection.drivers
        serverName: sqlconnection.server
        database: sqlconnection.database
        username: sqlconnection.username
        password: sqlconnection.password
        tryButton.onClicked: if (sqlconnection.tryDbConnection())
                                 messageDialog.show("Connection Succeeded.")
                             else
                                 messageDialog.show("Connection Failed.")
        saveButton.onClicked: {
            sqlconnection.saveSettings();
            settingsWindow.visible = false;
        }
        cancelButton.onClicked: {
            sqlconnection.loadSettings();
            settingsWindow.visible = false;
        }

        visible: false
        modality: Qt.WindowModal
    }

    Binding {
       property: "driver"
       target: sqlconnection
       value: settingsWindow.driverType.currentText
       when:
           if (settingsWindow.driverType.currentText != "")
               return true;
           else
               console.log("driver type not selected");
    }

    Binding {
        property: "server"
        target: sqlconnection
        value: settingsWindow.serverName
    }

    Binding {
        property: "database"
        target: sqlconnection
        value: settingsWindow.database
    }

    Binding {
        property: "username"
        target: sqlconnection
        value: settingsWindow.username
    }

    Binding {
        property: "password"
        target: sqlconnection
        value: settingsWindow.password
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: {
                    fileDialog.visible = true;
                }
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: qsTr("Select Data Advice File")
        folder: if (importer.dataFilePath == "") shortcuts.home; else importer.dataFilePath;
        onAccepted: {
            importer.dataFilePath = fileDialog.fileUrl;
            console.log("XML file " + importer.dataFilePath + " chosen.");
        }
    }

    MainForm {
        anchors.fill: parent
        textedit1.text: logdata.logtext
        startbutton.onClicked: importer.beginImport();
        settingsButton.onClicked: {
            sqlconnection.loadSettings();
            if(settingsWindow.driverType.find(sqlconnection.driver) >= 0)
                                     settingsWindow.driverType.currentIndex = settingsWindow.driverType.find(sqlconnection.driver);
                                 else
                                     console.log("Failed to find the previous driver name. again.");
            settingsWindow.visible = true;
        }

    }

    MessageDialog {
        id: messageDialog
        title: qsTr("Connection Result")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
