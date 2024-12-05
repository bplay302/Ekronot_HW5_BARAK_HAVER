#include "Polygon.h"

Polygon::Polygon(const std::string& type, const std::string& name) :
	Shape(name, type)
{
}

std::vector<Point> Polygon::getPoints() const
{
	return this->_points;
}
