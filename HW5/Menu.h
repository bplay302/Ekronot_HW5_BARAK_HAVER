#pragma once
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Arrow.h"
#include "Canvas.h"
#include <vector>


enum OptionChoice
{
	ADD_SHAPE,
	SHAPE_INFO_AND_DATA,
	DELETE_ALL_SHAPES,
	EXIT
};

enum ShapeOption
{
	CIRCLE,
	ARROW,
	TRIANGLE,
	RECTANGLE
};

class Menu
{
public:

	Menu();
	~Menu();

	void addShape();
	static void printGeneralMenu();

private:
	Arrow* getArrowData() const;
	Circle* getCircleData() const;
	Triangle* getTriangleData() const;
	myShapes::Rectangle* getRectangleData() const;

	static void printAddMenu();

private: 
	Canvas _canvas;
	std::vector<Shape*> _shapes;
};

