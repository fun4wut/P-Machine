
#include "or.h"



Or::Or() {}



Or::~Or() {}



void Or::execute(StackMachine *stack) 
{
		if(stack->fSP < 1)
		throw ExecutionError("instruction or: requires 2 stackelements to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction or: SP does not point to element of type boolean.");
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction or: SP - 1 does not point to element of type boolean.");

	
		stack->fStore[stack->fSP - 1]->ori(stack->fStore[stack->fSP]);
	
		delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
		stack->fTime.count("or");

}



ostream& Or::print(ostream &os) const
{
	os << "or";
	return os;
}
