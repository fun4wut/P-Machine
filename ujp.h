

#ifndef UJP_H
#define UJP_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Ujp : public Instruction
{
	public:
		Ujp(string q);
		~Ujp();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;		
	
	private:
		string fQ;
};


#endif
