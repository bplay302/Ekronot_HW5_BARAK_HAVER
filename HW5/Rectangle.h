#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class Rectangle : public Polygon
	{
	public:

		// Constructor
		// There's a need only for the top left corner 
		Rectangle(Point a, double length, double width, std::string type, std::string name);

		virtual double getArea() const override;
		virtual double getPerimeter() const override;
		virtual void move(Point other) override; // add the Point coordinates to all the points coordinates in the shape

		virtual void draw(const Canvas& canvas) override;
		virtual void clearDraw(const Canvas& canvas) override;
	};
}