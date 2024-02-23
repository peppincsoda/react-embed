#include "websocketclientwrapper.h"
#include "websockettransport.h"

#include <QWebSocketServer>

WebSocketClientWrapper::WebSocketClientWrapper(QWebSocketServer *server, QObject *parent)
    : QObject{parent}
    , server_(server)
{
    connect(server, &QWebSocketServer::newConnection,
            this, &WebSocketClientWrapper::handleNewConnection);
}

void WebSocketClientWrapper::handleNewConnection()
{
    Q_EMIT clientConnected(new WebSocketTransport(server_->nextPendingConnection()));
}
