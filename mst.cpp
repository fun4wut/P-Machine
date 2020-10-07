
#include "mst.h"



Mst::Mst(int p) : fP(p) {}



Mst::~Mst() {}



void Mst::execute(StackMachine *stack)
{	
	for(int i = 0; i < 5; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}

		delete stack->fStore[stack->fSP + 2];
	stack->fStore[stack->fSP + 2] = new StackAddress(stack->base(fP, stack->fMP));

		delete stack->fStore[stack->fSP + 3];
	stack->fStore[stack->fSP + 3] = new StackAddress(stack->fMP);

		delete stack->fStore[stack->fSP + 4];
	stack->fStore[stack->fSP + 4] = new StackAddress(stack->fEP);
	
	stack->fSP += 5;
	
		stack->fTime.count("mst");

}



ostream& Mst::print(ostream &os) const
{
	os << "mst " << fP;
	return os;
}

