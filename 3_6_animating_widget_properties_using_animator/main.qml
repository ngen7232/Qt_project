import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        id: myBox;
        width: 50;
        height: 50;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        color: "blue"
       /* ScaleAnimator{
            target: myBox;
            from: 5;
            to: 1;
            duration: 2000;
            running: true;
            loops: Animator.Infinite;
        }*/
    }

    ParallelAnimation {
        ScaleAnimator{
            target: myBox;
            from: 5;
            to: 1;
            duration: 2000;
            easing.type: Easing.InOutElastic;
            easing.amplitude: 2.0;
            easing.period: 1.5;
        }
        /*RotationAnimator{
            target: myBox;
            from:0;
            to:360;
            duration: 1000;
        }*/
        running: true;

    }
}
