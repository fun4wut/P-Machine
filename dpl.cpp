
#include "dpl.h"


Dpl::Dpl(StackElementType type) : fType(type) {}



Dpl::~Dpl() {}



void Dpl::execute(StackMachine *stack)
{
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[stack->fSP]))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case character:
		{
			StackCharacter p1;
			
						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[stack->fSP]))));
			}


			break;
		}
		case address:
		{
			StackAddress p1;

						if(typeid(p1) != typeid(*stack->fStore[stack->fSP]))
			{
				throw ExecutionError("instruction dpl: SP does not point to element of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[stack->fSP]))));
			}

			break;
		}
	}
	
		++stack->fSP;
	
		stack->fTime.count("dpl");

}



ostream& Dpl::print(ostream &os) const
{
	os << "dpl " << printStackElementType(fType);
	return os;
}
