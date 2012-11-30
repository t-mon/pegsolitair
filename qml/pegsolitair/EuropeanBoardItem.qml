// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item{
    id: gameBoard
    anchors.top: parent.top
    anchors.bottom: toolBar.top
    anchors.right: gameHistory.left
    anchors.left: screen.left

    Column{
        anchors.centerIn: parent
        spacing: 12
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 3
                FieldItem{
                    fieldNumber: index
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 5
                FieldItem{
                    fieldNumber: index + 3
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 8
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 15
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 7
                FieldItem{
                    fieldNumber: index + 22
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 5
                FieldItem{
                    fieldNumber: index + 29
                }
            }
        }
        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 12
            Repeater{
                model: 3
                FieldItem{
                    fieldNumber: index + 34
                }
            }
        }
    }
}

//    Rectangle{
//        id: gameBoard
//        anchors.top: parent.top
//        anchors.bottom: toolBar.top
//        anchors.right: gameHistory.left
//        anchors.left: screen.left
//        color: "white"

//        Column{
//            anchors.centerIn: parent
//            spacing: 12
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 3
//                    FieldItem{
//                        fieldNumber: index
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 5
//                    FieldItem{
//                        fieldNumber: index + 3
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 7
//                    FieldItem{
//                        fieldNumber: index + 8
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 7
//                    FieldItem{
//                        fieldNumber: index + 15
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 7
//                    FieldItem{
//                        fieldNumber: index + 22
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 5
//                    FieldItem{
//                        fieldNumber: index + 29
//                    }
//                }
//            }
//            Row{
//                anchors.horizontalCenter: parent.horizontalCenter
//                spacing: 12
//                Repeater{
//                    model: 3
//                    FieldItem{
//                        fieldNumber: index + 34
//                    }
//                }
//            }
//        }
//    }
