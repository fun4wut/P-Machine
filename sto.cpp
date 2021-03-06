
#include "sto.h"



Sto::Sto(StackElementType type) : fType(type) {}



Sto::~Sto() {}



void Sto::execute(StackMachine *stack)
{
	StackAddress p;
	
	if(stack->fSP < 1)
		throw ExecutionError("instruction sto: at least 2 stackelements are required for this operation");
		
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP - 1])))
		throw ExecutionError("instruction sto: type pointed to by SP - 1 is not of type address.");
				
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sto: type pointed to by SP is not of type integer.");
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sto: type pointed to by SP is not of type real.");
			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sto: type pointed to by SP is not of type boolean.");
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sto: type pointed to by SP is not of type character.");
			}


			break;
		}
		case address:
		{
			StackAddress p1;

			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
			{
				throw ExecutionError("instruction sto: type pointed to by SP is not of type address.");
			}
				
			break;
		}
	}
	
	if(stack->fStore[stack->fSP - 1]->heapAddress())
	{
		if(stack->fStore[stack->fSP - 1]->getValue() < stack->fNP)
		{
			throw ExecutionError("instruction sto: invalid heap address.");
		}
		else
		{
			delete stack->fHeap[-stack->fStore[stack->fSP - 1]->getValue() - 1];
			stack->fHeap[-stack->fStore[stack->fSP - 1]->getValue() - 1] = stack->fStore[stack->fSP];
		}
	}
	else
	{
		if(stack->fStore[stack->fSP - 1]->getValue() > stack->fSP - 2) 	
		{
						
			throw ExecutionError("instruction sto: invalid stack address.");
		}
		else
		{
			delete stack->fStore[stack->fStore[stack->fSP - 1]->getValue()];
			stack->fStore[stack->fStore[stack->fSP - 1]->getValue()] = stack->fStore[stack->fSP];
		}
	}
	
	stack->fStore.pop_back();
	delete stack->fStore[stack->fSP - 1];
	stack->fStore[stack->fSP - 1] = 0;
	stack->fStore.pop_back();

	stack->fSP -= 2;
	
		stack->fTime.count("sto");
}


ostream& Sto::print(ostream &os) const
{
	os << "sto " << printStackElementType(fType);
	return os;
}
