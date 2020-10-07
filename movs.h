

#ifndef MOVS_H
#define MOVS_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Movs : public Instruction
{
	public:
		Movs(int q);
		~Movs();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
			
	private:
		int fQ;
};


#endif

