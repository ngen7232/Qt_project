#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addressRequest = new QNetworkAccessManager();
    connect(addressRequest, &QNetworkAccessManager::finished, this, &MainWindow::getAddressFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString latitude = ui->lineEdit->text();
    QString longtitude = ui->lineEdit->text();

    QNetworkRequest request;
    request.setUrl(QUrl("http://maps.googleapis.com/maps/api/geocode/xml?latlng=" + latitude + "," + longtitude + "&key=AIzaSyBhKayXIr2zgMW2olsxtuZ7x2QWyLo1itQ"));
    addressRequest->get(request);
}

void MainWindow::getAddressFinished(QNetworkReply*reply){
    QByteArray bytes =reply->readAll();

    QXmlStreamReader xml;
    xml.addData(bytes);

    while(!xml.atEnd()){
        if(xml.isStartElement()){
            QString name = xml.name().toString();
            if(name == "formatted_address"){
                QString text = xml.readElementText();
                qDebug() <<"Address:"<<text;
                return;
            }
        }
        xml.readNext();
    }

    if (xml.hasError()){
        qDebug() <<"Error loading XML:" << xml.errorString();
        return;
    }
    qDebug() <<"No result.";
}
