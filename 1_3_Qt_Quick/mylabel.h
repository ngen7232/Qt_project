#ifndef MYLABEL_H
#define MYLABEL_H

#include "QObject"

class MyLabel: public QObject
{
public:
    QObject* myObject;
    MyLabel();
    explicit MyLabel(QObject *parent = 0);

    Q_INVOKABLE void SetMyObject(QObject* obj);
};

#endif // MYLABEL_H
