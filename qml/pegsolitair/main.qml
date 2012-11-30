// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1


Rectangle {
    id: screen

    width: 750
    height: 750

    SystemPalette { id: activePalette }

    Rectangle{
        id: gameHistory
        anchors.top: parent.top
        anchors.bottom: toolBar.top
        anchors.right: screen.right
        width: 70
        color: "gray"
        border.color: "black"
        border.width: 2
        Text{
            anchors.fill: parent
            text: engine.history;
        }

    }

    EuropeanBoardItem{}

    Text {
        id: gameOverText
        anchors.centerIn: parent
        visible: !engine.stillCanWinn;
        font.pixelSize: 100
        font.bold: true
        color: "red"
        text: qsTr("Game Over");
    }

    Rectangle {
        id: toolBar
        width: parent.width; height: 30
        color: activePalette.window
        anchors.bottom: screen.bottom

        Button {
            anchors { left: parent.left; verticalCenter: parent.verticalCenter }
            text: "New Game"
            onClicked: engine.newGameClicked()
        }

        Text {
            id: score
            anchors { right: parent.right; verticalCenter: parent.verticalCenter }
            text: "Moves left: " + engine.movesLeft + "  ";
        }
    }
}



