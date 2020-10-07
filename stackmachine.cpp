
#include "stackmachine.h"



StackMachine::StackMachine() : fSP(-1), fPC(0), fNP(0), fMP(0), fEP(0), fHaltrequested(false), fStepping(false), fIC(0), fStepSize(0), fShowHeap(false), fStackSize(0), fStepCounter(1) {}



StackMachine::~StackMachine() {}



void StackMachine::addInstruction(Instruction *instruction)
{
	fCode.push_back(instruction);
	++fIC;
}



void StackMachine::addLabel(const string &kLabel)
{
	fLabelCenter.addAddress(kLabel, fIC);
}



void StackMachine::run()
{
	fPC = 0;
	while(fHaltrequested == false)
	{
		if(fPC >= fIC)
		{
			throw ExecutionError("PC has exceeded maximum number of instructions.");
			cerr << "End reached" << endl;
			return;
		}
		else
		{
			if(fStepping)
			{
				printCurrentInstruction();
			}
			fCode[fPC]->execute(this);
			if(fStepping)
			{
				showStack();
				showHeap();
				showParameters();
				continueStep();
			}
			++fPC;
			++fStepCounter;
		}
	}
	
		cout << endl << "--> Execution time: " << fTime.getTime() << endl << endl;
	
}



void StackMachine::step(bool step)
{
	fStepping = step;
}



void StackMachine::continueStep()
{
	if(fStepCounter == fStepSize)
	{
		cout << "Press [c] + [Enter] to continue. Other key to end." << endl;
		char space;
		cin >> space;
		switch(space)
		{
			case 'c': 
			case 'C': break;
			default: exit(0);
		}
		fStepCounter = 0;
	}
}



void StackMachine::printCurrentInstruction()
{
	cout << "--> " << *fCode[fPC] << endl;
}



void StackMachine::showStack()
{
	int beginvalue;
	
	if(fStackSize == 0)
	{
		beginvalue = 0;
	}
	else
	{
		if(fStore.size() - fStackSize < 0)
		{
			beginvalue = 0;
		}
		else
		{
			beginvalue = fStore.size() - fStackSize;
		}
	}
	
	for(int i = beginvalue; i < fStore.size(); ++i)
	{
		cout << "\t[" << i << "]\t\t" << "[" << fStore[i]->getType() << "]\t" << *fStore[i] << endl;
	}
	cout << endl;

}



void StackMachine::showHeap()
{
	if(fShowHeap)
	{
		for(int i = -1; i >= fNP; --i)
		{
			cout << "\t[" << i << "]\t\t" << "[" << fHeap[-i-1]->getType() << "]\t" << *fHeap[-i-1] << endl;
		}
		cout << endl;
	}
}



void StackMachine::showParameters()
{
	cout << "\tSP: " << fSP << ",\tPC: " << fPC << endl;
	cout << "******" << endl;
}



void StackMachine::setShowHeap()
{
	fShowHeap = true;
	step(true);
}



void StackMachine::setStackSize(int stacksize)
{
	fStackSize = stacksize;
	step(true);
}



void StackMachine::setStepSize(int stepsize)
{
	fStepSize = stepsize;
	step(true);
}



int StackMachine::base(int p, int a)
{
	if (p == 0)
		return a;
	else
	{
		if(a+1 > fSP)
		{
			strstream errormessage;
			errormessage << "base(" << p << "," << a << ") is trying to access a memorylocation above STORE[SP]";
			throw ExecutionError(errormessage.str());
		}
		else
		{
			return base(p - 1, fStore[a+1]->getValue());
		}
	}
}
