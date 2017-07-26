import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item{
    id: main
    visible: true
    property int focusedContact: 0

    Flickable{
        id: flick
        clip: true
        width: parent.width
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: rowlayout.top
        anchors{
            leftMargin: 5; rightMargin: 5; topMargin: 5; bottomMargin: 5
        }
        flickableDirection: Flickable.VerticalFlick
        contentHeight: flickableHeight

        property int flickableHeight: 0

        FocusScope{

            Column{
            id: column
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            spacing: 5
            }
        }
    }

    RowLayout{
        id: rowlayout
        y: Screen.height - 200
        width: Screen.width
        height: 150
        spacing: 0

        Rectangle{
            id: add
            Layout.fillWidth: true
            Layout.minimumWidth: 50
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
                text: "Add"
            }

            MouseArea{
                anchors.fill: parent
                onPressed:{
                    addPressed();
                }
            }
        }

        Rectangle{
            id: edit
            Layout.fillWidth: true
            Layout.minimumWidth: 50
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
                text: "Edit"
            }

            MouseArea{
                anchors.fill: parent
                onPressed:{
                    editPressed();
                }
            }
        }

        Rectangle{
            id: del
            Layout.fillWidth: true
            Layout.minimumWidth: 50
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
                text: "Del"
            }

            MouseArea{
                anchors.fill: parent
                onPressed:{
                    delPressed();
                }
            }
        }
    }

    function addPressed()
    {
        var comp = Qt.createComponent("Data.qml");
        var data = comp.createObject(main);
        data.saveClicked.connect(saveClicked);
        data.editNumber = -1;
    }

    function editPressed()
    {
        var comp = Qt.createComponent("Data.qml");
        var data = comp.createObject(main);
        data.saveClicked.connect(saveClicked);
        data.editName = Model.listContacts[main.focusedContact * 3].toString();
        data.editPhone = Model.listContacts[main.focusedContact * 3 + 1].toString();
        data.editEmail = Model.listContacts[main.focusedContact * 3 + 2].toString();
        data.editNumber = main.focusedContact;
        data.editFieldsFill();
    }

    function delPressed()
    {
        Model.delContact(main.focusedContact);
        column.children = "";
        createContacts(Model.listContacts);
        //numerateContacts();
    }

    function saveClicked()
    {
        column.children = "";
        createContacts(Model.listContacts);
    }

    function focusedElement(contactNumber)
    {
        main.focusedContact = contactNumber;
        console.log(main.focusedContact)
    }

//    function numerateContacts()
//    {
//        for(var i=0; i<column.children.length; ++i){
//            column.children[i].contactNumber = i;
//        }
//    }

    function createContacts(anArray)
    {
        var contCount = 0;
        flick.flickableHeight = 0;
        for(var i=0; i<anArray.length; i+=3){
            var component = Qt.createComponent("Contact.qml");
            var rect = component.createObject(column);
            rect.focusSignal.connect(focusedElement);
            if(rect != null ){
                rect.contactName = anArray[i].toString();
                rect.contactPhone = anArray[i+1].toString();
                rect.contactEmail = anArray[i+2].toString();
                rect.contactNumber = contCount;
                ++contCount;
                flick.flickableHeight += 155;
            }
        }
    }
}
