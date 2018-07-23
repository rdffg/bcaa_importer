import QtQuick 2.0
import QtQuick.Layouts 1.0

Item {
    id: item1
    width: 400
    height: 400
    property alias pluginList: pluginList
    property string appVersion
    property alias updates: updates
    ColumnLayout {
        id: column
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        spacing: 6

        Image {
            width: 390
            height: 73
            sourceSize.height: 73
            sourceSize.width: 390
            Layout.maximumWidth: 390
            Layout.maximumHeight: 73
            Layout.fillHeight: false
            Layout.fillWidth: true
            fillMode: Image.PreserveAspectFit
            source: "RDFFG_logo.svg"
        }

        Text {
            text: "Version " + version
        }

        Text {
            id: updates
            text: "Updates: go to <a href=\"https://github.com/rdffg/bcaa_importer/releases\">our github page</a>."
            textFormat: Text.RichText
            font.pixelSize: 12
        }

        Text {
            y: 0
            text: "Copyright Regional District of Fraser-Fort George 2018"
            transformOrigin: Item.Center
            Layout.fillWidth: true
        }

        Text {
            id: pluginslabel
            text: qsTr("Loaded Plugins")
            font.bold: true
            font.pixelSize: 14
        }

        ListView {
            id: pluginList
            width: 110
            height: 160
            spacing: 14
            interactive: true
            Layout.fillWidth: true
        }
    }
}
