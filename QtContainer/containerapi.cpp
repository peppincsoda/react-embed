#include "containerapi.h"

#include <QJsonObject>

ContainerApi::ContainerApi(QObject *parent)
    : QObject{parent}
{

}

void ContainerApi::asyncLoad()
{
    // Do the fetch here and call dataReady when ready...

    QMetaObject::invokeMethod(this, "dataReady");
}

void ContainerApi::dataReady()
{
    QJsonObject data;
    data["name"] = "John Doe";
    Q_EMIT onLoadReady(data);
}

void ContainerApi::triggerEvent()
{
    Q_EMIT onEvent("test_event");
}
