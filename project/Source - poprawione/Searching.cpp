#include<iostream>
#include<vector>
#include<string>
#include "Products.h"
#include "Orders.h"
#include "Searching.h"
#include "Check.h"

void Search_engine::Add(Product* product1) {
	product.push_back(product1);
	number_of_products++;
}
void Search_engine::Delete(Product* product1) {
	for (int i = 0; i < number_of_products; i++) {
		if (product[i] == product1) {
			product.erase(product.begin() + i);
			break;
		}
	}
	number_of_products--;
	std::cout << "Product deleted" << std::endl;
}
std::vector<Product*> Search_engine::Search(std::string term) {
	found_products.clear();
	for (int i = 0; i < number_of_products; i++) {
		if (product[i]->Search(term)) {
			found_products.push_back(product[i]);
			std::cout << found_products.size() << ":" << std::endl;
			product[i]->Print();
			std::cout << std::endl;
		}
	}
	return found_products;
}
std::vector<Product*> Search_engine::Show_all() {
	found_products.clear();
	for (int i = 0; i < number_of_products; i++) {
		std::cout << i + 1 << ":" << std::endl;
		product[i]->Print();
		std::cout << std::endl;
		found_products.push_back(product[i]);
	}
	return found_products;
}