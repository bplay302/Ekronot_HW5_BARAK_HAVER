#include "Shape.h"

std::string Shape::getType() const
{
    return this->_type;
}

std::string Shape::getName() const
{
    return this->_name;
}

Shape::Shape(std::string name, std::string type) : _name(name), _type(type)
{
}
