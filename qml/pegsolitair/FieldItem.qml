// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import pegsolitaire 1.0

Item {
    id: fieldItem
    property int fieldNumber
    width: 80
    height: 80
    Rectangle{
        anchors.fill: parent
        radius: 15
        border.color: "black"
        color: board.fieldAt(fieldNumber).occupied ? "red" : "green"
        Text {
            anchors.centerIn: parent
            id: fieldText
            text: fieldNumber
        }
        MouseArea{
            anchors.fill: parent
            onClicked: engine.fieldClicked(fieldNumber)
        }
    }
}
