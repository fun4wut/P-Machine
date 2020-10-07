
#include "movd.h"



Movd::Movd(int q) : fQ(q) {}



Movd::~Movd() {}



void Movd::execute(StackMachine *stack)
{	cout << "begin " << stack->fStore[stack->fMP + fQ]->getValue() << endl;
	cout << "einde " << stack->fStore[stack->fMP + fQ + 2]->getValue() << endl;
	cout << "totaal " << stack->fStore[stack->fMP + fQ]->getValue() + stack->fStore[stack->fMP + fQ + 2]->getValue() - 1 << endl;
	if(stack->fStore[stack->fStore[stack->fMP + fQ]->getValue() + stack->fStore[stack->fMP + fQ + 2]->getValue()]->getValue() < 0)
	{
						
		StackInteger p1;
		StackBoolean p2;
		StackAddress p3;
		StackCharacter p4;
		StackReal p5;
		
		int baseaddress = stack->fStore[stack->fMP + fQ]->getValue() + stack->fStore[stack->fMP + fQ + 2]->getValue() - 1;
		
		for(int i = 1; i <= stack->fStore[stack->fMP + fQ + 1]->getValue(); ++i)
		{
			int effectiveaddress = - baseaddress - i - 1;
			
			if((-effectiveaddress >= 0) || (-effectiveaddress < stack->fNP))
				throw ExecutionError("instruction movd: trying to access a heapaddress that is out of range.");

			if(typeid(p1) == typeid(*stack->fHeap[effectiveaddress]))			
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fHeap[-effectiveaddress]))));
			if(typeid(p2) == typeid(*stack->fHeap[effectiveaddress]))
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fHeap[-effectiveaddress]))));
			if(typeid(p3) == typeid(*stack->fHeap[effectiveaddress]))
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fHeap[-effectiveaddress]))));
			if(typeid(p4) == typeid(*stack->fHeap[effectiveaddress]))
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fHeap[-effectiveaddress]))));
			if(typeid(p5) == typeid(*stack->fHeap[effectiveaddress]))
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fHeap[-effectiveaddress]))));
		}
	}
	else
	{
						
		StackInteger p1;
		StackBoolean p2;
		StackAddress p3;
		StackCharacter p4;
		StackReal p5;
		
		int baseaddress = stack->fStore[stack->fMP + fQ]->getValue() + stack->fStore[stack->fMP + fQ + 2]->getValue() - 1;
		
		for(int i = 1; i <= stack->fStore[stack->fMP + fQ + 1]->getValue(); ++i)
		{
			int effectiveaddress = baseaddress + i;
			
			if((effectiveaddress < 0) || (effectiveaddress > stack->fSP))
				throw ExecutionError("instruction movd: trying to access a stackaddress that is out of range.");

			if(typeid(p1) == typeid(*stack->fStore[effectiveaddress]))			
				stack->fStore.push_back(new StackInteger(*(dynamic_cast<StackInteger*>(stack->fStore[effectiveaddress]))));
			if(typeid(p2) == typeid(*stack->fStore[effectiveaddress]))
				stack->fStore.push_back(new StackBoolean(*(dynamic_cast<StackBoolean*>(stack->fStore[effectiveaddress]))));
			if(typeid(p3) == typeid(*stack->fStore[effectiveaddress]))
				stack->fStore.push_back(new StackAddress(*(dynamic_cast<StackAddress*>(stack->fStore[effectiveaddress]))));
			if(typeid(p4) == typeid(*stack->fStore[effectiveaddress]))
				stack->fStore.push_back(new StackCharacter(*(dynamic_cast<StackCharacter*>(stack->fStore[effectiveaddress]))));
			if(typeid(p5) == typeid(*stack->fStore[effectiveaddress]))
				stack->fStore.push_back(new StackReal(*(dynamic_cast<StackReal*>(stack->fStore[effectiveaddress]))));
		}
	}
	
	delete stack->fStore[stack->fMP + fQ];
	stack->fStore[stack->fMP + fQ] = new StackAddress(stack->fSP + 1 - stack->fStore[stack->fMP + fQ + 2]->getValue());
	
		stack->fSP += stack->fStore[stack->fMP + fQ + 1]->getValue();	
	
		stack->fTime.count("movd");

}



ostream& Movd::print(ostream &os) const
{
	os << "movd " << fQ;
	return os;
}
