#include<iostream>
#include<string>
#include<vector>
#include "Check.h"

int string_to_int() {
start:
	std::string str;
	std::cin >> str;
	int i = strtol(str.c_str(), nullptr, 10);
	if (i != 0)
		return i;
	else {
		std::cout << "You did not enter a number, enter again: ";
		goto start;
	}
}

float string_to_float() {
start:
	char str[100];
	std::cin >> str;
	float i = strtof(str, NULL);
	if (i != 0)
		return i;
	else {
		std::cout << "You did not enter a number, enter again: ";
		goto start;
	}
}