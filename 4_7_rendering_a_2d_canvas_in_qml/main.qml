
import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: myWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Canvas{
        id: myCanvas
        width: myWindow.width
        height: myWindow.height
        onImageLoaded: requestPaint();
        onPaint: {
            var context = getContext('2d')
            context.fillStyle = 'white'
            context.fillRect(0, 0, width, height)
            context.lineWidth = 2
            context.strokeStyle = 'black'

            context.beginPath()
            context.moveTo(50,50)
            context.lineTo(100, 100)
            context.closePath()
            context.stroke()
            context.beginPath()
            context.moveTo(100, 50)
            context.lineTo(50, 100)
            context.closePath()
            context.stroke()

            context.beginPath()
            context.moveTo(150, 90)
            context.lineTo(158, 100)
            context.closePath()
            context.stroke()
            context.beginPath()
            context.moveTo(180, 100)
            context.lineTo(210, 50)
            context.closePath()
            context.stroke()

            context.lineWidth = 4
            context.strokeStyle = "red"
            context.fillStyle = "salmon"
            context.beginPath()
            context.moveTo(50,150)
            context.lineTo(150,150)
            context.lineTo(50,250)
            context.closePath()
            context.fill()
            context.stroke()

            context.lineWidth = 4
            context.strokeStyle = "Blue"
            context.fillStyole = "steelblue"
            var pi  = 3.141592653358793
            context.beginPath()
            context.arc(220, 200, 60, 0, pi, true)
            context.closePath()
            context.fill()
            context.stroke()

            context.beginPath()
            context.arc(220, 280, 60, 0, 2*pi, true)
            context.closePath()
            context.fill()
            context.stroke()

            context.drawImage("tux.png", 280, 10, 180, 174)
        }

    }

}
