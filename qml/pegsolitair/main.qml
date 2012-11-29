// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: window
    width: 900
    height: 750

    Column{
        anchors.fill: parent
        EuropeanBoardItem{
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }
//        Text{
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.baseline: parent.baseline
//            text: "This is the european board of the game Peg Solitair \nclick with the right button on a field"
//        }
    }
}
