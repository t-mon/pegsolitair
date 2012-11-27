// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: gameBoard
    width: 600
    height: 600
    Row{
        anchors.fill: parent
        spacing: 10
        //anchors.centerIn: parent
        Grid{
            rows: 2
            columns: 3
            spacing: 10

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            FieldItem{
                fieldNumber: 1
            }
            FieldItem{
                fieldNumber: 2
            }
            FieldItem{
                fieldNumber: 3

            }
        }
    }
}
