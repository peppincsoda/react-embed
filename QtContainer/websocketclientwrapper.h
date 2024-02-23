#ifndef WEBSOCKETCLIENTWRAPPER_H
#define WEBSOCKETCLIENTWRAPPER_H

#include <QObject>

class QWebSocketServer;

class WebSocketTransport;

/*!
    Wrap incoming connections of QWebSocketServer with WebSocketTransport. From the Qt5 webchannel example.
*/
class WebSocketClientWrapper : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClientWrapper(QWebSocketServer *server, QObject *parent = nullptr);

Q_SIGNALS:
    void clientConnected(WebSocketTransport *client);

private:
    void handleNewConnection();

    QWebSocketServer *server_{};
};

#endif // WEBSOCKETCLIENTWRAPPER_H
