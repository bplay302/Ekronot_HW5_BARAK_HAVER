#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(const Point& center, const double radius, const std::string& type, const std::string& name);

	// Getters
	Point getCenter() const;
	double getRadius() const;

	virtual double getArea() const override;
	virtual double getPerimeter() const override;
	virtual void move(Point other) override; // add the Point coordinates to all the points coordinates in the shape
	virtual void printDetails() const override;

	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;

private:
	Point _center;
	double _radios;
};