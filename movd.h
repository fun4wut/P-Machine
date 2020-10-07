

#ifndef MOVD_H
#define MOVD_H


#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

#include "stackmachine.h"
#include "executionerror.h"
#include "stackelement.h"
#include "instruction.h"



class Movd : public Instruction
{
	public:
		Movd(int q);
		~Movd();
		void execute(StackMachine *stack);
		ostream& print(ostream &os) const;
	
	private:
		int fQ;
};


#endif
