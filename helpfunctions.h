#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include "mainwindow.h"
#include <QtNetwork/QtNetwork>
#include <QNetworkInterface>

#include <GeoLite2PP.hpp>

QString GetCode(QString furl){
    QString fcode;
    QNetworkAccessManager manager;
    QUrl url;
    url = url.fromUserInput(furl);
    QNetworkRequest request(url);
    QNetworkReply *reply(manager.get(request));
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray arr=reply->readAll();
    fcode.append(arr);
    return fcode;
}

QBitArray PlanetHours(int riseh, int seth){
    if( seth <= riseh) seth = 25;
    QBitArray planethours(24);
    for (int i = 0; i < 24; ++i){
        planethours[i] = (i >= riseh)&&(i <= seth);
    }
    return planethours;
}

bool isOne (QBitArray bits){
    for (int i = 0; i < bits.size(); ++i){
        if (bits[i]) return true;
    }
    return false;
}

#endif // HELPFUNCTIONS_H
