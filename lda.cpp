
#include "lda.h"



Lda::Lda(int p, int q) : fP(p), fQ(q) {}



Lda::~Lda() {}



void Lda::execute(StackMachine *stack)
{
	stack->fStore.push_back(new StackAddress(stack->base(fP, stack->fMP) + fQ));
	
	++stack->fSP;
	
		stack->fTime.count("lda");

}



ostream& Lda::print(ostream &os) const
{
	os << "lda " << fP << " " << fQ;
	return os;
}
