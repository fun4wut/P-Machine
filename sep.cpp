
#include "sep.h"



Sep::Sep(int p) : fP(p) {}



Sep::~Sep() {}



void Sep::execute(StackMachine *stack)
{	
	stack->fEP = stack->fSP + fP;
	
		stack->fTime.count("sep");

}



ostream& Sep::print(ostream &os) const
{
	os << "sep " << fP;
	return os;
}
