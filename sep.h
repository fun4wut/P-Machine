

#ifndef SEP_H
#define SEP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Sep : public Instruction
{
	public:
		Sep(int p);
		~Sep();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
			
	private:
		int fP;
};


#endif
