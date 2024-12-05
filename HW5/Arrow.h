#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name);


	// Getters
	Point getSource() const;
	Point getDestination() const;

	virtual double getArea() const override;
	virtual double getPerimeter() const override;
	virtual void move(Point other) override; // add the Point coordinates to all the points coordinates in the shape
	virtual void printDetails() const override;

	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;


private:
	Point _points[2];
};