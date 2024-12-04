#pragma once
#include "Point.h"

// Uncomment when you want to draw on Canvas and run it locally on windows
// #include "Canvas.h" 
#include <string>

class Shape 
{
public:

	// Constructor
	Shape(std::string name, std::string type);

	// Destructor
	~Shape();

	// Getters
	std::string getType();
	std::string getName();

	// Methods
	double getArea();
	double getPerimeter();
	void move(Point other); // add the Point coordinates to all the points coordinates in the shape
	void printDetails() ;

	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	// virtual void draw(const Canvas& canvas) = 0;
	// virtual void clearDraw(const Canvas& canvas) = 0;

private:
	std::string _name;
	std::string _type;
};