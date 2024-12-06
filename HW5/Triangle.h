#include "Polygon.h"
#include <string>

class Triangle : public Polygon
{
public:

	// Constructor
	Triangle(Point a, Point b, Point c, std::string type, std::string name);
		

	virtual double getArea() const override;
	virtual double getPerimeter() const override;
	virtual void move(Point other) override; // add the Point coordinates to all the points coordinates in the shape

	virtual void draw(const Canvas& canvas) override;
	virtual void clearDraw(const Canvas& canvas) override;
};