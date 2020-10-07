
#include "ixa.h"



Ixa::Ixa(int q) : fQ(q) {}



Ixa::~Ixa() {}



void Ixa::execute(StackMachine *stack)
{
	StackAddress p1;
	StackInteger p2;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction ixa: STORE[SP-1] does not contain an element of type address.");
		
	if(typeid(p2) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction ixa: STORE[SP] does not contain an element of type integer.");
		
	StackInteger temp(fQ);
	
	int newaddress = stack->fStore[stack->fSP - 1]->getValue() + stack->fStore[stack->fSP]->getValue() * fQ;
	
	delete stack->fStore[stack->fSP - 1];
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
	stack->fStore[stack->fSP] = new StackAddress(newaddress);
	
		stack->fTime.count("ixa");
}



ostream& Ixa::print(ostream &os) const
{
	os << "ixa " << fQ;
	return os;
}
