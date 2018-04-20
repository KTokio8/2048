import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 560
    title: qsTr("2048")

    MainForm {
        id: root
        anchors.fill: parent

        property int eN
        property int eM
        focus: true

        //Vider la grille precedente avant l'afficher
        function vidergrille() {
            for(eN = 0; eN < 4; eN++) {
                for(eM = 0; eM < 4; eM++) {
                    egrille.eNums.itemAt(4*eN+eM).eNum = "";
                    egrille.eNums.itemAt(4*eN+eM).color = "white";
                }
            }
        }

        //Afficher la grille
        function showgrille() {
            vidergrille();
            for(eN = 0; eN < 4; eN++) {
                for(eM = 0; eM < 4; eM++) {
                    if(vueGrille.lireChiffre(eN,eM)) {
                        egrille.eNums.itemAt(4*eN+eM).eNum = vueGrille.lireChiffre(eN,eM);
                        egrille.eNums.itemAt(4*eN+eM).color = vueGrille.color(eN,eM);
                    }
                }
            }
        }


        //Definir la fonction du clavier
        Keys.onPressed: {
          switch (event.key) {
            case Qt.Key_Up:
                vueGrille.mouveHaut();
                root.showgrille();
              break;
            case Qt.Key_Down:
                vueGrille.mouveBas();
                root.showgrille();
              break;
            case Qt.Key_Left:
                vueGrille.mouveGauche();
                root.showgrille()
              break;
            case Qt.Key_Right:
                vueGrille.mouveDroite();
                root.showgrille()
              break;
            default:
                break;
          }
        }

        start {
            onClicked:vueGrille.commencer(),root.showgrille();
        }
        back {
            onClicked:vueGrille.goBack(),root.showgrille();
        }

    }
}
