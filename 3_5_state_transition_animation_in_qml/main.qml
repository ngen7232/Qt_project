import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    color: "#000000"
    title: qsTr("Hello World")

    Rectangle{
        id: background;
        anchors.fill: parent;
        color: "blue";
/*
        SequentialAnimation on color{

            ColorAnimation {
                to: "yellow"
                duration: 1000
            }
            ColorAnimation {
                to: "red"
                duration: 1000
            }
            ColorAnimation {
                to: "blue"
                duration: 1000
            }
            loops: Animation.Infinite;
        }*/

        state: "RELEASED";
        states: [
            State{
                name: "PRESSED"
                PropertyChanges {
                    target: background;
                    color:"blue";
                }
            },
            State{
                name: "RELEASED"
                PropertyChanges {
                    target: background;
                    color:"red";
                }
            }

        ]

        MouseArea{
            anchors.fill:parent;
            onPressed: background.state = "PRESSED";
            onReleased: background.state = "RELEASED";
        }

        transitions:[
            Transition{
                from: "PRESSED"
                to: "RELEASED"
                ColorAnimation{target:background; duration:200}
            },
            Transition{
                from: "RELEASED"
                to: "PRESSED"
                ColorAnimation{target:background; duration:200}
            }

        ]
    }

    Text{
        text: qsTr("Hello World");
        anchors.centerIn: parent;
        color: "white";
        font.pointSize: 15;

        SequentialAnimation on opacity{
            NumberAnimation { to: 0.0; duration:200}
            NumberAnimation { to: 1.0; duration:200}
            loops: Animation.Infinite;
        }
        NumberAnimation on rotation{
            from: 0;
            to: 360;
            duration: 2000;
            loops: Animation.Infinite;
        }
    }
}
