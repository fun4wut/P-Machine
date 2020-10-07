

#ifndef CUP_H
#define CUP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Cup : public Instruction
{
	public:
		Cup(int p, const string &q);
		~Cup();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	private:
		int fP;
		string fQ;
};


#endif
