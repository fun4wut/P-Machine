
#include "chk.h"



Chk::Chk(int p, int q) : fP(p), fQ(q) {}



Chk::~Chk() {}



void Chk::execute(StackMachine *stack)
{
	StackInteger p;
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP])))
	{
		throw ExecutionError("instruction chk: STORE[SP] does not contain element of type integer.");
	}
	
	if((stack->fStore[stack->fSP]->getValue() < fP) || (stack->fStore[stack->fSP]->getValue() > fQ))
	{
		throw ExecutionError("instruction chk: value out of range.");
	}
	
		stack->fTime.count("chk");

}



ostream& Chk::print(ostream &os) const
{
	os << "chk " << fP << " " << fQ;
	return os;
}
