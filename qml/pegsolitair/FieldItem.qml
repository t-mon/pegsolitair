// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: fieldItem
    property int fieldNumber
    width: parent.width/8
    height: parent.height/8
    Rectangle{
        anchors.fill: parent
        radius: 5
        border.color: "black"
        color: "gray"
        Text {
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            id: fieldText
            text: fieldNumber
        }
    }
}
