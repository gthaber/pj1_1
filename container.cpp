
#include "container.h"

void ReadContainer(std::ifstream &stream, container &c) {
    while(!stream.eof()) {
        transport *temp_tr = ReadTransport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
        element *el = new element{};
        el->t = temp_tr;
        ContainerAdd(el, c);
    }
}

void ContainerAdd(element *el, container&con) {
    con.size++;
    if(con.starting == nullptr) {
        con.starting = con.ending = el;
    } else {
        con.ending->forward = el;
        con.ending = el;
        el->forward = con.starting;
    }
}

void ContainerInit(container &con) {
    con.size = 0;
    con.starting = con.ending = nullptr;
}

void ContainerClear(container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        delete el->t;
        element *next = el->forward;
        delete el;
        el = next;
    }
}

void OutContainer(std::ofstream &stream, container &con) {
    element *el = con.starting;
    for(int i = 0; i < con.size; i++) {
        stream << i+1 << ". ";
        OutTransport(stream, el->t);
        el = el->forward;
    }
}

void Sort(container &con) {
    element *el1 = con.starting;
    for (int i = 0; i < con.size - 1; i++) {
        element *el2 = el1;
        el2 = el2->forward;
        for (int j = 0; j < con.size - 1 - i; j++) {
            //std::cout << "checking " << Estimate_Time(el1->t) << ";" << EstimateTime(el2->t) << std::endl;
            if (Comparator(el1->t, el2->t)) {
                transport *el_temp = el1->t;
                el1->t = el2->t;
                el2->t = el_temp;
            }
            el2 = el2->forward;
        }
        el1 = el1->forward;
    }
}

int OutContainer(std::ofstream &stream, container &con, t_type but) {
    element *el = con.starting;
    int count1 = 0;
    for(int i = 0; i < con.size; i++) {
        if(el->t->tr_type != but) {
            count1++;
            stream << i+1 << ". ";
            OutTransport(stream, el->t);
        }
        el = el->forward;
    }
    return count1;
}

