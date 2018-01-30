import QtQuick 2.0
import QtQuick.Controls 1.0
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

        ScrollView {
            id: flick1
            x: 0
            y: 0
            width: 640
            height: 457
            anchors.fill: parent
            clip: true

            TextEdit {
                id: textedit1
                renderType: Text.NativeRendering
                enabled: true
                selectByMouse: true
                activeFocusOnPress: false
                readOnly: true
                wrapMode: TextEdit.NoWrap
            }
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
