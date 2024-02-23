#include <QApplication>
#include <QWebChannel>
#include <QWebSocketServer>

#include "mainwindow.h"
#include "containerapi.h"
#include "websocketclientwrapper.h"
#include "websockettransport.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWebSocketServer webSocketServer(QStringLiteral("Local QWebChannel Server"), QWebSocketServer::NonSecureMode);
    if (!webSocketServer.listen(QHostAddress::LocalHost, 29999)) {
        qFatal("Failed to initialize web socket server");
        return 1;
    }

    WebSocketClientWrapper clientWrapper(&webSocketServer);
    QWebChannel channel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                     &channel, &QWebChannel::connectTo);

    ContainerApi containerApi;
    channel.registerObject("containerApi", &containerApi);

    MainWindow mainWindow(&containerApi);
    mainWindow.show();

    return app.exec();
}
