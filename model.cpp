#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include "model.h"

Model::Model(QObject* parent) : QObject(parent){}

void Model::jsonParser(QJsonObject jsonObject, int type)
{
    switch(type){
    case 0:{
        QJsonValue jsonValue = jsonObject.value("Contacts");
        QJsonArray jsonArray = jsonValue.toArray();
        foreach (const QJsonValue & v, jsonArray){
            listContacts << v.toObject().value("Name").toString();
            listContacts << v.toObject().value("Phone").toString();
            listContacts << v.toObject().value("Email").toString();
        }}
        break;
        default:
        break;
    }
}

void Model::jsonLoader(int type)
{
    QString typesrc;
    switch(type){
    case 0: typesrc = "contacts.json"; break;
    case 1: typesrc = "schedule.json"; break;
    case 2: typesrc = "notes.json"; break;
    }
    if(!typesrc.isEmpty()){
        QFile json(":/contacts.json");
        if(json.open(QIODevice::ReadOnly | QFile::Text)){
            QJsonParseError  parseError;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(json.readAll(), &parseError);
            if(parseError.error == QJsonParseError::NoError){
                if(jsonDoc.isObject()){
                    jsonParser(jsonDoc.object(), type);
                }
            }
            else{
                qDebug()<<parseError.errorString();
            }
        }
        else{
            qDebug()<<"failed open txt";
        }
    }
    else{
        qDebug()<<"unknown query type";
    }
}

QVariantList Model::getContacts()
{
    return listContacts;
}

void Model::saveContact(QString name, QString phone, QString email, const int number)
{
    if(number == -1){
        listContacts << name;
        listContacts << phone;
        listContacts << email;
    }
    else{
        listContacts[number * 3] = name;
        listContacts[number * 3 + 1] = phone;
        listContacts[number * 3 + 2] = email;
    }
}

void Model::delContact(const int number)
{
    for(auto i = 0; i < 3; ++i)
        listContacts.removeAt(number * 3);
}
