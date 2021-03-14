#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QXmlStreamReader xml;

    QString filename = QFileDialog::getOpenFileName(this, "Open Xml", ".", "Xml files (*.xml)");
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() <<"Error loading XML file.";
    xml.setDevice(&file);

    while(!xml.atEnd()){
        if (xml.isStartElement()){
            QString name = xml.name().toString();

            if (name == "object"){
                qDebug()<<
                           "[Object]=================================";
                for(int i = 0; i < xml.attributes().size(); i++){
                    qDebug()<<xml.attributes().at(i).name()<<xml.attributes().at(i).value();
                }
            }

            if (name == "name" || name == "position" || name == "rotation" || name == "scale"){
                QString text = xml.readElementText();
                qDebug() << name << text;
            }
        }
        if (xml.isEndElement()){
            QString name = xml.name().toString();

            if (name == "object")
                qDebug()<<"==================================";
        }

        xml.readNext();
    }
    if (xml.hasError()){
        qDebug() <<"Error loading XMS:" << xml.errorString();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QXmlStreamWriter xml;
    QString filename = QFileDialog::getSaveFileName(this, "Save Xml", ".", "Xml files (*.xml)");
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text))
        qDebug() << "Error saving XML files.";
    xml.setDevice(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();

    xml.writeStartElement("contact");
    xml.writeAttribute("category", "Friend");
    xml.writeTextElement("name", "John Doe");
    xml.writeTextElement("age", "32");
    xml.writeTextElement("address", "114B, 2nd Floor, Sterling apt, Morrison Town");
    xml.writeTextElement("phone", "0221743566");
    xml.writeEndElement();

    xml.writeStartElement("contact");
    xml.writeAttribute("category", "Family");
    xml.writeTextElement("name", "Jane Smith");
    xml.writeTextElement("age", "24");
    xml.writeTextElement("address", "13, Ave Park, Alexandria");
    xml.writeTextElement("phone", "02123442231");
    xml.writeEndElement();
    xml.writeEndDocument();

}
