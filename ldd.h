

#ifndef LDD_H
#define LDD_H


#include <vector>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Ldd : public Instruction
{
	public:
		Ldd(int q);
		~Ldd();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fQ;
};


#endif

