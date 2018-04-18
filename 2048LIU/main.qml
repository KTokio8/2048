import QtQuick 2.5
import QtQuick.Window 2.2
import qml2048 1.0

Window {
    visible: true
    width: 360
    height: 560
    title: qsTr("2048")

    MainForm {
        id: root
        anchors.fill: parent

        property int eI

        QT2048 { id: numProvider }

        function eClear() {
            for(eI = 0; eI < 16; eI++) {
                panel.eNums.itemAt(eI).eNum = "";
                panel.eNums.itemAt(eI).color = "white";
                panel.eNums.itemAt(eI).eNumColor= "black";
            }
        }

        function eShow() {
            eClear();
            for(eI = 0; eI < 16; eI++) {
                if(numProvider.show(eI)) {
                    panel.eNums.itemAt(eI).eNum = numProvider.show(eI);
                    panel.eNums.itemAt(eI).color = numProvider.color(eI);
                    panel.eNums.itemAt(eI).eNumColor = numProvider.numColor(eI);
                }
            }
            information.eScore = numProvider.score;
            information.eStep = numProvider.step;
            information.eBestScore = numProvider.bestScore;
            information.eTotalStep = numProvider.totalStep;
            if(0 < numProvider.step) {
                botton2.eEnBack = true;
            }
        }

        Keys.onPressed: {
            switch(event.key) {
            case Qt.Key_Up:
                numProvider.move(QT2048.Move_Up);
                root.eShow();
                break;
            case Qt.Key_Down:
                numProvider.move(QT2048.Move_Down);
                root.eShow();
                break;
            case Qt.Key_Left:
                numProvider.move(QT2048.Move_Left);
                root.eShow();
                break;
            case Qt.Key_Right:
                numProvider.move(QT2048.Move_Right);
                root.eShow();
                break;
            default:
                break;
            }
        }


        start {onClicked: {
                numProvider.start();
                root.eShow();
                root.focus = true;
                botton2.eEnBack = false;}
        }
        back {onClicked: {
                numProvider.backed();
                root.eShow();
                if(!numProvider.step) {
                    tip1.eEnBack = false;
              }
            }}
}
}
