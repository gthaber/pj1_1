
#ifndef PR1_1_TRANSPORT_H
#define PR1_1_TRANSPORT_H

#include <iostream>
#include <fstream>
#include "planes.h"
#include "train.h"

enum T_type {
    PLANES=1,
    TRAIN=2
};

struct transport {
    T_type tr_type;
    int speed;
    int distance;
    double mass;
    union{
        planes pl;
        train tr;
    } u;
};

transport* Read_Transport(std::ifstream&stream);
void Out_Transport(std::ofstream& stream, transport*tran);

#endif //PR1_1_TRANSPORT_H
