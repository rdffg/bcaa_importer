import QtQuick 2.0
import QtQuick.Controls 1.0
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
                                 testConnectionDialog.show("Connection Succeeded.")
                             else
                                 testConnectionDialog.show("Connection Failed.")
        saveButton.onClicked: {
            sqlconnection.saveSettings();
            settingsWindow.visible = false;
        }
        cancelButton.onClicked: {
            sqlconnection.loadSettings();
            settingsWindow.visible = false;
        }

        driverType.onActivated: {
            console.log(index);
            console.log(driverType.model[index]);
            sqlconnection.driver = driverType.model[index];
        }

        visible: false
        modality: Qt.WindowModal
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
                shortcut: "Ctrl+O"
                onTriggered: {
                    if (importer.dataFilePath === "")
                    {
                        fileDialog.folder = fileDialog.shortcuts.home;
                    }
                    else
                    {
                        fileDialog.folder = importer.dataFilePath;
                    }

                    fileDialog.visible = true;
                }
            }
            MenuItem {
                text: qsTr("E&xit")
                shortcut: "Alt+F4"
                onTriggered: Qt.quit();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: qsTr("Select Data Advice File")
        nameFilters: ["BCA XML Files (*.xml)", "All Files (*)"]
        onAccepted: {
            importer.dataFilePath = fileDialog.fileUrl;
        }
    }

    MainForm {
        id: mainForm1
        anchors.fill: parent
        textedit1.text: logdata.logtext
        startbutton.text: importer.isRunning ? qsTr("Stop"): qsTr("Start")
        startbutton.onClicked: {
            if (importer.isRunning)
            {
                importer.cancel();
            }
            else
            {
                importer.createTables();
                var lastRun = importer.lastRun;
                var thisRun = importer.importMeta;
                if (lastRun != undefined && lastRun.runDate >= thisRun.runDate)
                {
                    overwriteImportDialog.open();
                } else {
                    verifyImportDialog.open();
                }
            }
        }

        startbutton.enabled: importer.canRun

        settingsButton.onClicked: {
            sqlconnection.loadSettings();
            if(settingsWindow.driverType.find(sqlconnection.driver) >= 0)
                                     settingsWindow.driverType.currentIndex = settingsWindow.driverType.find(sqlconnection.driver);
                                 else
                                     console.log("Failed to find the previous driver name. again.");
            settingsWindow.visible = true;
        }

        ProgressBar {
            id: progressBar1
            y: 426
            height: 23
            value: importer.percentDone
            maximumValue: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 23
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            visible: importer.isRunning

            Rectangle {
                width: text1.width + 2
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                height: text1.height
                opacity: 0.5
            }

            Text {
                id: text1
                y: 4
                text: Math.round(importer.progress / 10) * 10;
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

    }

    MessageDialog {
        id: verifyImportDialog
        icon: StandardIcon.Question
        title: qsTr("Continue Import?")
        text: "Run Type is " + importer.runType + ". Proceed?"
        onAccepted: {
            importer.beginImport();
        }
    }

    MessageDialog {
        id: overwriteImportDialog
        icon: StandardIcon.Warning
        title: "Overwrite import?"
        text: "This datafile is older than a previously imported file. Import anyway?"
        onAccepted: {
            verifyImportDialog.open();
        }
    }

    MessageDialog {
        id: testConnectionDialog
        title: qsTr("Connection Result")
        icon: StandardIcon.Information

        function show(caption) {
            testConnectionDialog.text = caption;
            testConnectionDialog.open();
        }
    }
}
