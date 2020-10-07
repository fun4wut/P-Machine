
#include "sli.h"


Sli::Sli(StackElementType type) : fType(type) {}



Sli::~Sli() {}



void Sli::execute(StackMachine *stack)
{
	if(stack->fSP < 1)
		throw ExecutionError("instruction sli: requires 2 stackelements to be present.");

	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type real.");

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p1;
			
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type character.");

			break;
		}
		case address:
		{
			StackAddress p1;

						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction sli: SP does not point to element of type address.");

			break;
		}
	}
	
		delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore[stack->fSP - 1] = stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
		--stack->fSP;
	
		stack->fTime.count("sli");

}



ostream& Sli::print(ostream &os) const
{
	os << "sli " << printStackElementType(fType);
	return os;
}
