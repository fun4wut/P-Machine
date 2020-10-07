
#ifndef HLT_H
#define HLT_H

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Hlt : public Instruction
{
	public:
		Hlt();
		~Hlt();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};

#endif

