

#ifndef SUB_H
#define SUB_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Sub : public Instruction
{
	public:
		Sub(StackElementType type);
		~Sub();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;	

	private:
				StackElementType fType;
		
};


#endif
