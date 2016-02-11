import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
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
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.fill: parent
        textedit1.text: logdata.logtext
        startbutton.onClicked: importer.beginImport();
        settingsButton.onClicked: settingsWindow.visible = true;

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
