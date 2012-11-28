// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: fieldItem
    property int fieldNumber
    width: 80
    height: 80
    Rectangle{
        anchors.fill: parent
        radius: 10
        border.color: "black"
        color: "gray"
        Text {
            anchors.centerIn: parent
            id: fieldText
            text: fieldNumber
        }
    }
}
