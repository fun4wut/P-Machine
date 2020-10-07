
#include "dec.h"



Dec::Dec(StackElementType type, int p) : fType(type), fP(-p) {}



Dec::~Dec() {}



void Dec::execute(StackMachine *stack)
{
		if(stack->fSP < 0)
		throw ExecutionError("instruction dec: requires 1 stackelement to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction dec: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction dec: SP does not point to element of type real.");

			break;
		}
		case boolean:
		{
			StackBoolean p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction dec: SP does not point to element of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction dec: SP does not point to element of type character.");

			break;
		}
		case address:
		{
			StackAddress p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction dec: SP does not point to element of type address.");

			break;
		}
	}
	
		stack->fStore[stack->fSP]->inc(fP);
	
		stack->fTime.count("dec");
}



ostream& Dec::print(ostream &os) const
{
	os << "dec " << printStackElementType(fType) << " " << -fP;
	return os;
}
