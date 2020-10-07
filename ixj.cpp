
#include "ixj.h"


Ixj::Ixj(string q) : fQ(q) {}



Ixj::~Ixj() {}



void Ixj::execute(StackMachine *stack)
{
	StackInteger p1;
			
	if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
		throw ExecutionError("instruction ixj: STORE[SP] does not contain an element of type integer.");
		
	stack->fPC = stack->fStore[stack->fSP]->getValue() + stack->fLabelCenter.getAddress(fQ);
	
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
		stack->fTime.count("ixj");

}



ostream& Ixj::print(ostream &os) const
{
	os << "ixj " << fQ;
	return os;
}
