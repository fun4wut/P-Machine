

#ifndef INSTRUCTION_H
#define INSTRUCTION_H


#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Instruction;

#include "stackmachine.h"
#include "stackelement.h"
#include "stackinteger.h"
#include "stackreal.h"
#include "stackaddress.h"
#include "stackboolean.h"
#include "stackcharacter.h"
#include "timecounter.h"

class Stackmachine;



class Instruction
{
	public:
		friend class StackMachine;

		Instruction();
		virtual ~Instruction();
				virtual void execute(StackMachine *stack) = 0;
				virtual ostream& print(ostream &os) const = 0;
		friend ostream& operator<<(ostream &os, const Instruction &kOutput);
};


string printStackElementType(StackElementType type);


#endif

