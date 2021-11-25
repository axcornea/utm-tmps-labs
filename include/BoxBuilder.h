#ifndef ACORNEA_BOXBUILDER_H
#define ACORNEA_BOXBUILDER_H

#include "CustomBox.h"

class BoxBuilder{
private:
    virtual void addComponent(std::string) = 0;

public:
    virtual ~BoxBuilder() {}

    virtual BoxBuilder *addGift() = 0;
    virtual BoxBuilder *addFood() = 0;
    virtual BoxBuilder *addShoe() = 0;

    virtual CustomBox build() = 0;
};

class BoxBuilderGeneric: public BoxBuilder{
private:
    CustomBox *product;

    void addComponent(std::string _e) override {
        product->addElement(_e);
    }

public:
    void Reset() {
        product = new CustomBox();
    }

    BoxBuilderGeneric() {
        Reset();
    }

    ~BoxBuilderGeneric() {
        delete product;
    }

    BoxBuilder *addGift() override {
        addComponent("Random gift");
        return this;
    }
    BoxBuilder *addFood() override {
        addComponent("Random food");
        return this;
    }

    BoxBuilder *addShoe() override {
        addComponent("Random shoe");
        return this;
    }

    CustomBox build() override{
        CustomBox result = *product;
        Reset();
        return result;
    }
};

class BoxDirector {
private:
    BoxBuilder *builder;

public:
    BoxDirector(BoxBuilder *_newBuilder): builder(_newBuilder) {}

    void setBuilder(BoxBuilder *_newBuilder) {
        builder = _newBuilder;
    }

    void buildSimpleBox() {
        builder->addFood();
    }

    void buildComplexBox() {
        builder->addFood()->addGift()->addShoe();
    }
};

#endif //ACORNEA_BOXBUILDER_H
