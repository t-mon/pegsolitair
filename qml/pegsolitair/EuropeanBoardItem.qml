// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1


Item{
    id: europeanBoard
    height: parent.height * 0.8
    width: parent.width * 0.8
    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        spacing: 15
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 3
                FieldItem{
                    fieldNumber: index
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 5
                FieldItem{
                    fieldNumber: index + 3
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 8
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 15
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 22
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 5
                FieldItem{
                    fieldNumber: index + 29
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 15
            Repeater{
                model: 3
                FieldItem{
                    fieldNumber: index + 34
                }
            }
        }
    }
}


