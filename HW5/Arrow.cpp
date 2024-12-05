#include "Arrow.h"

 void Arrow::draw(const Canvas& canvas)
 {
 	canvas.draw_arrow(_points[0], _points[1]);
 }

 void Arrow::clearDraw(const Canvas& canvas)
 {
 	canvas.clear_arrow(_points[0], _points[1]);
 }

Arrow::Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name):
    Shape(name, type) 
{
    if (a.distance(b) != 0)
    {
        this->_points[0] = a;
        this->_points[1] = b;
    }
    else
    {
        std::cerr << "the 2 points that makes the arrow cannot be equal" << std::endl;
        exit(1);
    }
}

Point Arrow::getSource() const
{
    return this->_points[0];
}

Point Arrow::getDestination() const
{
    return this->_points[1];
}

double Arrow::getArea() const
{
    return 0.0;
}

double Arrow::getPerimeter() const
{
    return this->_points[0].distance(this->_points[1]);
}

void Arrow::move(Point other)
{
    this->_points[0] += other;
    this->_points[1] += other;
}

void Arrow::printDetails() const
{
    std::cout << this->_type << "  " << this->_name << "  " << this->getArea() << "  " << this->getPerimeter() << std::endl;    
}
