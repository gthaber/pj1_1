
#ifndef PR1_1_SHIP_H
#define PR1_1_SHIP_H

#include <iostream>
#include <fstream>
#include <string>

enum ship_type {
    LINER = 1,
    TUG = 2,
    TANKER = 3
};

struct ship {
    int displacement;
    ship_type ship_type;
};

std::string ShipTypeStr(ship_type t);
bool ReadShip(ship&sh, std::ifstream& stream);
void OutShip(std::ofstream& stream, ship &sh);

#endif //PR1_1_SHIP_H
