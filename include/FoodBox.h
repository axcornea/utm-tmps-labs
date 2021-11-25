#ifndef ACORNEA_FOODBOX_Hcourses
#define ACORNEA_FOODBOX_H

#include "Box.h"

class FoodBox : public Box {
public:
    FoodBox(std::string food) {
        addContent(food);
    }

    void unpack() {
        std::cout << "Eating from food box:\n"; printContent();
    }
};

#endif //ACORNEA_FOODBOX_H
