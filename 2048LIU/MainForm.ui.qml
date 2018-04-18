import QtQuick 2.5

Rectangle {
    id: root


    property alias eEnBack: back.enabled
    property alias information: information
    property alias panel: panel
    property alias start: start
    property alias back: back
    property alias botton1: botton1
    property alias botton2: botton2

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
    }

    Text {
        id: logo
        x: 33
        y: 27
        width: 117
        height: 64
        color: "#967b7b"
        text: qsTr("2048")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        elide: Text.ElideNone
        font.pixelSize: 42
        font.family: "Verdana"
        font.bold: true
        renderType: Text.NativeRendering
        fontSizeMode: Text.Fit
    }

    Rectangle {

        id: informationrect
        x: 176
        y: 27
        width: 160
        height: 64
        color: "#ffffff"

        Grid {
            id: information
            anchors.fill: parent

            property alias eScore: score.text
            property alias eBestScore: bestScore.text
            property alias eStep: step.text
            property alias eTotalStep: totalStep.text

            Text {
                id: textscore
                x: 0
                y: 0
                width: 40
                height: 32
                text: qsTr("score:")
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }

            Text {
                id: score
                x: 60
                y: 8
                width: 40
                height: 32
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.QtRendering
                font.pixelSize: 12
            }

            Text {
                id: bestscoretext
                x: 0
                y: 0
                width: 40
                height: 32
                text: "best\nscore:"
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.QtRendering
                font.pixelSize: 12
            }

            Text {
                id: bestScore
                x: 60
                y: 8
                width: 40
                height: 32
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.QtRendering
                font.pixelSize: 12
            }

            Text {
                id: steptxt
                x: 0
                y: 0
                width: 40
                height: 32
                text: qsTr("step:")
                font.family: "Arial"
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }

            Text {
                id: step
                x: 60
                y: 8
                width: 40
                height: 32
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.QtRendering
                font.pixelSize: 12
            }

            Text {
                id: totalsteptxt
                x: 0
                y: 0
                width: 40
                height: 32
                text: qsTr("total\nstep:")
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }

            Text {
                id: totalStep
                x: 60
                y: 8
                width: 40
                height: 32
                font.family: "Arial"
                textFormat: Text.PlainText
                font.weight: Font.Light
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.QtRendering
                font.pixelSize: 12
            }
            rows: 0
            columns: 4
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
            id: panel
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
                        font.family: "Tahoma"
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 24
                    }
                }

            }

        }
    }

    Rectangle {
        signal eStart()
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
            id: text1
            text: qsTr("Start")
            font.letterSpacing: 1
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
        property alias eEnBack: back.enabled
        id: botton2
        x: 206
        y: 463
        width: 101
        height: 49
        radius: 8
        border.width: 0
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

        MouseArea {
            id: back
            x: 8
            y: 7
            anchors.fill: parent
        }

        Text {
            id: text2
            x: -9
            y: 5
            text: qsTr("Back")
            font.weight: Font.Normal
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.letterSpacing: 1
            font.family: "Tahoma"
            horizontalAlignment: Text.AlignHCenter
            font.capitalization: Font.MixedCase
            anchors.fill: parent
            font.pixelSize: 24
        }
    }


}
