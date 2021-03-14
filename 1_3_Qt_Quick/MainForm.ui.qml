import QtQuick 2.4

Item {
    width: 800
    height: 600

    BorderImage {
        id: borderImage
        anchors.fill: parent
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    MouseArea {
        id: mouseArea
        x: 0
        y: 0
        width: 800
        height: 600

        Rectangle {
            id: rectangle
            height: 78
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#ffffff"
                }

                GradientStop {
                    position: 1
                    color: "#80000000"
                }

                GradientStop {
                    position: 0
                    color: "#805bcce9"
                }
            }
            anchors.topMargin: 0
            anchors.rightMargin: 0
            anchors.leftMargin: 0

            Text {
                id: text2
                width: 212
                height: 50
                color: "#ffffff"
                text: qsTr("Tuesday, 02-03-2021 1:46 AM")
                anchors.left: parent.left
                anchors.top: parent.top
                font.pixelSize: 23
                minimumPointSize: 12
                minimumPixelSize: 12
                fontSizeMode: Text.FixedSize
                anchors.leftMargin: 0
                anchors.topMargin: 0
            }

            MouseArea {
                id: mouseArea1
                x: 371
                width: 50
                height: 50
                anchors.right: parent.right
                anchors.top: parent.top
                transformOrigin: Item.Center
                anchors.rightMargin: 10
                anchors.topMargin: 8

                Image {
                    id: shutdown_icon
                    x: 0
                    y: 0
                    width: 50
                    height: 50
                    source: "shutdown_icon.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            MouseArea {
                id: mouseArea2
                x: 669
                width: 50
                height: 50
                anchors.right: parent.right
                anchors.top: parent.top
                transformOrigin: Item.Center
                anchors.rightMargin: 81
                anchors.topMargin: 8

                Image {
                    id: restart_icon
                    x: 0
                    y: 0
                    width: 50
                    height: 50
                    source: "restart_icon.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
    }

}
