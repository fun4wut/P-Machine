
#ifndef GRT_H
#define GRT_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Grt : public Instruction
{
	public:
		Grt(StackElementType type);
		~Grt();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		StackElementType fType;
};


#endif

