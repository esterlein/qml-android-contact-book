#ifndef PHONE_H
#define PHONE_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QDesktopServices>
#include <QUrl>

class Phone : public QObject
{
    Q_OBJECT

public:
    Phone();
    Q_INVOKABLE void directCall(QString number);
};

#endif // PHONE_H
