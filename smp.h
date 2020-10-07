

#ifndef SMP_H
#define SMP_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Smp : public Instruction
{
	public:
		Smp(int p);
		~Smp();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fP;
};


#endif
