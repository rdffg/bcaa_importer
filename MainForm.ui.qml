import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 640
    height: 480

    property alias startbutton: button1
    property alias textedit1: textedit1
    property alias settingsButton: settingsButton1

    RowLayout {
        id: rowlayout1
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.bottom: rowLayout2.top
        anchors.bottomMargin: 0


        Rectangle {
            color: "#dbdbdb"
            border.color: "#242424"
            anchors.fill: parent
        }
        TextArea {
            id: textedit1
            anchors.fill: parent
            readOnly: true
        }
    }
    RowLayout {
        id: rowLayout2
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
}