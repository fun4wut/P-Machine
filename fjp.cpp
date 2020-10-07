
#include "fjp.h"



Fjp::Fjp(string q) : fQ(q) {}



Fjp::~Fjp() {}



void Fjp::execute(StackMachine *stack)
{
	StackBoolean p;
	
	if(typeid(p) != typeid(*(stack->fStore[stack->fSP])))
		throw ExecutionError("instruction fjp: requires a boolean te be on top of the stack.");

	if(stack->fStore[stack->fSP]->getBoolean() == false)
	{
		stack->fPC = stack->fLabelCenter.getAddress(fQ);
	}
	
	delete stack->fStore[stack->fSP];
	stack->fStore.pop_back();
	--stack->fSP;
	
		stack->fTime.count("fjp");

}



ostream& Fjp::print(ostream &os) const
{
	os << "fjp " << fQ;
	return os;
}
