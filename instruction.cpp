
#include "instruction.h"


Instruction::Instruction() {;}



Instruction::~Instruction() {;}



string printStackElementType(StackElementType type)
{
	switch(type)
	{
		case integer:
			return "i";
			break;
		case real:
			return "r";
			break;
		case character:
			return "c";
			break;
		case boolean:
			return "b";
			break;
		case address:
			return "a";
			break;
	}
}



ostream& operator<<(ostream &os, const Instruction &kOutput)
{ 
	return kOutput.print(os);
}
