import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 640
    height: 480

    property alias startbutton: button1
    property alias textedit1: textedit1
    property alias settingsButton: settingsButton1

    RowLayout {
        id: rowLayout1
        anchors.bottom: parent.bottom

        Button {
            id: button1
            text: qsTr("Start")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }

        Button {
            id: settingsButton1
            text: qsTr("Settings...")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }
    }
    RowLayout {
        id: rowlayout2
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.bottom: rowLayout1.top
        anchors.bottomMargin: 0


        Rectangle {
            color: "#dbdbdb"
            border.color: "#242424"
            anchors.fill: parent
        }
        TextEdit {
            id: textedit1
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
}
