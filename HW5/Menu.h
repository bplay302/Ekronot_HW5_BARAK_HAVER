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

enum ShapeEditOtion
{
	MOVE,
	DETAILS,
	REMOVE
};

class Menu
{
public:
	~Menu();

	/*
	* menu add shape option
	*/
	void addShape();

	/*
	* menu get info or chnge shape data option
	*/
	void getShapesInfoAndData();

	/*
	* clear oll shpes from screen, menu option
	*/
	void clearShapes();

	/*
	* print the general menu to the screen
	*/
	static void printGeneralMenu();

private:
	/*
	* create an arraow shape
	* return: a pointer to a new arrow
	*/
	Arrow* getArrowData() const;

	/*
	* create a ciecle shape
	* return: a pointer to a new circle
	*/
	Circle* getCircleData() const;

	/*
	* create a triangle shape
	* return: a pointer to a new triangle
	*/
	Triangle* getTriangleData() const;

	/*
	* create a rectangle shape 
	* return: a pointer to a new rectangle
	*/
	myShapes::Rectangle* getRectangleData() const;

	/*
	* print add shape options
	*/
	static void printAddMenu();

	/*
	* print the shapes in order
	*/
	void printShapesMenu() const;

	/*
	* print shape edir options
	*/
	static void printShapeEditOptions();

	/*
	* remove the shapes from the shpes vector and from screen
	* \param index of shape to remove 
	*/
	void removeShape(const unsigned int index);

private: 
	Canvas _canvas;
	std::vector<Shape*> _shapes;
};

