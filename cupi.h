
#ifndef CUPI_H
#define CUPI_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Cupi : public Instruction
{
	public:
		Cupi(int p, int q);
		~Cupi();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
		int fQ;
};


#endif
