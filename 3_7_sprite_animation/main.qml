import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent;
        color: "white";

    }

    AnimatedSprite{
        id: sprite;
        width: 128;
        height: 129;
        x: -128;
        y: parent.height/2;

        source: "qrc:/../../../Desktop/9781789803822_Code/9781789803822_Code/Chapter03/Sprite_Animation/horse_1.png";
        frameCount: 11;
        frameWidth: 128;
        frameHeight:128;
        frameRate: 25;
        loops: Animation.Infinite;
        running: true;
    }

    MouseArea{
        anchors.fill: parent;
        onClicked: {
            if (sprite.paused)
                sprite.resume();
            else
                sprite.pause();
        }
    }

    NumberAnimation{
        target: sprite;
        property: "x";
        from: -128;
        to:512;
        duration: 5000;
        loops: Animation.Infinite;
        running: true;
    }
}
