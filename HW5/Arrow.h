#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	~Arrow();

	// Getters
	Point getSource();
	Point getDestination();

	// override functions if need (virtual + pure virtual)
	
	
	//////////////////////////////////////////////////////////////////////////////
	// Canvas and Cimg cannot be used on Linux, 								//
	// please make sure to leave it commented if you want test to run on GitLab //
	// You can remove comments when you run your exercise locally on Windows .  //
	//////////////////////////////////////////////////////////////////////////////

	// virtual void draw(const Canvas& canvas);
	// virtual void clearDraw(const Canvas& canvas);


private:

	// add fields if necessary
};