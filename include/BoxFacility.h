#ifndef ACORNEA_BOXFACILITY_H
#define ACORNEA_BOXFACILITY_H

#include "Box.h"
#include "BoxFactory.h"
#include "BoxBuilder.h"
#include "BoxCompositor.h"

enum class BoxType {
    prebuilt,
    custom,
    composite,
};

class BoxFacility{
private:
    BoxFacility(){}

    BoxFactory factory;
    BoxBuilder *builder;
    BoxDirector *director;
    BoxCompositor *compositor;

public:
    BoxFacility(BoxFacility const &) = delete;
    void operator=(BoxFacility const &) = delete;

    static BoxFacility *getInstance() {
        static BoxFacility it;
        return &it;
    }

    void generateBox(BoxType type) {
        Box *resultBox;

        switch (type) {
            case BoxType::prebuilt: resultBox = randomPrebuilt(); break;
            case BoxType::custom: resultBox = randomCustom(); break;
            case BoxType::composite: resultBox = randomComposite(); break;
        }

        if(resultBox != nullptr){
            resultBox->unpack();
            delete resultBox;
        }else{
            std::cout << "Something went wrong!\n";
        }

        std::cout << std::flush;
    }

    Box* randomPrebuilt() {
        int variant = rand()%3;

        switch (variant) {
            case 0:
                return factory.produce(BoxPrebuildType::ShoeBox, "Gucci");
            case 1:
                return factory.produce(BoxPrebuildType::PresentBox, "PlayStation 5");
            case 2:
                return factory.produce(BoxPrebuildType::FoodBox, "Lasagna");
            default:
                return nullptr;
        }
    }

    Box* randomCustom() {
        builder = new BoxBuilderGeneric();
        director = new BoxDirector(builder);

        director->buildComplexBox();


        return new CustomBox(builder->build());
    }

    Box* randomComposite() {
        compositor = new BoxCompositor();

        return new CompositeBox(compositor->generateRandomComposedBox());
    }
};

#endif //ACORNEA_BOXFACILITY_H
