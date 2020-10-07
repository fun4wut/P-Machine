
#include "div.h"



Div::Div(StackElementType type) : fType(type) {}



Div::~Div() {}



void Div::execute(StackMachine *stack) 
{
		if(stack->fSP < 1)
		throw ExecutionError("instruction add: requires 2 stackelements to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction div: SP does not point to element of type integer.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction div: SP - 1 does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
			
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction div: SP does not point to element of type real.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction div: SP - 1 does not point to element of type real.");
			break;
		}
		default:
			cerr << "operation not supported for this type" << endl;
	}
	
		if(stack->fStore[stack->fSP]->isZero())
		throw ExecutionError("instruction div: illegal action: divide by zero.");

		stack->fStore[stack->fSP - 1]->div(stack->fStore[stack->fSP]);
	
		delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
		stack->fTime.count("div");

}



ostream& Div::print(ostream &os) const
{
	os << "div " << printStackElementType(fType);
	return os;
}
