#include<iostream>
#include<string>
#include<vector>
#include "Products.h"
#include "Orders.h"
#include "Searching.h"
#include "Check.h"
#include "Global.h"

Product::Product() {
	ID = 0;
	amount = 0;
	price = 0;
}
std::string Product::Function_name() {
	return additional_function_name;
}
bool Product::Search(std::string term) {
	std::string amountS = std::to_string(amount);
	std::string priceS = std::to_string(price);
	if (amountS == term || priceS == term || name == term || Category() == term)
		return true;
	else
		return false;
}
void Product::Print() {
	std::cout << "Category: " << Category() << "\tName: " << name << "\tID: " << ID << "\tPrice: " << price << "\tAmound: " << amount << std::endl;
}
void Product::Add_products(int number) {
	amount += number;
	std::cout << "Products were replenished" << std::endl;
}


Groceries::Groceries(std::string name1, int amount1, float price1, int day1, int month1) {
	name = name1;
	ID = next_ID;
	next_ID++;
	amount = amount1;
	price = price1;
	additional_function_name = "Check if the product is expired";
	expiration_date_day = day1;
	expiration_date_month = month1;
}
std::string Groceries::Category() {
	return "groceries";
}
void Groceries::Additional() {
	int current_day, current_month;
	std::cout << "Enter the current date \n" << "day: ";
	current_day = string_to_int();
	if (current_day > 31) {
		std::cout << "The day must be between 1 and 31";
		return;
	}
	std::cout << "month: ";
	current_month = string_to_int();
	if (current_month > 12) {
		std::cout << "The month must be between 1 and 12";
		return;
	}
	if (current_month > expiration_date_month)
		std::cout << "The product has expired" << std::endl;
	if (current_month < expiration_date_month)
		std::cout << "The product hasn't expired" << std::endl;
	if (current_month == expiration_date_month) {
		if (current_day > expiration_date_day)
			std::cout << "The product has expired" << std::endl;
		if (current_day <= expiration_date_day)
			std::cout << "The product hasn't expired" << std::endl;
	}
}

Electronics::Electronics(std::string name1, int amount1, float price1, char energy_class1) {
	name = name1;
	ID = next_ID;
	next_ID++;
	amount = amount1;
	price = price1;
	additional_function_name = "Check the color of the energy class label";
	energy_class = energy_class1;
}
std::string Electronics::Category() {
	return "electronics";
}
void Electronics::Additional() {
	std::cout << "Color of the energy class label: ";
	if (energy_class == 'A')
		std::cout << "dark green" << std::endl;
	else if (energy_class == 'B')
		std::cout << "green" << std::endl;
	else if (energy_class == 'C')
		std::cout << "light green" << std::endl;
	else if (energy_class == 'D')
		std::cout << "yellow" << std::endl;
	else if (energy_class == 'E')
		std::cout << "light orange" << std::endl;
	else if (energy_class == 'F')
		std::cout << "orange" << std::endl;
	else if (energy_class == 'G')
		std::cout << "red" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

Clothes::Clothes(std::string name1, int amount1, float price1, std::string size1) {
	name = name1;
	ID = next_ID;
	next_ID++;
	amount = amount1;
	price = price1;
	additional_function_name = "Check the size";
	size = size1;
}
std::string Clothes::Category() {
	return "clothes";
}
void Clothes::Additional() {
	std::cout << size;
}


Cosmetics::Cosmetics(std::string name1, int amount1, float price1, std::string designed1) {
	name = name1;
	ID = next_ID;
	next_ID++;
	amount = amount1;
	price = price1;
	additional_function_name = "Check designed";
	designed = designed1;
}
std::string Cosmetics::Category() {
	return "cosmetics";
}
void Cosmetics::Additional() {
	std::cout << "Product designed for " << designed << std::endl;
}

Chemistry::Chemistry(std::string name1, int amount1, float price1, std::string GHS1) {
	name = name1;
	ID = next_ID;
	next_ID++;
	amount = amount1;
	price = price1;
	additional_function_name = "Check the danger";
	GHS = GHS1;
}
std::string Chemistry::Category() {
	return "home_Chemistry";
}
void Chemistry::Additional() {
	std::cout << "Denger: ";
	if (GHS == "GHS 01 CLP")
		std::cout << "explosive product" << std::endl;
	else if (GHS == "GHS 02 CLP")
		std::cout << "flammable product" << std::endl;
	else if (GHS == "GHS 03 CLP")
		std::cout << "oxidizing product" << std::endl;
	else if (GHS == "GHS 04 CLP")
		std::cout << "pressurized product" << std::endl;
	else if (GHS == "GHS 05 CLP")
		std::cout << "corrosive product" << std::endl;
	else if (GHS == "GHS 06 CLP")
		std::cout << "very toxic product" << std::endl;
	else if (GHS == "GHS 07 CLP")
		std::cout << "health-threatening product" << std::endl;
	else if (GHS == "GHS 08 CLP")
		std::cout << "product that poses a serious threat to health" << std::endl;
	else if (GHS == "GHS 09 CLP")
		std::cout << "dangerous product for the environment" << std::endl;
	else
		std::cout << "missing or unknown" << std::endl;
}