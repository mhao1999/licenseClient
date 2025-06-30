import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: wnd
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RowLayout {
        spacing: 8
        Layout.fillWidth: true
        width: parent.width -20
        anchors.leftMargin: 10
        anchors.left: parent.left
        TextField {
            id: codeInput
            Layout.fillWidth: true

            placeholderText: qsTr("请输入key")
            font.family: "KaiTi"
            font.pointSize: 16
            selectByMouse: true
            // enabled: isCodeSent
            inputMethodHints: Qt.ImhDigitsOnly
            maximumLength: 6
            implicitHeight: 50

            background: Rectangle {
                color: codeInput.enabled ? "#f8f9fa" : "#ecf0f1"
                border.color: codeInput.activeFocus ? "#3498db" : "#bdc3c7"
                border.width: 2
                radius: 8
            }
        }


    }
}
