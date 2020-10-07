
#include "add.h"


Add::Add(StackElementType type) : fType(type) {}



Add::~Add() {}



void Add::execute(StackMachine *stack) 
{
		if(stack->fSP < 1)
		throw ExecutionError("instruction add: requires 2 stackelements to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type integer.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction add: SP - 1 does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type real.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction add: SP - 1 does not point to element of type real.");
			break;
		}
		default:
			cerr << "operation not supported for this type" << endl;
	}
	
		stack->fStore[stack->fSP - 1]->add(stack->fStore[stack->fSP]);
	
		delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	stack->fStore.pop_back();
	--stack->fSP;
	
		stack->fTime.count("add");
}



ostream& Add::print(ostream &os) const
{
	os << "add " << printStackElementType(fType);
	return os;
}


