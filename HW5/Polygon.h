#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(const std::string& type, const std::string& name);

	// Getters
	std::vector<Point> getPoints() const;


protected:
	std::vector<Point> _points;
};