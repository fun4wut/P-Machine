
#include "and.h"



And::And() {}



And::~And() {}



void And::execute(StackMachine *stack) 
{
		if(stack->fSP < 1)
		throw ExecutionError("instruction and: requires 2 stackelements to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction and: SP does not point to element of type boolean.");
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction and: SP - 1 does not point to element of type boolean.");

	
		stack->fStore[stack->fSP - 1]->andi(stack->fStore[stack->fSP]);
	
		delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
		stack->fTime.count("add");	
}



ostream& And::print(ostream &os) const
{
	os << "and";
	return os;
}
