#ifndef CONTAINERAPI_H
#define CONTAINERAPI_H

#include <QObject>

class ContainerApi : public QObject
{
    Q_OBJECT
public:
    explicit ContainerApi(QObject *parent = nullptr);

    Q_INVOKABLE void asyncLoad(); // called from JavaScript/WebChannel
    void triggerEvent(); // called only from C++

signals:
    void onLoadReady(const QJsonObject &data);
    void onLoadError(const QString& errorCode);
    void onEvent(const QString& eventType);

private:
    Q_INVOKABLE void dataReady();
};

#endif // CONTAINERAPI_H
