
#include "conv.h"


Conv::Conv(StackElementType type1, StackElementType type2) : fType1(type1), fType2(type2) {}



Conv::~Conv() {}



void Conv::execute(StackMachine *stack) 
{
		if(stack->fSP < 0)
		throw ExecutionError("instruction conv: requires 1 stackelement to be present.");
	
	int integervalue;
	
	switch(fType1)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction conv: SP does not point to element of type integer.");
			
			integervalue = stack->fStore[stack->fSP]->getValue();
			
			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction conv: SP does not point to element of type real.");
			
			double realvalue = stack->fStore[stack->fSP]->getReal();
			delete stack->fStore[stack->fSP];	
			
			switch(fType2)
			{
				case integer:
					stack->fStore[stack->fSP] = new StackInteger(realvalue);
					break;
				case boolean:
					stack->fStore[stack->fSP] = new StackBoolean(realvalue);
					break;
				case character:
					stack->fStore[stack->fSP] = new StackCharacter(realvalue);
					break;
				case address:
					stack->fStore[stack->fSP] = new StackAddress(realvalue);
					break;
				case real:
					stack->fStore[stack->fSP] = new StackReal(realvalue);
					break;
			}

			return;
		}
		case character:
		{
			StackCharacter p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction conv: SP does not point to element of type character.");
			
			integervalue = stack->fStore[stack->fSP]->getValue();
			
			break;  
		}
		case boolean:
		{
			StackBoolean p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction conv: SP does not point to element of type boolean.");

			integervalue = stack->fStore[stack->fSP]->getBoolean();
			
			break;
		}
		case address:
		{
			StackAddress p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction conv: SP does not point to element of type address.");
			
			integervalue = stack->fStore[stack->fSP]->getValue();

			break;
		}
	}
	
	delete stack->fStore[stack->fSP];	
	
	switch(fType2)
	{
		case integer:
			stack->fStore[stack->fSP] = new StackInteger(integervalue);
			break;
		case boolean:
			stack->fStore[stack->fSP] = new StackBoolean(static_cast<bool>(integervalue));
			break;
		case character:
			stack->fStore[stack->fSP] = new StackCharacter(static_cast<char>(integervalue));
			break;
		case address:
			stack->fStore[stack->fSP] = new StackAddress(integervalue);
			break;
		case real:
			stack->fStore[stack->fSP] = new StackReal(integervalue);
			break;
	}
	
		stack->fTime.count("conv");

}


ostream& Conv::print(ostream &os) const
{
	os << "conv " << printStackElementType(fType1) << " " << printStackElementType(fType2);
	return os;
}


