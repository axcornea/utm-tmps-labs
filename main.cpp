#include <iostream>
#include <thread>
#include <chrono>

#include "include/BoxFacility.h"

#define VAR_LEN 3
#define TRY_LIMIT 50

int main() {
    srand(time(NULL));

    int tries = 0;
    while(true){
        BoxType variants[VAR_LEN] = {BoxType::prebuilt, BoxType::custom, BoxType::composite};
        BoxType currentVariant = variants[rand()%VAR_LEN];

        BoxFacility::getInstance()->generateBox(currentVariant);

        std::this_thread::sleep_for(std::chrono::seconds(1));
        tries++;
        if(tries>=TRY_LIMIT)
            break;
    }

    return 0;
}
