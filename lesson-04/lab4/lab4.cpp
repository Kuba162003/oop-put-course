#include<iostream>
#include<string>

class Wire {
private:
	double _long;
public:
	double Length() { return this->_long; };
	Wire() { this->_long = 0.0; };
	Wire(double size) { this->_long = size; };
	Wire(float size) : Wire(static_cast<double>(size)) {};
	Wire(int size) : Wire(static_cast<double>(size)) {};
	Wire(std::string size) : Wire(std::stod(size)) {};
};

int main() {
	Wire defaultSize;
	Wire doubleSize(25.76);
	Wire floatSize(292.01f);
	Wire stringSize("44.87");
	Wire intSize(560);
	std::cout << defaultSize.Length() << std::endl;
	std::cout << doubleSize.Length() << std::endl;
	std::cout << floatSize.Length() << std::endl;
	std::cout << stringSize.Length() << std::endl;
	std::cout << intSize.Length() << std::endl;
	std::cout << "typeid of stringSize.Length() -> " << typeid(stringSize.Length()).name();
	return 0;
}