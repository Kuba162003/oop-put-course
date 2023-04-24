#include <iostream>
#include <memory>
#include<sstream>

class Sequence {
public:
	virtual int Length() = 0;
};

class FakeSequence : public Sequence {
public:
	int Length() override { return 100; }
};

class Gene {
private:
	std::string name_;
	std::shared_ptr<Sequence> sequence_;
public:
	Gene(std::string name, std::shared_ptr<Sequence> sequence);
	sequence_(sequence), name_(name) {};
	std::string JSON() {
		std::stringstream ss;
		ss << "{" << "\"name\":\"" <<name_ <<"\"length\": " << sequence_->Length() << "}"
	}
};
int main()
{
	std::shared_ptr<Sequence> fake_seq = std::make_shared<FakeSequence>();
	std:cout << gene.JSON() << std::endl;
	assert(fake_seq->Length == 100);
	return 0;
}