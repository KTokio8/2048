import QtQuick 2.5

Rectangle {
    id: rectangle1

    property alias egrille: jeuxgrille
    property alias start: start
    property alias back: back
    width: 360
    height: 560
    color: "#ffffff"
    radius: 13
    border.width: 7
    border.color: "#000000"


    Rectangle {
        id: logorecrt
        x: 33
        y: 27
        width: 117
        height: 64
        color: "#ffffff"

        Text {
            id: logo
            color: "#967b7b"
            text: qsTr("2048")
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 42
            elide: Text.ElideNone
            font.family: "Verdana"
            font.bold: true
            renderType: Text.NativeRendering
            fontSizeMode: Text.Fit
        }
    }



    Rectangle {
        id: panelrect
        x: 33
        y: 139
        width: 300
        height: 300
        color: "#9e9c9c"
        radius: 7



        Grid {
            id: jeuxgrille
            x: 8
            y: 8
            width: 292
            height: 291
            spacing: 4
            transformOrigin: Item.Center
            rows: 4
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            columns: 4

            property var eNums: repeater

            Repeater {
                id: repeater
                model: 16

                Rectangle {

                    property alias eNum: innerNum.text
                    property alias eNumColor: innerNum.color

                    x: 39
                    y: 45
                    width: 70
                    height: 70
                    color: "#c9c4c4"
                    radius: 8

                    Text {
                        id: innerNum
                        color: "#6c6161"
                        opacity: 0.7
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.bold: true
                        font.family: "Tahoma"
                        font.pixelSize: 24
                    }
                }

            }

        }
    }
    Rectangle {
        property alias start: start
        id: botton1
        x: 59
        y: 463
        width: 101
        height: 49
        radius: 13
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
        border.color: "#ffffff"
        border.width: 0

        MouseArea {
            id: start
            anchors.fill: parent
        }


        Text {
            id: starttxt
            text: qsTr("Start")
            opacity: 0.5
            font.letterSpacing: 2
            font.weight: Font.Normal
            font.capitalization: Font.MixedCase
            font.bold: true
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 24
        }
    }

    Rectangle {

        property alias back: back
        id: botton2
        x: 206
        y: 463
        width: 101
        height: 49
        radius: 8
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }
        border.color: "#ffffff"
        border.width: 0

            MouseArea {
                id: back
                x: 8
                y: 7
                anchors.fill: parent
            }

            Text {
                id: backtext
                x: -9
                y: 5
                color: "#000000"
                text: qsTr("Back")
                opacity: 0.5
                font.letterSpacing: 2
                font.weight: Font.Normal
                font.capitalization: Font.MixedCase
                font.bold: true
                font.family: "Tahoma"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 24
            }
        }

        Rectangle {
            id: terminalbox
            x: 33
            y: 139
            width: 300
            height: 300
            color: "#eaeae2"
            opacity: vueGrille.QMLtermine*0.04

            Text {
                id: dialogmsg
                text: "Game Over"
                opacity: 1
                font.family: "Verdana"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 42
            }
        }

        Text {
            id: text1
            x: 271
            y: 84
            width: 70
            height: 49
            text: vueGrille.QMLstep
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 23
        }

        Rectangle {
            id: rectangle
            x: 185
            y: 84
            width: 94
            height: 49
            color: "#ffffff"

            Text {
                id: text2
                text: "Step:"
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Courier"
                anchors.fill: parent
                font.pixelSize: 18
            }
        }




}

