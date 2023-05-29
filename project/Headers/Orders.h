#pragma once
#include<iostream>
#include<vector>
#include<string>

class Order {
private:
	std::string client_name;
	std::vector <Product*> product;
	std::vector<int> product_amount;
	int amount_of_products;
	float order_price;
	int number_to_Show;
public:
	Order(std::string name);
	void Add(Product* new_product, int amount);
	void Cancel();
	void Show();
	std::string Client_name();
};
