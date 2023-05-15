#include <iostream>
#include <vector>

int next_product_ID = 0;
class Product {
private:
	std::string name;
	float price;
	int product_ID;
public:
	Product(std::string name1, float price1) {
		name = name1;
		price = price1;
		product_ID = next_product_ID;
		next_product_ID++;
	}
	float Price() {
		return price;
	}
};

int next_customer_ID = 0;
class Customer {
private:
	std::string name;
	std::string email;
	int customer_ID;
public:
	Customer(std::string name1, std::string email1) {
		name = name1;
		email = email1;
		customer_ID = next_customer_ID;
		next_customer_ID++;
	}
};

int next_order_ID = 0;
class Order {
private:
	Customer* customer;
	std::vector<Product*> product;
	int order_ID;
public:
	Order(Customer* customer1) {
		customer = customer1;
		order_ID = next_order_ID;
		next_order_ID++;
	}
	void Add_product(Product* product1) {
		product.push_back(product1);
	}
	void Total_cost() {
		float total_cost = 0;
		int max = product.size();

		for (int i = 0; i < max; i++) {
			total_cost = total_cost + product[i]->Price();
		}
		std::cout << total_cost;
	}
};

int main()
{
	Product milk("milk", 4);
	Product butter("butter", 7);
	Customer karol("Karol", "karol123@gmail.com");
	Order karolOrder (&karol);
	karolOrder.Add_product(&milk);
	karolOrder.Add_product(&butter);
	karolOrder.Total_cost();
}