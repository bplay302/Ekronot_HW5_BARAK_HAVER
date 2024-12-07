#include "Rectangle.h"


void myShapes::Rectangle::draw(const Canvas& canvas)
{
    canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
    canvas.clear_rectangle(_points[0], _points[1]);
}

myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name):
    Polygon(type, name)
{
    if (width > 0 && length > 0)
    {
        this->_points.resize(4);
        this->_points[0] = a;
        this->_points[1] = a + Point(width, length);
        this->_points[2] = a + Point(0, length);
        this->_points[3] = a + Point(width, 0);
    }
    else
    {
        std::cerr << "width and length must be positive" << std::endl;
        exit(1);
    }
}

double myShapes::Rectangle::getArea() const
{
    return this->_points[0].distance(this->_points[2]) * this->_points[0].distance(this->_points[3]);
}

double myShapes::Rectangle::getPerimeter() const
{
    return this->_points[0].distance(this->_points[2]) * 2 + this->_points[0].distance(this->_points[3]) * 2;
}

void myShapes::Rectangle::move(Point other)
{
    for (int i = 0; i < 4; i++)
    {
        this->_points[i] += other;
    }
}