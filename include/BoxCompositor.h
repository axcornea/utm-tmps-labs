#ifndef ACORNEA_BOXCOMPOSITOR_H
#define ACORNEA_BOXCOMPOSITOR_H

#include "CompositeBox.h"

#define ELEM_LEN 8
#define MAX_BOX 3
#define MAX_ELEM 4

class BoxCompositor {
private:
    std::string elemPool[ELEM_LEN] = {"Sock","PlayStation", "BruhBurger", "Burger", "Loli License", "Java developer", "Number 9", "Ace of Spades"};

    std::string generateElement() {
        return elemPool[rand()%ELEM_LEN];
    }

    CompositeBox generateBox() {
        CompositeBox result;

        int boxLen = rand()%MAX_BOX,
            elemLen = rand()%MAX_ELEM+1;

        while(boxLen--){
            result.addBox(generateBox());
        }
        while(elemLen--){
            result.addElement(generateElement());
        }

        return result;
    }
public:
    BoxCompositor(){}

    CompositeBox generateRandomComposedBox() {
        return generateBox();
    }
};

#endif //ACORNEA_BOXCOMPOSITOR_H
