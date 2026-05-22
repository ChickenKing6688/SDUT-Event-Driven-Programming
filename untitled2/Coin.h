#ifndef COIN_H_
#define COIN_H_

#include <QObject>






class Coin: public QObject
{
    // When extending QObject or any of its descendants,
    // we have to call the Q_OBJECT macro.
    Q_OBJECT

public:

    Coin();

    void flip();

signals:

    void heads();

    void tails();
};

#endif
