
#include "retf.h"



Retf::Retf() {}



Retf::~Retf() {}



void Retf::execute(StackMachine *stack)
{	
	StackAddress p;
	if((typeid(p) != typeid(*(stack->fStore[stack->fMP + 2]))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 3])))
		|| (typeid(p) != typeid(*(stack->fStore[stack->fMP + 4])))))
	{
		throw ExecutionError("instruction retf: stackframe has been compromised.");
	}
	
	int oldSP = stack->fSP;
	
		stack->fSP = stack->fMP;
	
		stack->fPC = stack->fStore[stack->fMP + 4]->getValue();
	
		stack->fEP = stack->fStore[stack->fMP + 3]->getValue();
	
		stack->fMP = stack->fStore[stack->fMP + 2]->getValue();
	
	for(int i = oldSP; i > stack->fSP; --i)
	{
		delete stack->fStore[i];
		stack->fStore.pop_back();
	}
	
		stack->fTime.count("retf");

	
}



ostream& Retf::print(ostream &os) const
{
	os << "retf";
	return os;
}
