

#ifndef SLI_H
#define SLI_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Sli : public Instruction
{
	public:
		Sli(StackElementType type);
		~Sli();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
	
	private:
		StackElementType fType;
};


#endif
