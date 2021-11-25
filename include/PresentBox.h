#ifndef ACORNEA_PRESENTBOX_H
#define ACORNEA_PRESENTBOX_H

#include "Box.h"

class PresentBox : public Box {
private:

public:
    PresentBox(std::string present){
        addContent(present);
    }

    void unpack() {
        std::cout << "Unpacking a present:\n"; printContent();
    }
};

#endif //ACORNEA_PRESENTBOX_H
