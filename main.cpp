#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QQmlComponent>
#include "database.h"
#include "model.h"
#include "phone.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);

    //DataBase dbapi;
    Model model;
    Phone phone;

    QQuickView view;
    view.engine()->rootContext()->setContextProperty("Phone", &phone);
    view.engine()->rootContext()->setContextProperty("Model", &model);
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    model.jsonLoader(0);

    QMetaObject::invokeMethod(view.rootObject(), "createContacts", Q_ARG(QVariant, QVariant::fromValue(model.getContacts())));

    view.show();

    //dbapi.connectToDatabase();

    return app.exec();
}
