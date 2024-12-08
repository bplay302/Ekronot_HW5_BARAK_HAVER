#include "Menu.h"

Menu::~Menu()
{
	this->clearShapes();
}

void Menu::addShape()
{
	Shape* shape = nullptr;
	bool validChoice = false;
	unsigned int choice = CIRCLE;

	while (!validChoice)
	{
		system("cls");
		validChoice = true;
		Menu::printAddMenu();
		std::cin >> choice;

		switch (choice)
		{
			case CIRCLE:
				shape = getCircleData();
				break;
			case ARROW:
				shape = getArrowData();
				break;
			case TRIANGLE:
				shape = getTriangleData();
				break;
			case RECTANGLE:
				shape = getRectangleData();
				break;
			default:
				validChoice = false;
		}
	}

	_shapes.push_back(shape);
	shape->draw(this->_canvas);
}

void Menu::getShapesInfoAndData()
{
	bool validChoice = false;
	unsigned int index = 0;
	unsigned int choice = DETAILS;

	if (!this->_shapes.empty())
	{
		//get shape to edit
		do
		{
			system("cls");
			Menu::printShapesMenu();
			std::cin >> index;
		} while (index >= this->_shapes.size());

		while (!validChoice)
		{
			system("cls");
			validChoice = true;
			double x = 0, y = 0;

			Menu::printShapeEditOptions();
			std::cin >> choice;

			switch (choice)
			{
			case MOVE: //move the shape by x amount on the x axis and y amount on the y axis
				std::cout << "Please enter the X moving scale:" << std::endl;
				std::cin >> x;
				std::cout << "Please enter the Y moving scale:" << std::endl;
				std::cin >> y;
				this->_shapes[index]->clearDraw(this->_canvas);
				this->_shapes[index]->move(Point(x, y));
				this->_shapes[index]->draw(this->_canvas);
				break;
			case DETAILS:
				this->_shapes[index]->printDetails();
				break;
			case REMOVE:
				this->removeShape(index);
				break;
			default:
				validChoice = false;
			}
		}
	}
}

void Menu::clearShapes()
{
	unsigned int shapesCount = this->_shapes.size();
	for (int i = 0; i < shapesCount; i++)
	{
		//like pop first but i also clear the shape from the screen
		this->removeShape(0);
	}
}

Arrow* Menu::getArrowData() const
{
	double x = 0, y = 0;
	std::string name;
	Point arrowPoints[2] = {};
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Enter the X of point number: " << i + 1 << std::endl;
		std::cin >> x;
		std::cout << "Enter the Y of point number: " << i + 1<< std::endl;
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
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Enter the X of point number: " << i + 1 << std::endl;
		std::cin >> x;
		std::cout << "Enter the Y of point number: " << i + 1 << std::endl;
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

void Menu::printShapesMenu() const
{
	for (int i = 0; i < this->_shapes.size(); i++)
	{
		std::cout << "Enter " << i << " for " << this->_shapes[i]->getType() << '(' << this->_shapes[i]->getName() << ')' << std::endl;
	}
}

void Menu::printShapeEditOptions()
{
	std::cout << "Enter 0 to move the shape\n" <<
		"Enter 1 to get its details.\n" <<
		"Enter 2 to remove the shape." << std::endl;
}

void Menu::removeShape(const unsigned int index)
{
	this->_shapes[index]->clearDraw(this->_canvas);
	this->_shapes.erase(this->_shapes.begin() + index);
}

void Menu::printGeneralMenu()
{
	std::cout << "Enter 0 to add a new shape\n" <<
		"Enter 1 to modify or get information from a current shape.\n" <<
		"Enter 2 to delete all of the shapes.\n" <<
		"Enter 3 to exit." << std::endl;
}
