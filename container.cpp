
#include "container.h"

void Read_Container(std::ifstream &stream, container &c) {
    while(!stream.eof()) {
        transport *temp_tr = Read_Transport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
        element *el = new element{};
        el->t = temp_tr;
        containerAdd(el, c);
    }
}

void containerAdd(element *el, container&con) {
    con.size++;
    if(con.starting == nullptr) {
        con.starting = con.ending = el;
    } else {
        con.ending->forward = el;
        con.ending = el;
        el->forward = con.starting;
    }
}

void containerInit(container &con) {
    con.size = 0;
    con.starting = con.ending = nullptr;
}

void containerClear(container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        delete el->t;
        element *next = el->forward;
        delete el;
        el = next;
    }
}

void Out_Container(std::ofstream &stream, container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        stream << i+1 << ". ";
        Out_Transport(stream, el->t);
        el = el->forward;
    }
}


void Multi(container &con, std::ofstream &ofstr) {
    ofstr << "_.-._.-._.-._.-MULTIMETHOD-._.-._.-._.-._" << std::endl;
    element *el1 = con.starting;
    element *el2 = con.starting;
    for(int i = 0; i < con.size; i++) {
        el2 = con.starting;
        for(int j = 0; j < con.size; j++) {
            if(i == j) {
                el2 = el2->forward;
                continue;
            }
            switch(el1->t->tr_type) {
                case PLANES:
                    ofstr << "| Planes + ";
                    switch(el2->t->tr_type) {
                        case PLANES:
                            ofstr << "Planes |" << std::endl;
                            Out_Transport(ofstr, el2->t);
                            break;
                        case TRAIN:
                            ofstr << "Train |" << std::endl;
                            Out_Transport(ofstr, el2->t);
                            break;
                    }
                    Out_Transport(ofstr, el1->t);
                    break;
                case TRAIN:
                    ofstr << "| Train + ";
                    switch(el2->t->tr_type) {
                        case PLANES:
                            ofstr << "Planes |" << std::endl;
                            Out_Transport(ofstr, el2->t);
                            break;
                        case TRAIN:
                            ofstr << "Train |" << std::endl;
                            Out_Transport(ofstr, el2->t);
                            break;
                    }
                    Out_Transport(ofstr, el1->t);
                    break;
            }
        }
        el1 = el1->forward;
    }
}
