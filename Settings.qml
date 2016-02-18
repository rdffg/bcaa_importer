import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3

ApplicationWindow {
    width: 320
    height: 280
    title: qsTr("Settings")
    property alias driverType: comboBox1
    property alias serverName: serverField.text
    property alias username: usernameField.text
    property alias database: databaseField.text
    property alias password: passwordField.text
    property alias tryButton: connectButton
    property alias saveButton: saveButton
    property alias cancelButton: cancelButton
    property int rowSpacing: 4;
    property int fontSize: 8;

    Rectangle {
        id: rectangle1
        color: "#00000000"
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.fill: parent

    RowLayout {
        id: row1
        height: 40
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        spacing: 4

        Text {
            id: text1
            text: qsTr("Database Type")
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: fontSize
        }

        ComboBox {
            id: comboBox1
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        model: [
            "Apple", "Banana"
        ]
        }
    }

    RowLayout {
        id: row2
        height: 40
        anchors.topMargin: rowSpacing
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: row1.bottom
        spacing: 4

        Text {
            id: text2
            text: qsTr("Server")
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: fontSize
        }

        TextField {
            id: serverField
            anchors.left: parent.left
            anchors.leftMargin: text2.width + 10
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    RowLayout {
        id: row3
        anchors.top: row2.bottom
        anchors.topMargin: rowSpacing
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        spacing: 4

        Text {
            id: text3
            text: qsTr("Database")
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: fontSize
        }

        TextField {
            id: databaseField
            anchors.left: parent.left
            anchors.leftMargin: text3.width + 10
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    RowLayout {
        id: row4
        anchors.top: row3.bottom
        anchors.topMargin: rowSpacing
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        spacing: 4

        Text {
            id: text4
            text: qsTr("Username")
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: fontSize
        }

        TextField {
            id: usernameField
            anchors.left: parent.left
            anchors.leftMargin: text4.width + 10
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter

        }
    }

    RowLayout {
        id: row5
        anchors.top: row4.bottom
        anchors.topMargin: rowSpacing
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        spacing: 4

        Text {
            id: text5
            text: qsTr("Password")
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: fontSize
        }

        TextField {
            id: passwordField
            echoMode: TextInput.Password
            anchors.left: parent.left
            anchors.leftMargin: text5.width + 10
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    RowLayout {
        id: row6
        anchors.top: row5.bottom
        anchors.topMargin: rowSpacing
        height: 40
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        spacing: 4

        Button {
            id: saveButton
            text: qsTr("Save")
        }

        Button {
            id: cancelButton
            text: qsTr("Cancel")
        }

        Button {
            id: connectButton
            text: qsTr("Test Connection")
        }
    }
    }
}
