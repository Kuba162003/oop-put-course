#include<iostream>
#include<vector>
#include<string>
#include "Products.h"
#include "Orders.h"
#include "Searching.h"
#include "Check.h"

Order::Order(std::string name) {
	amount_of_products = 0;
	order_price = 0;
	number_to_Show = 0;
	client_name = name;
}
void Order::Add(Product* new_product, int amount) {
	if (amount <= new_product->amount) {
		product.push_back(new_product);
		product_amount.push_back(amount);
		amount_of_products += amount;
		order_price += new_product->price * amount;
		new_product->amount -= amount;
		number_to_Show++;
	}
	else
		std::cout << "Not enough products" << std::endl;
}
void Order::Cancel() {
	for (int i = 0; i < product.size(); i++) {
		product[i]->amount += product_amount[i];
	}
}
void Order::Show() {
	for (int i = 0; i < number_to_Show; i++) {
		std::cout << "Name: " << product[i]->name << "\tAmount: " << product_amount[i] << "\tPrice: " << product_amount[i] * product[i]->price << std::endl;
	}
	std::cout << "Total: " << order_price;
}
std::string Order::Client_name() {
	return client_name;
}