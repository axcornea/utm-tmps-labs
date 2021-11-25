#ifndef ACORNEA_CUSTOMBOX_H
#define ACORNEA_CUSTOMBOX_H

#include "Box.h"

class CustomBox : public Box {
public:
    CustomBox() {}

    void unpack() {
        std::cout << "Unpacking custom box:\n"; printContent();
    }

    template<typename T>
    void addElement(T item){
        addContent(item);
    }
};

#endif //ACORNEA_CUSTOMBOX_H
