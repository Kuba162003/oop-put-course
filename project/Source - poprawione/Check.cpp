#include<iostream>
#include<string>
#include<vector>
#include "Check.h"

int string_to_int() {
	std::string str;
	std::cin >> str;
	try {
		int i = strtol(str.c_str(), nullptr, 10);
		if (i == 0)
			throw 1;
		return i;
	}
	catch(int err){
		std::cout << "You did not enter a number, enter again: ";
		return string_to_int();
	}
}

float string_to_float() {
	char str[100];
	std::cin >> str;
	try {
		float i = strtof(str, NULL);
		if (i == 0)
			throw 1;
		return i;
	}
	catch(int err){
		std::cout << "You did not enter a number, enter again: ";
		return string_to_float();
	}
}