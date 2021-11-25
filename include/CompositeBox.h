#ifndef ACORNEA_COMPOSITEBOX_H
#define ACORNEA_COMPOSITEBOX_H

#include "Box.h"

class CompositeBox : public Box {
public:
    CompositeBox() {}
    std::vector<CompositeBox> innerBox;

    void unpack() {
        std::cout << "Unpacking composite box:\n"; printContent();
        std::cout << "And inner box:\n";

        for(auto box: innerBox){
            box.printContent();
        }
    }

    template<typename T>
    void addElement(T item){
        addContent(item);
    }

    void addBox(CompositeBox newBox){
        innerBox.push_back(newBox);
    }
};

#endif //ACORNEA_COMPOSITEBOX_H
