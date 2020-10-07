
#include "mstf.h"



Mstf::Mstf(int p, int q) : fP(p), fQ(q) {}



Mstf::~Mstf() {}



void Mstf::execute(StackMachine *stack)
{	
	for(int i = 0; i < 5; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}
	
		delete stack->fStore[stack->fSP + 2];
	stack->fStore[stack->fSP + 2] = new StackAddress(stack->fStore[stack->base(fP, stack->fMP) + fQ + 1]->getValue());
	
		delete stack->fStore[stack->fSP + 3];
	stack->fStore[stack->fSP + 3] = new StackAddress(stack->fMP);
	
		delete stack->fStore[stack->fSP + 4];
	stack->fStore[stack->fSP + 4] = new StackAddress(stack->fEP);
	
	stack->fSP += 5;
	
		stack->fTime.count("mstf");
}



ostream& Mstf::print(ostream &os) const
{
	os << "mstf " << fP << " " << fQ;
	return os;
}
