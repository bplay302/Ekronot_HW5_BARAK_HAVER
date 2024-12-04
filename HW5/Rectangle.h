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

		// Destructor
		~Rectangle();

		// override methods if need (virtual + pure virtual)

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
}