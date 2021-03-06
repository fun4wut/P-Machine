

#ifndef MUL_H
#define MUL_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Mul : public Instruction
{
	public:
		Mul(StackElementType type);
		~Mul();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
				StackElementType fType;
};


#endif
