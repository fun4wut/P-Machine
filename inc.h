

#ifndef INC_H
#define INC_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Inc : public Instruction
{
	public:
		Inc(StackElementType type, int p);
		~Inc();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		StackElementType fType;
};


#endif

