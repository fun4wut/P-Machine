
#ifndef MSTF_H
#define MSTF_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Mstf : public Instruction
{
	public:
		Mstf(int p, int q);
		~Mstf();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		int fQ;
};


#endif
