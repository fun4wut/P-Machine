
#include "ent.h"



Ent::Ent(int p, int q) : fP(p), fQ(q) {}



Ent::~Ent() {}



void Ent::execute(StackMachine *stack)
{	
	int oldSP = stack->fSP;
	
		stack->fSP = stack->fMP + fQ - 1;
	
	for(int i = oldSP + 1; i <= stack->fSP; ++i)
	{
		stack->fStore.push_back(new StackElement());
	}
	
		stack->fEP = stack->fSP + fP;
	
		stack->fTime.count("ent");

}



ostream& Ent::print(ostream &os) const
{
	os << "ent " << fP << " " << fQ;
	return os;
}
