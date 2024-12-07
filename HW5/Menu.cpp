#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	for (int i = 0; i < this->_shapes.size();i++)
	{
		delete this->_shapes[i];
	}
}

void Menu::addShape()
{
	bool validChoice = false;
	unsigned int choice = CIRCLE;
	printAddMenu();
	std::cin >> choice;

	while (!validChoice)
	{
		validChoice = true;
		switch (choice)
		{
			case CIRCLE:
				_shapes.push_back(getCircleData());
				break;
			case ARROW:
				_shapes.push_back(getArrowData());
				break;
			case TRIANGLE:
				_shapes.push_back(getTriangleData());
				break;
			case RECTANGLE:
				_shapes.push_back(getRectangleData());
				break;
			default:
				validChoice = false;
		}
	}
}

Arrow* Menu::getArrowData() const
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
	}

	std::cout << "Enter the name of the shape:" << std::endl;
	std::cin >> name;

	return new Arrow(arrowPoints[0], arrowPoints[1], "Arrow", name);
}

Circle* Menu::getCircleData() const
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

	return new Circle(Point(x, y), radius, "Circle", name);
}

Triangle* Menu::getTriangleData() const
{
	double x = 0, y = 0;
	std::string name;
	Point trianglePoints[3] = {};
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Enter the X of point number: " << i << std::endl;
		std::cin >> x;
		std::cout << "Enter the Y of point number: " << i << std::endl;
		std::cin >> y;
		trianglePoints[i] = Point(x, y);
	}

	std::cout << "Enter the name of the shape:" << std::endl;
	std::cin >> name;

	return new Triangle(trianglePoints[0], trianglePoints[1], trianglePoints[2], "Triangle", name);
}

myShapes::Rectangle* Menu::getRectangleData() const
{
	double x = 0, y = 0, width = 0, length = 0;
	std::string name;
	std::cout << "Enter the X of the to left corner:" << std::endl;
	std::cin >> x;
	std::cout << "Enter the Y of the to left corner:" << std::endl;
	std::cin >> y;
	std::cout << "Please enter the length of the shape:" << std::endl;
	std::cin >> length;
	std::cout << "Please enter the width of the shape:" << std::endl;
	std::cin >> width;
	std::cout << "Enter the name of the shape:" << std::endl;
	std::cin >> name;

	return new myShapes::Rectangle(Point(x, y), length, width, "Rectangle", name);
}

void Menu::printAddMenu()
{
	std::cout << "Enter 0 to add a circle.\n" <<
		"Enter 1 to add an arrow.\n" <<
		"Enter 2 to add a triangle.\n" <<
		"Enter 3 to add a rectangle." << std::endl;
}

void Menu::printGeneralMenu()
{
	std::cout << "Enter 0 to add a new shape\n" <<
		"Enter 1 to modify or get information from a current shape.\n" <<
		"Enter 2 to delete all of the shapes.\n" <<
		"Enter 3 to exit." << std::endl;
}
