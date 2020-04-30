
#ifndef PR1_1_CONTAINER_H
#define PR1_1_CONTAINER_H

#include <iostream>
#include <fstream>
#include "transport.h"

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
void Out_Container(std::ofstream& stream, container&con);
void Sort(container&con);

#endif //PR1_1_CONTAINER_H
