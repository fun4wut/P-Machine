
#include "not.h"


Not::Not() {}



Not::~Not() {}



void Not::execute(StackMachine *stack) 
{
		if(stack->fSP < 0)
		throw ExecutionError("instruction not: requires 1 stackelement to be present.");
		
	StackBoolean p1;
	
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction not: SP does not point to element of type boolean.");

	
		stack->fStore[stack->fSP]->noti();
	
		stack->fTime.count("not");

	
}



ostream& Not::print(ostream &os) const
{
	os << "not";
	return os;
}
