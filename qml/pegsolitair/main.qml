// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: gameBoard
    width: 600
    height: 600
    Grid{
        rows: 7
        columns: 7
        anchors.fill: parent
        spacing: 10
        Repeater{
            model: 3
            FieldItem{
                fieldNumber: index + 1
            }
        }

    }

}
