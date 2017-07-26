#include "phone.h"

Phone::Phone(){}

void Phone::directCall(QString number)
{
    QAndroidJniObject activity =  QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    if (activity.isValid()){
        QAndroidJniObject callConstant = QAndroidJniObject::getStaticObjectField<jstring>("android/content/Intent", "ACTION_CALL");
        QAndroidJniObject callIntent("android/content/Intent",  "(Ljava/lang/String;)V", callConstant.object());
        QAndroidJniObject package = QAndroidJniObject::fromString("com.android.server.telecom");
        callIntent.callObjectMethod("setPackage", "(Ljava/lang/String;)Landroid/content/Intent;", package.object<jstring>());
        QAndroidJniObject jNumber = QAndroidJniObject::fromString(QString("tel:%1").arg(number));
        QAndroidJniObject uri = QAndroidJniObject::callStaticObjectMethod("android/net/Uri","parse","(Ljava/lang/String;)Landroid/net/Uri;", jNumber.object());
        callIntent.callObjectMethod("setData", "(Landroid/net/Uri;)Landroid/content/Intent;", uri.object<jobject>());
        jint flag = QAndroidJniObject::getStaticField<jint>("android/content/Intent", "FLAG_ACTIVITY_NEW_TASK");
        callIntent.callObjectMethod("setFlags", "(I)Landroid/content/Intent;", flag);
        activity.callMethod<void>("startActivity","(Landroid/content/Intent;)V", callIntent.object<jobject>());
    }
    else{
        qDebug() << "something wrong with android activity";
    }
}
