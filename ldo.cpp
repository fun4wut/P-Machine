
#include "ldo.h"


Ldo::Ldo(StackElementType type, int q) : fType(type), fQ(q) {}



Ldo::~Ldo() {}



void Ldo::execute(StackMachine *stack)
{
	if(stack->fSP < fQ)
		throw ExecutionError("instruction ldo: no element present at STORE[q].");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[fQ]))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
			
						if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[fQ]))));
			}


			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
						if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[fQ]))));
			}


			break;
		}
		case character:
		{
			StackCharacter p1;
			
						if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[fQ]))));
			}


			break;
		}
		case address:
		{
			StackAddress p1;

						if(typeid(p1) != typeid(*stack->fStore[fQ]))
			{
				throw ExecutionError("instruction ldo: type of STORE[q] is not of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[fQ]))));
			}

			break;
		}
	}
	
		++stack->fSP;
	
		stack->fTime.count("ldo");

}



ostream& Ldo::print(ostream &os) const
{
	os << "ldo " << printStackElementType(fType) << " " << fQ;
	return os;
}
