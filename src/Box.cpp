#include "../include/Box.h"

using namespace std;

ostream& operator<<(ostream& os, const Box& bx){
    bx.printContent();
    return os;
}


