
#include "ldd.h"


Ldd::Ldd(int q) : fQ(q) {}



Ldd::~Ldd() {}



void Ldd::execute(StackMachine *stack) 
{
	if(stack->fSP < 2)
		throw ExecutionError("instruction ldd: requires 3 stackelements to be present.");
	
	StackAddress p1;
	if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 2])))
		throw ExecutionError("instruction add: SP-2 does not point to element of type address.");
		
	++stack->fSP;
	
	stack->fStore.push_back(new StackInteger(stack->fStore[stack->fSP -3]->getValue() + fQ));
	
		stack->fTime.count("ldd");

}



ostream& Ldd::print(ostream &os) const
{
	os << "ldd " << fQ;
	return os;
}


