
#include "sro.h"


Sro::Sro(StackElementType type, int q) : fType(type), fQ(q) {}



Sro::~Sro() {}



void Sro::execute(StackMachine *stack)
{
	if(stack->fSP < 1)
		throw ExecutionError("instruction sro: at least 1 stackelement is required for this operation");

				
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type integer.");
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type real.");
			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type boolean.");
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type character.");
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sro: type pointed to by SP is not of type address.");
			}
				
			break;
		}
	}
	
	if(fQ < 0)
	{
				if(fQ < stack->fNP)
			throw ExecutionError("instruction ind: invalid heap address.");
		else
		{
			stack->fHeap[fQ] = stack->fStore[stack->fSP];
		}
	}
	else
	{
				if(fQ > stack->fSP)
			throw ExecutionError("instruction ind: invalid stack address.");
		else
		{
			stack->fStore[fQ] = stack->fStore[stack->fSP];
		}
	}
	
	stack->fStore.pop_back();

	--stack->fSP;
	
		stack->fTime.count("sro");
}



ostream& Sro::print(ostream &os) const
{
	os << "sro " << printStackElementType(fType) << " " << fQ;
	return os;
}
