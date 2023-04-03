#include<iostream>

class Length {
public:
	Length() {};
	virtual ~Length() {}
	virtual Length* AddLength(float piece) = 0;
	virtual std::string Value() = 0;
};

class Tape : public Length {
private:
	float centimeters;
public:
	Tape* AddLength(float piece){ 
		return new Tape(centimeters + piece); 
	}
	Tape* Cut(float piece) {
		return new Tape(centimeters - piece);
	}
	Tape* CalculateToInches(){
		return new Tape(centimeters / 2.54);
	}
	std::string Value(){ 
		return "cm"; 
	}
	Tape(float centimeters){ 
		this->centimeters = centimeters; 
	}
};

int main() {
	Tape myTape(8);
	Tape* biggerTape = myTape.AddLength(10);
	Tape* smollerTape = myTape.Cut(4);
	Tape* TypeInInches = myTape.CalculateToInches();
}