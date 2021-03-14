#ifndef DDD_H
#define DDD_H

#include <QObject>

class ddd : public QObject
{
    Q_OBJECT
public:
    explicit ddd(QObject *parent = nullptr);

signals:

};

#endif // DDD_H
