#include "Point.h"
#include <cmath>F

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const double x, const double y): _x(x), _y(y)
{
}

Point Point::operator+(const Point& other) const
{
	Point newPoint(other._x, other._y);

	newPoint._x += this->_x;
	newPoint._y += this->_y;

	return newPoint;
}

Point& Point::operator+=(const Point& other)
{
	this->_x += other._x;
	this->_y += other._y;

	return *this;
}

double Point::getX() const
{
	return this->_x;
}

double Point::getY() const
{
	return this->_y;
}

double Point::distance(const Point& other) const
{
	return sqrt(pow(this->_x - other._x, 2) + pow(this->_y - other._y, 2));
}
