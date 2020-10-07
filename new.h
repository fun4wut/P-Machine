

#ifndef NEW_H
#define NEW_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class New : public Instruction
{
	public:
		New();
		~New();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
};


#endif
