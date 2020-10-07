

#ifndef ADD_H
#define ADD_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Add : public Instruction
{
	public:
		Add(StackElementType type);
		~Add();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
				StackElementType fType;
};


#endif
