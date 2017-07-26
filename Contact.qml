import QtQuick 2.5
import QtQuick.Window 2.2

Rectangle{
    id: contact
    color: focus ? "blue" : "lightblue"
    radius: 10.0
    width: Screen.width - 10; height: 150

    property string contactName: "Unknown"
    property string contactPhone: "Unknown"
    property string contactEmail: "Unknown"
    property int contactNumber: 0

    signal focusSignal( int contactNumber );

    Text{
        antialiasing: true
        color: "white"
        anchors.centerIn: parent
        font.pointSize: 24
        text: parent.contactName
    }

    Text{
        antialiasing: true
        color: "white"
        font.pointSize: 16
        //x: 20
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 10
        y: 100
        text: parent.contactPhone
    }

    Text{
        antialiasing: true
        color: "white"
        font.pointSize: 16
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 10
        y: 100
        text: parent.contactEmail
    }

    MouseArea{
        anchors.fill: parent
        onPressed: {parent.focus = true; contact.focusSignal(contactNumber)}
        onPressAndHold: {Qt.openUrlExternally("tel:%1".arg(parent.contactPhone));}
        //onPressAndHold: {Phone.directCall(parent.contactPhone);}
    }
}
