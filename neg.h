
#ifndef NEG_H
#define NEG_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Neg : public Instruction
{
	public:
		Neg(StackElementType type);
		~Neg();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
		
	private:
		StackElementType fType;
	
};


#endif
