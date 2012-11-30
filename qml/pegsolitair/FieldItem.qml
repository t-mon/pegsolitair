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
        radius: 45
        border.color: board.fieldAt(fieldNumber).possibleToMove ? "green" : "transparent"
        border.width: 4
        color: "transparent"
        Rectangle{
            anchors.centerIn: parent
            width: parent.width-10
            height: parent.height-10
            radius: 40
            border.color: board.fieldAt(fieldNumber).marked ? "red" : "black"
            border.width: 4
            color: board.fieldAt(fieldNumber).occupied ? "steelblue" : "white"
            Text {
                anchors.centerIn: parent
                id: fieldText
                text: fieldNumber
            }
            MouseArea{
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: {
                    if (mouse.button === Qt.LeftButton)
                        engine.fieldClicked(fieldNumber)
                    if(mouse.button === Qt.RightButton)
                        engine.rightClicked(fieldNumber)
                }

                //onClicked: engine.fieldClicked(fieldNumber)

            }
        }
    }
}
