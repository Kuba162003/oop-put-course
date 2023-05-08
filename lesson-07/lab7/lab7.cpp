#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Logarithm {
public:
	Logarithm(double base, double argument) {
		if(base <= 0 || base == 1){
			std::string error_info_base = "base: " + std::to_string(base) + " is wrong it should be greater than 0 and different from 1 ";
			throw invalid_argument(error_info_base);
		}
		if (argument <= 0) {
			std::string error_info_argument = "argument: " + std::to_string(argument) + " is wrong it should be greater than 0 ";
			throw invalid_argument(error_info_argument);
		}
		base_ = base;
		argument_ = argument;
	}

	double Calculate() const {
		return std::log(argument_) / std::log(base_);
	}

private:
	double base_;
	double argument_;
};

int main() {
	double base1;
	double argument1;
	cout << "Enter base: ";
	cin >> base1;
	cout << "Enter argument: ";
	cin >> argument1;
	try {
		Logarithm logarithm1(base1, argument1);
		cout << "Result:" << logarithm1.Calculate();
	}
	catch (invalid_argument & e) {
		cout << e.what();
	}
}