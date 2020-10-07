
#include "ssp.h"



Ssp::Ssp(int p) : fP(p) {}



Ssp::~Ssp() {}



void Ssp::execute(StackMachine *stack)
{	
	int newSPvalue = stack->fMP + fP - 1;

		if(newSPvalue < stack->fSP)
	{
		for(int i = stack->fSP; i > newSPvalue; --i)
		{	
			delete stack->fStore[i];
			stack->fStore[i] = 0;
			stack->fStore.pop_back();
		}
	}
	else
	{
		for(int i = stack->fSP; i < newSPvalue; ++i)
		{
			stack->fStore.push_back(new StackElement());
		}
	}
	
	stack->fSP = newSPvalue;
	
		stack->fTime.count("ssp");
}



ostream& Ssp::print(ostream &os) const
{
	os << "ssp " << fP;
	return os;
}
