#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList currencies;
    currencies.push_back("KOR");
    currencies.push_back("EUR");
    currencies.push_back("USD");
    currencies.push_back("MYR");
    currencies.push_back("GBP");

    ui->nation_from->addItems(currencies);
    ui->nation_to->addItems(currencies);
    QValidator* inputRange = new QDoubleValidator(this);
    ui->cur_from->setValidator(inputRange);
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::finished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convert_btn_clicked(){
    if(ui->cur_from->text() !=""){
        ui->convert_btn->setEnabled(false);
        QString from = ui->nation_from->currentText();
        QString to = ui->nation_to->currentText();
        targetCurrency = to;
        QString url = "http://data.fixer.io/api/latest?base="+from+"&symbols="+to+"&access_key=616e8b801a222f144a9460b5e6942ca4";
        QNetworkRequest request = QNetworkRequest(QUrl(url));
        manager->get(request);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Please insert a value.");
    }
}

void MainWindow::finished(QNetworkReply * reply){
    QByteArray response = reply->readAll();
    qDebug() << response;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
    QJsonObject jsonObj = jsonResponse.object();
    QJsonObject jsonObj2 = jsonObj.value("rates").toObject();
    double rate = jsonObj.value(targetCurrency).toDouble();

    if (rate == 0)
        rate = 1;
    double amount = ui->cur_from->text().toDouble();
    double result = amount*rate;
    ui->cur_to->setText(QString::number(result));
    ui->convert_btn->setEnabled(true);
}
