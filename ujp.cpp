
#include "ujp.h"



Ujp::Ujp(string q) : fQ(q) {}



Ujp::~Ujp() {}



void Ujp::execute(StackMachine *stack)
{
	stack->fPC = stack->fLabelCenter.getAddress(fQ);
	
		stack->fTime.count("ujp");
}



ostream& Ujp::print(ostream &os) const
{
	os << "ujp " << fQ;
	return os;
}
