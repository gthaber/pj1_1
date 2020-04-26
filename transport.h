
#ifndef PR1_1_TRANSPORT_H
#define PR1_1_TRANSPORT_H

#include <iostream>
#include <fstream>

enum T_type {
    PLANES=1,
    TRAIN=2
};

struct planes {
    int range;
    int carry;
};

struct train {
    int length;
};

struct transport {
    T_type tr_type;
    int speed;
    int distance;
    union{
        planes pl;
        train tr;
    } u;
};

struct element {
    transport* t;
    element* forward;
};

struct container {
    element* starting;
    element* ending;
    int size;
};

void containerClear(container&con);
void containerInit(container&con);
void containerAdd(element*, container&con);
void Read_Container(std::ifstream& stream, container&con);
transport* Read_Transport(std::ifstream&stream);
bool Read_Plane(planes&pl, std::ifstream& stream);
bool Read_Train(train&tr, std::ifstream& stream);

void Out_Planes(std::ofstream& stream, planes &pl);
void Out_Train(std::ofstream& stream, train &tr);
void Out_Transport(std::ofstream& stream, transport*tran);
void Out_Container(std::ofstream& stream, container&con);

#endif //PR1_1_TRANSPORT_H
