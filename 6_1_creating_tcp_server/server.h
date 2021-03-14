#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>
#include <QObject>

class server : public QObject
{
public:
    server(QObject * parent = nullptr);
    void startServer();
    void sendMessageToClients(QString message);

public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadReady();
    void socketStateChanged(QAbstractSocket::SocketState state);

private:
    QTcpServer* chatServer;
    QVector<QTcpSocket*>* allClients;
};

#endif // SERVER_H
