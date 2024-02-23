#ifndef WEBSOCKETTRANSPORT_H
#define WEBSOCKETTRANSPORT_H

#include <QWebChannelAbstractTransport>

class QWebSocket;

/*!
    WebChannel transport object implementation using a WebSocket. From the Qt5 webchannel example.
*/
class WebSocketTransport : public QWebChannelAbstractTransport
{
    Q_OBJECT
public:
    explicit WebSocketTransport(QWebSocket *socket);
    ~WebSocketTransport() override;

    void sendMessage(const QJsonObject &message) override;

private:
    void textMessageReceived(const QString &message);

    QWebSocket *socket_{};
};

#endif // WEBSOCKETTRANSPORT_H
