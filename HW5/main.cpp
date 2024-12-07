#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Arrow.h"
#include "Canvas.h"

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

void printGeneralMenu();
void printAddMenu();
void addShape(std::vector<Shape*>& shapes);
Circle getCircleData();
Arrow getArrowData();

void main()
{
	bool running = true;
	Canvas canvas;
	std::vector<Shape*> shapes;
	unsigned int choice = EXIT;

	do
	{
		printGeneralMenu();

		std::cin >> choice;
		switch (choice)
		{
			case ADD_SHAPE:
				addShape(shapes);
				break;
			case DELETE_ALL_SHAPES:
				shapes.clear();
				break;
			case EXIT:
				running = false;
				break;
		}
	} while (running);
}

void addShape(std::vector<Shape*>& shapes)
{
	unsigned int choice = CIRCLE;
	printAddMenu();
	std::cin >> choice;
	switch (choice)
	{
		case CIRCLE:
			shapes.push_back(&getCircleData());
			break;
		case ARROW:
			shapes.push_back(&getArrowData());
			break;
	}
}

Arrow getArrowData()
{
	double x = 0, y = 0;
	std::string name;
	Point arrowPoints[2] = {};
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Enter the X of point number: " << i << std::endl;
		std::cin >> x;
		std::cout << "Enter the Y of point number: " << i << std::endl;
		std::cin >> y;
		arrowPoints[i] = Point(x, y);
		std::cout << "Enter the name of the shape:" << std::endl;
		std::cin >> name;
	}

	return Arrow(arrowPoints[0], arrowPoints[1], "Arrow", name);
}

Circle getCircleData()
{
	double x = 0, y = 0, radius = 0;
	std::string name;
	std::cout << "Please enter X:" << std::endl;
	std::cin >> x;
	std::cout << "Please enter Y:" << std::endl;
	std::cin >> y;
	std::cout << "Please enter radius:" << std::endl;
	std::cin >> radius;
	std::cout << "Enter the name of the shape:" << std::endl;
	std::cin >> name;

	return Circle(Point(x, y), radius, "Triangle", name);
}

void printAddMenu()
{
	std::cout << "Enter 0 to add a circle.\n" <<
		"Enter 1 to add an arrow.\n" <<
		"Enter 2 to add a triangle.\n" <<
		"Enter 3 to add a rectangle." << std::endl;
}

void printGeneralMenu()
{
	std::cout << "Enter 0 to add a new shape\n" <<
		"Enter 1 to modify or get information from a current shape.\n" <<
		"Enter 2 to delete all of the shapes.\n" <<
		"Enter 3 to exit." << std::endl;
}
