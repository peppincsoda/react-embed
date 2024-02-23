#include "websockettransport.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QWebSocket>

WebSocketTransport::WebSocketTransport(QWebSocket *socket)
    : QWebChannelAbstractTransport(socket)
    , socket_(socket)
{
    connect(socket, &QWebSocket::textMessageReceived,
            this, &WebSocketTransport::textMessageReceived);
    connect(socket, &QWebSocket::disconnected,
            this, &WebSocketTransport::deleteLater);
}

WebSocketTransport::~WebSocketTransport()
{
    socket_->deleteLater();
}

void WebSocketTransport::sendMessage(const QJsonObject &message)
{
    QJsonDocument doc(message);
    socket_->sendTextMessage(QString::fromUtf8(doc.toJson(QJsonDocument::Compact)));
}

void WebSocketTransport::textMessageReceived(const QString &message)
{
    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(message.toUtf8(), &error);
    if (error.error) {
        qWarning() << "Failed to parse text message as JSON object:" << message
                   << "Error:" << error.errorString();
        return;
    } else if (!json.isObject()) {
        qWarning() << "Received JSON message that is not an object: " << message;
        return;
    }
    emit messageReceived(json.object(), this);
}
