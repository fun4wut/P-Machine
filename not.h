
#ifndef NOT_H
#define NOT_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Not : public Instruction
{
	public:
		Not();
		~Not();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
		
};


#endif
