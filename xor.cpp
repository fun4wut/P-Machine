
#include "xor.h"



Xor::Xor() {}



Xor::~Xor() {}



void Xor::execute(StackMachine *stack)
{
        if(stack->fSP < 1)
        throw ExecutionError("instruction xor: requires 2 stackelements to be present.");

    StackBoolean p1;

    if(typeid(p1) != typeid(*(stack->fStore[stack->fSP])))
        throw ExecutionError("instruction xor: SP does not point to element of type boolean.");
    if(typeid(p1) != typeid(*(stack->fStore[stack->fSP - 1])))
        throw ExecutionError("instruction xor: SP - 1 does not point to element of type boolean.");


        stack->fStore[stack->fSP - 1]->xori(stack->fStore[stack->fSP]);

        delete stack->fStore[stack->fSP];
    stack->fStore[stack->fSP] = 0;
    stack->fStore.pop_back();
    --stack->fSP;

        stack->fTime.count("xor");
}



ostream& Xor::print(ostream &os) const
{
    os << "xor";
    return os;
}
