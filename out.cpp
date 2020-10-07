
#include "out.h"



Out::Out(StackElementType type, bool precisionmarker) : fType(type), fPrecisionMarker(precisionmarker) {}



Out::Out(StackElementType type) : fType(type), fPrecisionMarker(false) {}



Out::~Out() {}



void Out::execute(StackMachine *stack) 
{	
	switch(fType)
	{
		case integer:
		{
			StackInteger p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type integer.");
			
			cout << "print: " << *stack->fStore[stack->fSP] << endl;
			
						delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case character:
		{
			StackCharacter p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type character.");

			cout << "print: " << *stack->fStore[stack->fSP] << endl;

			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case boolean:
		{
			StackBoolean p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type boolean.");

			cout << "print: " << *stack->fStore[stack->fSP] << endl;

			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}
		case address:
		{
			StackAddress p1;
			if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
				throw ExecutionError("instruction out: SP does not point to element of type boolean.");

			cout << "print: " << *stack->fStore[stack->fSP] << endl;

			delete stack->fStore[stack->fSP];
			stack->fStore.pop_back();
			--stack->fSP;
		
			break;
		}	
		case real:
		{
			StackInteger p1;
			StackReal p2;
				
			if(fPrecisionMarker)
			{
								if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
					throw ExecutionError("instruction out: SP does not point to element of type integer.");
				if(typeid(p2) != typeid(*(stack->fStore[stack->fSP - 1])))
					throw ExecutionError("instruction out: SP - 1 does not point to element of type real.");
								
				cout.precision(stack->fStore[stack->fSP]->getValue());
				cout << "print: " << *stack->fStore[stack->fSP - 1] << endl;

				delete stack->fStore[stack->fSP];
				delete stack->fStore[stack->fSP - 1];
				stack->fStore.pop_back();
				stack->fStore.pop_back();
				stack->fSP -= 2;
			}
			else
			{
				if(typeid(p2) != typeid(*(stack->fStore[stack->fSP])))
					throw ExecutionError("instruction out: SP does not point to element of type real.");

				cout << "print: " << *stack->fStore[stack->fSP] << endl;

				delete stack->fStore[stack->fSP];
				stack->fStore.pop_back();
				--stack->fSP;
			}			
			break;
		}
	}

		stack->fTime.count("out");
}



ostream& Out::print(ostream &os) const
{
	if(fPrecisionMarker)
		os << "out r i";
	else
		os << "out " << printStackElementType(fType);
	return os;
}


