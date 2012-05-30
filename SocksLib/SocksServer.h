#ifndef SOCKSSERVER_H
#define SOCKSSERVER_H

#include <QObject>
class QTcpServer;
#include <QPointer>
#include <QList>

#include "SocksLib_global.h"
class SocksConnection;

class SOCKSLIBSHARED_EXPORT SocksServer : public QObject
{
    Q_OBJECT
public:
    explicit SocksServer(QObject *parent = 0);
    ~SocksServer();

    void start();

    bool isStarted() const;
    
signals:
    
public slots:

private slots:
    void handleNewIncomingConnection();

private:
    QPointer<QTcpServer> _serverSock;
    QList<QPointer<SocksConnection> > _connections;
    
};

#endif // SOCKSSERVER_H
