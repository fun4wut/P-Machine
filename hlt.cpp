
#include "hlt.h"



Hlt::Hlt() {}



Hlt::~Hlt() {}



void Hlt::execute(StackMachine *stack)
{
	stack->fHaltrequested = true;
	
		stack->fTime.count("hlt");

}



ostream& Hlt::print(ostream &os) const
{
	os << "hlt";
	return os;
}


