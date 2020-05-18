
#include "transport.h"


transport *ReadTransport(std::ifstream &stream) {
    int type;
    stream >> type;
    if(type < 1 || type > 3) {
        std::cout << "Input error." << std::endl;
        return nullptr;
    }
    transport* temp_t = nullptr;
    switch (type) {
        case t_type::PLANES:
            temp_t = new transport{};
            ReadPlane(temp_t->u.pl, stream);
            temp_t->tr_type = t_type::PLANES;
            break;
        case t_type::TRAIN:
            temp_t = new transport{};
            ReadTrain(temp_t->u.tr, stream);
            temp_t->tr_type = t_type::TRAIN;
            break;
        case t_type::SHIP:
            temp_t = new transport();
            ReadShip(temp_t->u.sh, stream);
            temp_t->tr_type = t_type::SHIP;
            break;
        default:
            return temp_t;
    }
    if(!stream.eof()) stream >> temp_t->speed;
    else delete temp_t;
    if(temp_t->speed <= 0) {
        delete temp_t;
        return nullptr;
    }
    if(!stream.eof()) stream >> temp_t->distance;
    else delete temp_t;
    if(!stream.eof()) stream >> temp_t->mass;
    else delete temp_t;
    if(temp_t->mass <= 0) {
        delete temp_t;
        return nullptr;
    }
    return temp_t;
}

void OutTransport(std::ofstream &stream, transport *tran) {
    stream << "Speed: " << tran->speed << "; Distance: " << tran->distance <<
           "; Time: " << EstimateTime(tran) << "; Mass: " << tran->mass << "; Type: ";
    switch (tran->tr_type) {
        case t_type::PLANES:
            stream << "Planes";
            OutPlanes(stream, tran->u.pl);
            break;
        case t_type::TRAIN:
            stream << "Train";
            OutTrain(stream, tran->u.tr);
            break;
        case t_type::SHIP:
            stream << "Ship";
            OutShip(stream, tran->u.sh);
            break;
    }
}

int EstimateTime(transport *tran) {
    // Идеальное время прохождения пути (действительное число)
    return tran->distance / tran->speed;
}

bool Comparator(transport *q1, transport *q2) {
    return EstimateTime(q1) < EstimateTime(q2);
}
