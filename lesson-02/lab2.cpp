#include <iostream>
using namespace std;
class Desk {
public:
	float height;
	float width;
	int year_of_production;
	std::string material;
};


class Tree {
public:
	float height;
	int year;
	int number_of_leaves;
	std::string species;
};


class Lamp {
public:
	std::string housing_color;
	std::string light_color;
	std::string type;
	int power;
};

int main()
{
	Lamp Lamp;
	Tree Tree;
	Desk Desk;

	for (int i = 0;; i++) {
		int option;
	std:cout << "Choose thing to describe\n 1) Desk\n 2) Tree\n 3) Lamp\n 4) Exit the program and display the data\nOption: ";
		std::cin >> option;
		switch(option) {
			case 1:
				std::cout << "Enter height";
				std::cin >> Desk.height;
				std::cout << "Enter width";
				std::cin >> Desk.width;
				std::cout << "Enter year_of_production";
				std::cin >> Desk.year_of_production;
				std::cout << "Enter material";
				std::cin >> Desk.material;
				break;
			case 2:
				std::cout << "Enter height";
				std::cin >> Tree.height;
				std::cout << "Enter year";
				std::cin >> Tree.year;
				std::cout << "Enter number_of_leaves";
				std::cin >> Tree.number_of_leaves;
				std::cout << "Enter species";
				std::cin >> Tree.species;
				break;
			case 3:
				std::cout << "Enter housing_color";
				std::cin >> Lamp.housing_color;
				std::cout << "Enter light_color";
				std::cin >> Lamp.light_color;
				std::cout << "Enter type";
				std::cin >> Lamp.type;
				std::cout << "Enter power";
				std::cin >> Lamp.power;
				break;
			case 4:
				goto Exit;
				break;
		}
	}
Exit:
	std::cout << "Desk" << std::endl;
	std::cout << "Height: " << Desk.height << std::endl;
	std::cout << "Width: " << Desk.width << std::endl;
	std::cout << "Year_of_production: " << Desk.year_of_production << std::endl;
	std::cout << "Material: " << Desk.material << std::endl;

	std::cout << "Tree";
	std::cout << "Height" << Tree.height << std::endl;
	std::cout << "Year: " << Tree.year << std::endl;
	std::cout << "Number_of_leaves: " << Tree.number_of_leaves << std::endl;
	std::cout << "Species" << Tree.species << std::endl;

	std::cout << "Lamp";
	std::cout << "Housing_color" << Lamp.housing_color << std::endl;
	std::cout << "Light_color" << Lamp.light_color << std::endl;
	std::cout << "Ttype" << Lamp.type << std::endl;
	std::cout << "Power" << Lamp.power << std::endl;

	return 0;


}