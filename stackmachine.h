

#ifndef STACKMACHINE_H
#define STACKMACHINE_H

#include <vector>
#include <typeinfo>
#include <strstream>
using namespace std;
class StackMachine;

#include "instruction.h"
#include "stackelement.h"
#include "stackinteger.h"
#include "labelcenter.h"
#include "timecounter.h"


class StackMachine
{
	public:
		friend class Instruction;

		friend class Pop;
		friend class Mod;
		friend class Xor;

		friend class Add; 		friend class Sub;					friend class Mul;					friend class Div;					friend class Neg;			
		friend class And;					friend class Or;					friend class Not;					
		friend class Equ;					friend class Geq;					friend class Leq;					friend class Les;					friend class Grt;					friend class Neq;					
		friend class Ldo; 		friend class Ldc;					friend class Ind;					friend class Sro;					friend class Sto;					
		friend class Ujp; 		friend class Fjp;
		
		friend class Ixj; 		
		friend class Ixa; 		
		friend class Inc; 		friend class Dec;
		friend class Chk;
		
		friend class Dpl; 		friend class Ldd;
		friend class Sli;					
		friend class New; 		
		friend class Lod; 		friend class Lda;
		friend class Str;
		
		friend class Mst; 		friend class Cup;
		friend class Ssp;
		friend class Sep;
		
		friend class Ent;
		
		friend class Retf; 		friend class Retp;
		
		friend class Movs; 		friend class Movd; 		
		friend class Smp;  		friend class Cupi;
		friend class Mstf;
		
		friend class In;   		friend class Out;
		friend class Hlt;
		friend class Conv;
		
		StackMachine();
		~StackMachine();
		
		void addInstruction(Instruction *instruction);
		void addLabel(const string &kLabel);
		
		void run();
		void step(bool step);
		
		void printCurrentInstruction();
		
		void showStack();
		void showHeap();
		void showParameters();
		void continueStep();
		
		void setShowHeap();
		void setStackSize(int stacksize);
		void setStepSize(int stepsize);



		
		
	private:
		vector<Instruction*> fCode;					vector<StackElement*> fStore;				vector<StackElement*> fHeap;				LabelCenter fLabelCenter;					TimeCounter fTime;							
		int fPC;									int fSP;									int fNP;									int fEP;									int fMP;									
				bool fHaltrequested;
		int fIC;									
				bool fStepping;
		bool fShowHeap;
		int fStepSize;
		int fStackSize;
		int fStepCounter;

				int base(int a, int p);		
		
};


#endif
