#include "Circle.h"

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
 	canvas.clear_circle(getCenter(), getRadius());
}

Circle::Circle(const Point& center, const double radius, const std::string& type, const std::string& name) :
	Shape(name, type), _center(center), _radius(radius)
{
	if (radius < 0)
	{
		std::cerr << "radius cannot be negetive" << std::endl;
		exit(1);
	}
	else
	{
		this->_radius = radius;
	}
}

Point Circle::getCenter() const
{
	return this->_center;
}

double Circle::getRadius() const
{
	return this->_radius;
}

double Circle::getArea() const
{
	return this->_radius * this->_radius * PI;
}

double Circle::getPerimeter() const
{
	return 2 * PI * this->_radius;
}

void Circle::move(Point other)
{
	this->_center += other;
}
