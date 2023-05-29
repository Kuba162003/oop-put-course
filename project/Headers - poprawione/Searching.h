#pragma once
#include<iostream>
#include<vector>
#include<string>

class Search_engine {
private:
	std::vector<Product*> product;
	std::vector<Product*> found_products;
	int number_of_products = 0;
public:
	void Add(Product* product1);
	void Delete(Product* product1);
	std::vector<Product*> Search(std::string term);
	std::vector<Product*> Show_all();
};