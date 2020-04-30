
#ifndef PR1_1_SHIP_H
#define PR1_1_SHIP_H

#include <iostream>
#include <fstream>
#include <string>

enum Ship_type {
    liner = 1,
    tug = 2,
    tanker = 3
};

struct ship {
    int displacement;
    Ship_type ship_type;
};

std::string Ship_type_str(Ship_type t);
bool Read_Ship(ship&sh, std::ifstream& stream);
void Out_Ship(std::ofstream& stream, ship &sh);

#endif //PR1_1_SHIP_H
