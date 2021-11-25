#ifndef ACORNEA_BOX_H
#define ACORNEA_BOX_H

#include <vector>
#include <variant>
#include <iostream>

struct dimension{
    int x;
    int y;
};

class Box{
private:
    dimension size;

    std::vector<std::variant<int, double, std::string>> content;

    struct PrintVisitor{
        template <class T>
        void operator()(T&& _in){std::cout << _in << '\n';}
    };

protected:
    template<class T>
    void addContent(T newContent){ content.push_back(newContent); }


public:
    Box(){}

    int getX(){ return size.x; }
    int getY(){ return size.y; }

    void setX(int _x){ size.x = _x; }
    void setY(int _y){ size.y = _y; }



public:
    virtual void unpack() = 0;

    void printContent() const{
        for (const auto& nextVar: content)
            std::visit(Box::PrintVisitor{}, nextVar);
    }
};

std::ostream& operator<<(std::ostream& os, const Box& bx);

#endif //ACORNEA_BOX_H
