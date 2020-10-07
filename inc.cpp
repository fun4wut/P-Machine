
#include "inc.h"



Inc::Inc(StackElementType type, int p) : fType(type), fP(p) {}



Inc::~Inc() {}



void Inc::execute(StackMachine *stack)
{
		
	if(stack->fSP < 0)
		throw ExecutionError("instruction inc: requires 1 stackelement to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type real.");

			break;
		}
		case boolean:
		{
			StackBoolean p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type character.");

			break;
		}
		case address:
		{
			StackAddress p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction inc: SP does not point to element of type address.");

			break;
		}
	}
	
		stack->fStore[stack->fSP]->inc(fP);
	
		stack->fTime.count("inc");

}



ostream& Inc::print(ostream &os) const
{
	os << "inc " << printStackElementType(fType) << " " << fP;
	return os;
}
