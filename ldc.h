
#ifndef LDC_H
#define LDC_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Ldc : public Instruction
{
	public:
		Ldc(StackElementType type, StackElement *constant);
		~Ldc();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		StackElementType fType;
		StackElement *fConstant;
};


#endif
