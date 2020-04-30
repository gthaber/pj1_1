
#include "ship.h"

bool Read_Ship(ship&sh, std::ifstream &stream) {
    if(!stream.eof())
        stream >> sh.displacement;
    else return false;
    if(!stream.eof()) {
        int typ;
        stream >> typ;
        sh.ship_type = (Ship_type)typ;
    }
    else return false;
    return true;
}

void Out_Ship(std::ofstream &stream, ship &sh) {
    stream << "; Displacement: " << sh.displacement << "; Ship type: " << Ship_type_str(sh.ship_type) << ";" << std::endl;
}

std::string Ship_type_str(Ship_type t) {
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
