

#ifndef RETF_H
#define RETF_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Retf : public Instruction
{
	public:
		Retf();
		~Retf();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};


#endif
