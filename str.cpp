
#include "str.h"


Str::Str(StackElementType type, int p, int q) : fType(type), fP(p), fQ(q) {}



Str::~Str() {}



void Str::execute(StackMachine *stack)
{	
	switch(fType)
	{
		case integer:
		{
			StackInteger p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type integer.");

			break;
		}	
		case real:
		{
			StackReal p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type real.");


			break;
		}
		case boolean:
		{
			StackBoolean p;
			
			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type boolean.");

			break;
		}
		case character:
		{
			StackCharacter p;

			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type character.");

			break;
		}
		case address:
		{
			StackAddress p;
			
			if(typeid(p) != typeid(*stack->fStore[stack->fSP]))
				throw ExecutionError("instruction str: element you are trying to access is not of type address.");

			break;
		}
	}
	
	int newaddress = stack->base(fP, stack->fMP) + fQ;
	
	if((newaddress > stack->fSP) || (newaddress < 0))
		throw ExecutionError("instruction str: trying to access element above SP or < 0.");
	
	delete stack->fStore[newaddress];
	stack->fStore[newaddress] = stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	
	--stack->fSP;
	
		stack->fTime.count("str");

}



ostream& Str::print(ostream &os) const
{
	os << "str " << printStackElementType(fType) << " " << fP << " " << fQ;
	return os;
}
