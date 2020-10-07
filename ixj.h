

#ifndef IXJ_H
#define IXJ_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Ixj : public Instruction
{
	public:
		Ixj(string q);
		~Ixj();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		string fQ;
};


#endif

