
#include "ldc.h"


Ldc::Ldc(StackElementType type, StackElement *constant) : fType(type), fConstant(constant) {}



Ldc::~Ldc()
{
	delete fConstant;
}


void Ldc::execute(StackMachine *stack)
{
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type integer.");
			}
			else
			{
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(fConstant))));
			}
				
			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type real.");
			}
			else
			{
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(fConstant))));
			}

			break;
		}
		case boolean:
		{
			StackBoolean p1;
			
						if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type boolean.");
			}
			else
			{
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(fConstant))));
			}

			break;
		}
		case character:
		{
			StackCharacter p1;
			
						if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type character.");
			}
			else
			{
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(fConstant))));
			}

			break;
		}
		case address:
		{
			StackAddress p1;

						
			if(typeid(p1) != typeid(*fConstant))
			{
				throw ExecutionError("instruction ldc: type of constant is not of type address.");
			}
			else
			{
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(fConstant))));
			}

			break;
		}
	}
	
		++stack->fSP;
	
		stack->fTime.count("ldc");

}



ostream& Ldc::print(ostream &os) const
{
	os << "ldc " << printStackElementType(fType) << " " << *fConstant;
	return os;
}
