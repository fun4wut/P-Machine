
#include "neq.h"



Neq::Neq(StackElementType type): fType(type) {}



Neq::~Neq() {}



void Neq::execute(StackMachine *stack) 
{
		if(stack->fSP < 1)
		throw ExecutionError("instruction neq: requires 2 stackelements to be present.");

	switch(fType)
	{
		case integer:
		{
			StackInteger p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type integer.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type real.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type real.");
			break;
		}
		case boolean:
		{
			StackBoolean p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type boolean.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type boolean.");
			break;
		}
		case character:
		{
			StackCharacter p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type character.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type character.");
			break;
		}
		case address:
		{
			StackAddress p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction neq: SP does not point to element of type address.");
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
				throw ExecutionError("instruction neq: SP - 1 does not point to element of type address.");
			break;
		}

	}
		
		StackBoolean *result;
	if(*(stack->fStore[stack->fSP - 1]) != *(stack->fStore[stack->fSP]))
		result = new StackBoolean(true);
	else
		result = new StackBoolean(false);
		
		delete stack->fStore[stack->fSP];
	stack->fStore[stack->fSP] = 0;
	delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore.pop_back();
	stack->fStore.pop_back();
	--stack->fSP;

		stack->fStore.push_back(result);
	
		stack->fTime.count("neq");

}



ostream& Neq::print(ostream &os) const
{
	os << "neq " << printStackElementType(fType);
	return os;
}
