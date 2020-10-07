
#include "neg.h"



Neg::Neg(StackElementType type) : fType(type) {}



Neg::~Neg() {}



void Neg::execute(StackMachine *stack) 
{
		if(stack->fSP < 0)
		throw ExecutionError("instruction neg: requires 1 stackelement to be present.");
		
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;

						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type integer.");

			break;
		}	
		case real:
		{
			StackReal p1;
						if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction add: SP does not point to element of type real.");
				
			break;
		}
	}
	
		stack->fStore[stack->fSP]->neg();
	
		stack->fTime.count("neg");
}



ostream& Neg::print(ostream &os) const
{
	os << "neg " << printStackElementType(fType);
	return os;
}
