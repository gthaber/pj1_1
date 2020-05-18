
#include "planes.h"

bool ReadPlane(planes&pl, std::ifstream &stream) {
    if(!stream.eof())
        stream >> pl.range;
    else return false;
    if(!stream.eof())
        stream >> pl.carry;
    else return false;
    return true;
}

void OutPlanes(std::ofstream &stream, planes &pl) {
    stream << "; Range: " << pl.range << "; Carry: " << pl.carry << ";" << std::endl;
}

