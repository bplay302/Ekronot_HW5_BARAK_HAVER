#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	~Polygon();

	// Getters
	std::vector<Point> getPoints();

	// override methods if need (virtual + pure virtual)

protected:
	std::vector<Point> _points;
};