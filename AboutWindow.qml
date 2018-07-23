import QtQuick 2.0
import QtQuick.Controls 1.0;
import QtQuick.Window 2.0;

ApplicationWindow {
    property string appVersion
    width: 400
    height: 400
    minimumHeight: 400
    maximumHeight: 400
    minimumWidth: 400
    maximumWidth: 400
    title: qsTr("About BCAA XML Importer")

    AboutWindowForm {
        appVersion: appVersion
        updates.onLinkActivated: Qt.openUrlExternally(link);
        pluginList.model: importer.plugins;
        pluginList.delegate: Rectangle {
            Text { text: modelData }
        }

    }
}
