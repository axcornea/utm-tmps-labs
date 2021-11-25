#ifndef ACORNEA_BOXFACTORY_H
#define ACORNEA_BOXFACTORY_H

#include "ShoeBox.h"
#include "PresentBox.h"
#include "FoodBox.h"

enum class BoxPrebuildType{
    ShoeBox,
    FoodBox,
    PresentBox
};

class BoxFactory{
private:

public:
    BoxFactory(){}

    Box* produce(BoxPrebuildType type, std::string data){
        switch (type) {
            case BoxPrebuildType::ShoeBox:
                return new ShoeBox(data);
            case BoxPrebuildType::FoodBox:
                return new FoodBox(data);
            case BoxPrebuildType::PresentBox:
                return new PresentBox(data);
            default:
                return nullptr;
        }
    }
};

#endif //ACORNEA_BOXFACTORY_H
