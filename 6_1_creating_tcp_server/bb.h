#ifndef BB_H
#define BB_H

#include <QObject>

class bb : public QObject
{
    Q_OBJECT
public:
    explicit bb(QObject *parent = nullptr);

signals:

};

#endif // BB_H
