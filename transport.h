
#ifndef PR1_1_TRANSPORT_H
#define PR1_1_TRANSPORT_H

#include <iostream>
#include <fstream>
#include "planes.h"
#include "train.h"
#include "ship.h"

enum t_type {
    PLANES=1,
    TRAIN=2,
    SHIP=3
};

struct transport {
    t_type tr_type;
    int speed;
    int distance;
    double mass;
    union{
        planes pl;
        train tr;
        ship sh;
    } u;
};

transport* ReadTransport(std::ifstream&stream);
void OutTransport(std::ofstream& stream, transport*tran);
int EstimateTime(transport*tran);
bool Comparator(transport*q1, transport*q2);

#endif //PR1_1_TRANSPORT_H
