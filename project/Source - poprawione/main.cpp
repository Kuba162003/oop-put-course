#include<iostream>
#include<vector>
#include<string>
#include "Products.h"
#include "Orders.h"
#include "Searching.h"
#include "Check.h"

Search_engine search_engine;

int main() {
	Groceries milk("milk", 40, 4.50, 23, 8);
	search_engine.Add(&milk);
	Groceries bread("bread", 20, 5.20, 29, 6);
	search_engine.Add(&bread);
	Groceries butter("butter", 10, 5.99, 4, 7);
	search_engine.Add(&butter);
	Groceries cheese("cheese", 50, 4.90, 20, 6);
	search_engine.Add(&cheese);
	Groceries sausage("sausage", 20, 8.40, 15, 6);
	search_engine.Add(&sausage);
	Groceries jam("jam", 40, 3.90, 6, 9);
	search_engine.Add(&jam);
	Electronics television("television", 5, 2000, 'F');
	search_engine.Add(&television);
	Electronics fridge("fridge", 5, 1500, 'C');
	search_engine.Add(&fridge);
	Electronics oven("oven", 3, 899.99, 'D');
	search_engine.Add(&oven);
	Clothes jacket("jecket", 15, 159, "M");
	search_engine.Add(&jacket);
	Clothes dress("dress", 15, 89, "S");
	search_engine.Add(&dress);
	Clothes trousers("trousers", 10, 109.99, "XL");
	search_engine.Add(&trousers);
	Clothes t_shirt("t-shirt", 50, 39.99, "L");
	search_engine.Add(&t_shirt);
	Cosmetics soap("soap", 70, 1.29, "everyone");
	search_engine.Add(&soap);
	Cosmetics shampoo("shampoo", 70, 8.99, "women");
	search_engine.Add(&shampoo);
	Cosmetics cream("cream", 15, 19.90, "men");
	search_engine.Add(&cream);
	Cosmetics olive("olive", 30, 6.99, "children");
	search_engine.Add(&olive);
	Chemistry detergent("detergent", 24, 39, "GHS 07 CLP");
	search_engine.Add(&detergent);
	Chemistry pipe_cleaner("pipe_cleaner", 12, 12.90, "GHS 05 CLP");
	search_engine.Add(&pipe_cleaner);
	Chemistry hair_spray("hair_spray", 12, 7.50, "GHS 04 CLP");
	search_engine.Add(&hair_spray);

	int option;
	int option2;
	int option3;
	int selected = 1;
	std::string term;
	std::vector<Product*> product_list;
	int add_number;
	std::string designed;

	std::vector<Order*> order_list;
	std::string customer_name;
	std::vector<Product*> order_product;
	std::string order_add;
	int order_amount;

	std::string category;
	std::string name;
	int amount;
	float price;
	int day;
	int month;
	char energy_class;
	std::string size;
	std::string denger;

	for (int i = 0;; i++) {
		std::cout << "Choose an option number from: \n1. Search for a product\n2. Show all products\n3. Add product\n4. Open order list\n5. Add order\n6. End the program" << std::endl;
		std::cout << "Option: ";
		option = string_to_int();
		system("cls");
		switch (option) {
		case 1:
			std::cout << "Enter a term: ";
			std::cin >> term;
		case1:
			product_list.clear();
			product_list = search_engine.Search(term);
			if (product_list.size() != 0) {
				std::cout << "Select product number to action: ";
				selected = string_to_int();
				if (selected <= product_list.size()) {
					std::cout << "Choose an option from: \n1. Replenish products\t2. Delete product\t3." << product_list[selected - 1]->Function_name() << "\t4. Back\nOption: ";
					option2 = string_to_int();
					switch (option2) {
					case 1:
						std::cout << "How meny: ";
						add_number = string_to_int();
						product_list[selected - 1]->Add_products(add_number);
						break;
					case 2:
						search_engine.Delete(product_list[selected - 1]);
						break;
					case 3:
						product_list[selected - 1]->Additional();
						break;
					case 4:
						;
						break;
					default:
						;
						break;
					}
					std::cout << std::endl;
				}
				else {
					std::cout << "There is no product with this number" << std::endl;
				}
			}
			else
				std::cout << "Product not found" << std::endl;
			std::cout << "Select:\t1. Back to product list\t2. Back to menu\nOption: ";
			option3 = string_to_int();
			switch (option3) {
			case 1:
				system("cls");
				goto case1;
				break;
			case 2:
				;
				break;
			default:
				;
				break;
			}
			break;
		case 2:
		case2:
			product_list.clear();
			product_list = search_engine.Show_all();
			if (product_list.size() != 0) {
				std::cout << "Select product to action: ";
				selected = string_to_int();
				if (selected <= product_list.size()) {
					std::cout << "Choose an option from: \n1. Replenish products \t2. Delete product \t3." << product_list[selected - 1]->Function_name() << "\t 4. Back\nOption: ";
					option2 = string_to_int();
					switch (option2) {
					case 1:
						std::cout << "How meny: ";
						add_number = string_to_int();
						product_list[selected - 1]->Add_products(add_number);
						break;
					case 2:
						search_engine.Delete(product_list[selected - 1]);
						break;
					case 3:
						product_list[selected - 1]->Additional();
						break;
					case 4:
						;
						break;
					default:
						;
						break;
					}
				}
				else {
					std::cout << "There is no product with this number" << std::endl;
				}
			}
			else
				std::cout << "You have no products";
			std::cout << "Select:\t1. Back to product list\t2. Back to menu\nOption: ";
			option3 = string_to_int();
			switch (option3) {
			case 1:
				system("cls");
				goto case2;
				break;
			case 2:
				;
				break;
			default:
				;
				break;
			}
			break;
		case 3:
		case3:
			std::cout << "Enter a category (groceries, electronics, clothes, cosmetics or home_Chemistry): ";
			std::cin >> category;
			std::cout << "Enter a name: ";
			std::cin >> name;
			std::cout << "Enter an amount: ";
			amount = string_to_int();
			std::cout << "Enter a price: ";
			price = string_to_float();
			if (category == "groceries") {
				std::cout << "Enter a expiration date - day: ";
				day = string_to_int();
				std::cout << "Enter a expiration date - month: ";
				month = string_to_int();
				Product* added = new Groceries(name, amount, price, day, month);
				search_engine.Add(added);
				std::cout << "Product created" << std::endl;
			}
			else if (category == "electronics") {
				std::cout << "Enter a energy class: ";
				std::cin >> energy_class;
				Product* added = new Electronics(name, amount, price, energy_class);
				search_engine.Add(added);
				std::cout << "Product created" << std::endl;
			}
			else if (category == "clothes") {
				std::cout << "Enter a size: ";
				size = string_to_float();
				Product* added = new Clothes(name, amount, price, size);
				search_engine.Add(added);
				std::cout << "Product created" << std::endl;
			}
			else if (category == "cosmetics") {
				std::cout << "For whom the product is drsigned: ";
				std::cin >> designed;
				Product* added = new Cosmetics(name, amount, price, designed);
				search_engine.Add(added);
				std::cout << "Product created" << std::endl;
			}
			else if (category == "home_Chemistry") {
				std::cout << "Enter denger designation: ";
				std::cin >> denger;
				Product* added = new Chemistry(name, amount, price, denger);
				search_engine.Add(added);
				std::cout << "Product created" << std::endl;
			}
			else {
				std::cout << "You entered the wrong category, the product was not created" << std::endl;
			}
			std::cout << "Select:\t1. add another product\t2. Back to menu\nOption: ";
			option3 = string_to_int();
			switch (option3) {
			case 1:
				system("cls");
				goto case3;
				break;
			case 2:
				;
				break;
			default:
				;
				break;
			}
			break;
		case 4:
		case4:
			if (order_list.size() != 0) {
				int j = 0;
				while (j < order_list.size()) {
					std::cout << j + 1 << ". Order for " << order_list[j]->Client_name() << ":" << std::endl;
					order_list[j]->Show();
					std::cout << std::endl << std::endl;
					j++;
				}
				std::cout << "Select order number to action: ";
				selected = string_to_int();
				if (selected <= order_list.size() && selected > 0) {
					std::cout << "Choose an option from: \t1. Complete the order \t2. Cancel the order \t3. Back\nOption: ";
					option2 = string_to_int();
					switch (option2) {
					case 1:
						order_list.erase(order_list.begin() + selected - 1);
						std::cout << "Order completed" << std::endl;
						break;
					case 2:
						order_list[selected - 1]->Cancel();
						order_list.erase(order_list.begin() + selected - 1);
						std::cout << "Order canceled" << std::endl;
						break;
					case 3:
						;
						break;
					default:
						;
						break;
					}
				}
				else
					std::cout << "There is no order with this number" << std::endl;
			}
			else
				std::cout << "You have no orders" << std::endl;
			std::cout << "Select:\t1. Back to order list\t2. Back to menu\nOption: ";
			option3 = string_to_int();
			switch (option3) {
			case 1:
				system("cls");
				goto case4;
				break;
			case 2:
				;
				break;
			default:
				;
				break;
			}
			break;
		case 5:
			std::cout << "Enter the customer's name: ";
			std::cin >> customer_name;
			if (true) {
				Order* new_order = new Order(customer_name);
				order_list.push_back(new_order);
				for (int i = 0;; i++) {
					std::cout << "Enter the name of the product to add (if you want to stop adding, type stop): ";
					std::cin >> order_add;
					order_product.clear();
					order_product = search_engine.Search(order_add);
					if (order_add == "stop") {
						break;
					}
					if (order_add != "stop" && order_product.size() != 0) {
						std::cout << "Enter amount: ";
						order_amount = string_to_int();
						new_order->Add(order_product[0], order_amount);
					}
					else {
						std::cout << "Product not found" << std::endl;
					}
				}
			}
			break;
		case 6:
			return 0;
		default:
			std::cout << "You entered the wrong option";
			break;
		}
		system("cls");
	}
}