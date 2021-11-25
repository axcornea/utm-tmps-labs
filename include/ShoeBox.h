#ifndef ACORNEA_SHOEBOX_H
#define ACORNEA_SHOEBOX_H

#include "Box.h"

class ShoeBox : public Box {
public:
    ShoeBox(std::string shoes) {
        addContent(shoes);
    }

    void unpack() {
        std::cout << "Unpacking shoe box with:\n"; printContent();
    }
};

#endif //ACORNEA_SHOEBOX_H
