#ifndef THROTTLINGDECORATOR_H
#define THROTTLINGDECORATOR_H

#include "QIODeviceDecorator.h"

#include <QTimer>
#include <QByteArray>

class ThrottlingDecorator : public QIODeviceDecorator
{
    Q_OBJECT
public:
    explicit ThrottlingDecorator(QIODevice * toDecorate, QObject *parent = 0);
    virtual ~ThrottlingDecorator();

    //These are all virtual from QIODeviceDecorator
    virtual bool atEnd() const;
    virtual qint64 bytesAvailable() const;
    virtual qint64 bytesToWrite() const;
    virtual bool canReadLine() const;
    virtual bool waitForBytesWritten(int msecs);
    virtual bool waitForReadyRead(int msecs);

protected:
    //pure-virtual from QIODevice
    virtual qint64 readData(char *data, qint64 maxlen);
    virtual qint64 readLineData(char *data, qint64 maxlen);
    virtual qint64 writeData(const char *data, qint64 len);
    
signals:
    
public slots:

protected slots:
    //These are all virtual from QIODeviceDecorator
    virtual void handleChildReadChannelFinished();
    virtual void handleChildReadyRead();

private slots:
    void handleBuckets();
    void handleWriteQueue();

private:
    QTimer * _bucketTimer;
    qint64 _readBucket;
    qint64 _writeBucket;

    qint64 _readBytesPerSecond;
    qint64 _writeBytesPerSecond;

    QByteArray _writeQueue;
    
};

#endif // THROTTLINGDECORATOR_H