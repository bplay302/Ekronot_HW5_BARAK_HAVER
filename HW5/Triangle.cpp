#include "Triangle.h"

void Triangle::draw(const Canvas& canvas)
{
    canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
 	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}

Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) :
    Polygon(type, name)
{
    double ab = a.distance(b);
    double ac = a.distance(c);
    double cb = c.distance(b);

    if (ab + ac > cb &&
        ab + cb > ac &&
        ac + cb > ab)
    {
        this->_points.resize(3);
        this->_points[0] = a;
        this->_points[1] = b;
        this->_points[2] = c;
    }
    else
    {
        std::cerr << "three points dont form a triangle" << std::endl;
        exit(1);
    }
}

double Triangle::getArea() const
{
    double ab = this->_points[0].distance(this->_points[1]);
    double ac = this->_points[0].distance(this->_points[2]);
    double bc = this->_points[1].distance(this->_points[2]);
    double s = (ab + bc + ac) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}

double Triangle::getPerimeter() const
{
    double ab = this->_points[0].distance(this->_points[1]);
    double ac = this->_points[0].distance(this->_points[2]);
    double bc = this->_points[1].distance(this->_points[2]);
    return ab + bc + ac;
}

void Triangle::move(Point other)
{
    for (int i = 0; i < 3; i++)
    {
        this->_points[i] += other;
    }
}
