
#include "ship.h"

bool ReadShip(ship&sh, std::ifstream &stream) {
    if(!stream.eof())
        stream >> sh.displacement;
    else return false;
    if(!stream.eof()) {
        int typ;
        stream >> typ;
        sh.ship_type = (ship_type)typ;
    }
    else return false;
    return true;
}

void OutShip(std::ofstream &stream, ship &sh) {
    stream << "; Displacement: " << sh.displacement << "; Ship type: " << ShipTypeStr(sh.ship_type) << ";" << std::endl;
}

std::string ShipTypeStr(ship_type t) {
    switch(t) {
        case 1:
            return "Liner";
        case 2:
            return "Tug";
        case 3:
            return "Tanker";
        default:
            return "Unknown type";
    }
}
