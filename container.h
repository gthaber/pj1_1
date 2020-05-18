
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

void ContainerClear(container&con);
void ContainerInit(container&con);
void ContainerAdd(element *el, container&con);
void ReadContainer(std::ifstream& stream, container&c);
int OutContainer(std::ofstream& stream, container&con, t_type but);
void OutContainer(std::ofstream& stream, container&con);
void Sort(container&con);

#endif //PR1_1_CONTAINER_H
