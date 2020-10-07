
#include "smp.h"


Smp::Smp(int p) : fP(p) {}


Smp::~Smp() {}


void Smp::execute(StackMachine *stack)
{	
	stack->fMP = stack->fSP - (fP + 4);
	
		stack->fTime.count("smp");

}



ostream& Smp::print(ostream &os) const
{
	os << "smp " << fP;
	return os;
}

