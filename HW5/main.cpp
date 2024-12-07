#include "Menu.h"

void main()
{
	bool running = true;
	Menu menu;
	unsigned int choice = EXIT;

	do
	{
		system("cls");
		Menu::printGeneralMenu();

		std::cin >> choice;
		switch (choice)
		{
			case ADD_SHAPE:
				menu.addShape();
				break;
			case SHAPE_INFO_AND_DATA:
				menu.getShapesInfoAndData();
				break;
			case DELETE_ALL_SHAPES:
				menu.clearShapes();
				break;
			case EXIT:
				running = false;
				break;
		}
	} while (running);
}