
#include "cupi.h"



Cupi::Cupi(int p, int q) : fP(p), fQ(q) {}



Cupi::~Cupi() {}



void Cupi::execute(StackMachine *stack)
{	
	
	
	stack->fStore[stack->fMP + 4] = new StackAddress(stack->fPC);
	
	if(stack->base(fP, stack->fStore[stack->fMP + 2]->getValue()) + fQ > stack->fSP)
	{
		throw ExecutionError("instruction cupi: trying to access a memorylocation above STORE[SP]");
	}
	stack->fPC = stack->fStore[stack->base(fP, stack->fStore[stack->fMP + 2]->getValue()) + fQ]->getValue();
	
		stack->fTime.count("cupi");
}



ostream& Cupi::print(ostream &os) const
{
	os << "cupi " << fP << " " << fQ;
	return os;
}
