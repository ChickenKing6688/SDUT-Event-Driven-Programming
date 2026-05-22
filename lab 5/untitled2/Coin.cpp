#include <bits/stdc++.h>

#include <Coin.h>

using namespace std;

Coin::Coin(){
    srand(time(nullptr));
}

void Coin::flip()

{

    if (rand() % 2) {

        // the emit keyword will automatically call

        // all slots associated with the signal it emits.

        emit this->heads();

    } else {

        emit tails(); // this-> is optional in this context.

    }

}
