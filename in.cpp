
#include "in.h"



In::In(StackElementType type) : fType(type) {}



In::~In() {}



void In::execute(StackMachine *stack) 
{	
	switch(fType)
	{
		case integer:
		{
			int inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackInteger(inputvalue));
			break;
		}	
		case real:
		{
			double inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackReal(inputvalue));
			break;
		}
		case character:
		{
			char inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackCharacter(inputvalue));
			break;
		}
		case boolean:
		{
			bool inputvalue;
			cin >> inputvalue;
			stack->fStore.push_back(new StackBoolean(inputvalue));
			break;
		}
		case address:
		{
			throw ExecutionError("instruction in: input of address at runtime is not allowed");
		}
	}
	
		++stack->fSP;
	
		stack->fTime.count("in");

}



ostream& In::print(ostream &os) const
{
	os << "in " << printStackElementType(fType);
	return os;
}


