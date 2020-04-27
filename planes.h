
#ifndef PR1_1_PLANES_H
#define PR1_1_PLANES_H

#include <iostream>
#include <fstream>


struct planes {
    int range;
    int carry;
};

bool Read_Plane(planes&pl, std::ifstream& stream);
void Out_Planes(std::ofstream& stream, planes &pl);

#endif //PR1_1_PLANES_H
