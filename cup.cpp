
#include "cup.h"


Cup::Cup(int p, const string &q) : fP(p), fQ(q) {}



Cup::~Cup() {}



void Cup::execute(StackMachine *stack)
{	
	stack->fMP = stack->fSP - (fP + 4);
	
	stack->fStore[stack->fMP + 4] = new StackAddress(stack->fPC);
	
	stack->fPC = stack->fLabelCenter.getAddress(fQ);
	
		stack->fTime.count("cup");

}



ostream& Cup::print(ostream &os) const
{
	os << "cup " << fP << " " << fQ;
	return os;
}
