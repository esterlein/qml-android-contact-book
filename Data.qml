import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4

Rectangle{
    id: data
    anchors.fill: parent
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    color: "lightblue"

    property string editName: "Unknown"
    property string editPhone: "Unknown"
    property string editEmail: "Unknown"
    property int editNumber: 0
    signal saveClicked();

    TextField{
        id: name
        y: 100
        width: parent.width
        placeholderText: qsTr("Enter Name")
    }

    TextField{
        id: phone
        y: 250
        width: parent.width
        placeholderText: qsTr("Enter Phone")
    }

    TextField{
        id: email
        y: 400
        width: parent.width
        placeholderText: qsTr("Enter Email")
    }

    RowLayout{
        id: rowlayout
        y: Screen.height - 200
        width: Screen.width
        height: 150
        spacing: 0

        Rectangle{
            id: save
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.maximumWidth: 1000
            height: parent.height
            color: "lightblue"
            anchors{
                leftMargin: 5; rightMargin: 5; topMargin: 5; bottomMargin: 5
            }

            Text{
                antialiasing: true
                color: "white"
                anchors.centerIn: parent
                font.pointSize: 24;
                text: "Save"
            }

            MouseArea{
                anchors.fill: parent
                onPressed:{
                    savePressed();
                }
            }
        }

        Rectangle{
            id: cancel
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.maximumWidth: 1000
            height: parent.height
            color: "lightblue"
            anchors{
                leftMargin: 5; rightMargin: 5; topMargin: 5; bottomMargin: 5
            }

            Text{
                antialiasing: true
                color: "white"
                anchors.centerIn: parent
                font.pointSize: 24;
                text: "Cancel"
            }

            MouseArea{
                anchors.fill: parent
                onPressed:{
                    cancelPressed();
                }
            }
        }
    }

    function savePressed()
    {
        data.editName = name.displayText;
        data.editPhone = phone.displayText;
        data.editEmail = email.displayText;
        Model.saveContact(data.editName, data.editPhone, data.editEmail, data.editNumber);
        data.saveClicked();
        data.destroy();
    }

    function cancelPressed()
    {
        data.destroy();
    }

    function editFieldsFill()
    {
        console.log(data.editNumber);
        if(data.editName != "Unknown"){
            name.text = data.editName;
            console.log(data.editName);
        }
        if(data.editPhone != "Unknown"){
            phone.text = data.editPhone;
            console.log(data.editPhone);
        }
        if(data.editEmail != "Unknown"){
            email.text = data.editEmail;
            console.log(data.editEmail);
        }
    }
}
