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
    QDomDocument xml;

    QString filename = QFileDialog::getOpenFileName(this,"Open Xml", ".", "Xml files (*.xml)");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))
        qDebug() << "Error loading XML files.";
    if(!xml.setContent(&file)){
        qDebug() << "Error setting content";
        file.close();
        return;
    }
    file.close();

    QDomElement element = xml.documentElement();
    QDomNode node = element.firstChild();
    while(!node.isNull()){
        QDomElement nodeElement = node.toElement();
        if(!nodeElement.isNull()){
            if(nodeElement.tagName() == "object"){
                qDebug()<<"[Object]=========================";
                QDomNode childNode = nodeElement.firstChild();

                while(!childNode.isNull()){
                    QDomElement childNodeElement = childNode.toElement();

                    QString name = childNodeElement.tagName();
                    if (name=="name" || name == "position" || name=="rotation" || name=="scale"){
                        QString text = childNodeElement.text();
                        qDebug() << name <<text;
                    }
                    childNode = childNode.nextSibling();
                }
            }
            qDebug()<<"========================";
        }
        node = node.nextSibling();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename =QFileDialog::getSaveFileName(this, "Save Xml", ".", "Xml files (*.xml)");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() <<"Error saveing XML file.";
        file.close();
        return;
    }

    QDomDocument xml("contact");

    QDomElement root = xml.createElement("contact");
    root.setAttribute("category", "Family");
    xml.appendChild(root);

    QDomElement tagName = xml.createElement("name");
    root.appendChild(tagName);
    QDomText textName = xml.createTextNode("John Doe");
    tagName.appendChild(textName);

    QDomElement tagAge = xml.createElement("age");
    root.appendChild(tagAge);
    QDomText textAge = xml.createTextNode("32");
    tagAge.appendChild(textAge);

    QDomElement root2 = xml.createElement("contact");
    root2.setAttribute("category", "Friend");
    xml.appendChild(root2);

    QDomElement tagName2 = xml.createElement("name");
    root2.appendChild(tagName2);
    QDomText textName2 = xml.createTextNode("Jane Smith");
    tagName2.appendChild(textName2);

    QDomElement tagAge2 = xml.createElement("age");
    root2.appendChild(tagAge2);
    QDomText textAge2 = xml.createTextNode("22");
    tagAge2.appendChild(textAge2);

    QTextStream output(&file);
    output << xml.toString();
    file.close();
}
