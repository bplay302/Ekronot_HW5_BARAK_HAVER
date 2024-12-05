#include "Shape.h"

std::string Shape::getType() const
{
    return this->_type;
}

std::string Shape::getName() const
{
    return this->_name;
}

void Shape::printDetails() const
{
    std::cout << this->_type << "  " << this->_name << "  " << this->getArea() << "  " << this->getPerimeter() << std::endl;
}

Shape::Shape(std::string name, std::string type) : _name(name), _type(type)
{
}
