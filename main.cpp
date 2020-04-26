
// Вариант 4 - 3 - 2 - 1
// Контейнер на основе однонаправленного кольцевого списка.
// Разбиение на модули осуществляется по объектному принципу.
// Обобщение, построенное на основе непосредственного включения специализаций.

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc !=3) {
        cout << "incorrect command line! " << endl
             << "Waited: command in_file out_file"
             << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "START"<< endl;
     c{};
    In(c, ifst);
    Out(c, ofst);
    Clear(c);
    cout << "END"<< endl;
    return 0;
}