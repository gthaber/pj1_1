
#include "planes.h"

bool Read_Plane(planes&pl, std::ifstream &stream) {
    if(!stream.eof())
        stream >> pl.range;
    else return false;
    if(!stream.eof())
        stream >> pl.carry;
    else return false;
    return true;
}

void Out_Planes(std::ofstream &stream, planes &pl) {
    stream << "; Range: " << pl.range << "; Carry: " << pl.carry << ";" << std::endl;
}

