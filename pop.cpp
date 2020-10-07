
#include "pop.h"

Pop::Pop() {}

Pop::~Pop() {}

void Pop::execute(StackMachine *stack)
{
        delete stack->fStore[stack->fSP];
    stack->fStore[stack->fSP] = 0;
    stack->fStore.pop_back();
    --stack->fSP;

    stack->fTime.count("pop");
}

ostream& Pop::print(ostream &os) const
{
    return os << "pop";
}