#include<iostream>
#include<vector>
#include<string>
#pragma once

class Product {
protected:
	std::string name;
	int ID;
	int amount;
	float price;
	std::string additional_function_name;
public:
	friend class Order;
	Product();
	virtual std::string Category() = 0;
	virtual void Additional() = 0;
	std::string Function_name();
	bool Search(std::string term);
	void Print();
	void Add_products(int number);
};
class Groceries :public Product {
private:
	int expiration_date_day, expiration_date_month;
public:
	Groceries(std::string name1, int amount1, float price1, int day1, int month1);
	std::string Category();
	void Additional();
};

class Electronics :public Product {
private:
	char energy_class;
public:
	Electronics(std::string name1, int amount1, float price1, char energy_class1);
	std::string Category();
	void Additional();
};

class Clothes :public Product {
private:
	std::string size;
public:
	Clothes(std::string name1, int amount1, float price1, std::string size1);
	std::string Category();
	void Additional();
};

class Cosmetics :public Product {
private:
	std::string designed;
public:
	Cosmetics(std::string name1, int amount1, float price1, std::string designed1);
	std::string Category();
	void Additional();
};

class Chemistry :public Product {
private:
	std::string GHS;
public:
	Chemistry(std::string name1, int amount1, float price1, std::string GHS1);
	std::string Category();
	void Additional();
};