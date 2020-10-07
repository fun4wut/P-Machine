
#include "timecounter.h"
#include <iostream>


TimeCounter::TimeCounter() : fCounter(0)
{
	fWeights.insert(map<string, int>::value_type("pop", 1));
    fWeights.insert(map<string, int>::value_type("mod", 1));
    fWeights.insert(map<string, int>::value_type("xor", 1));
    fWeights.insert(map<string, int>::value_type("add", 1));
	fWeights.insert(map<string, int>::value_type("and", 1));
	fWeights.insert(map<string, int>::value_type("chk", 1));
	fWeights.insert(map<string, int>::value_type("conv", 1));
	fWeights.insert(map<string, int>::value_type("cup", 1));
	fWeights.insert(map<string, int>::value_type("cupi", 1));
	fWeights.insert(map<string, int>::value_type("dec", 1));
	fWeights.insert(map<string, int>::value_type("div", 1));
	fWeights.insert(map<string, int>::value_type("dpl", 1));
	fWeights.insert(map<string, int>::value_type("ent", 1));
	fWeights.insert(map<string, int>::value_type("equ", 1));
	fWeights.insert(map<string, int>::value_type("fjp", 1));
	fWeights.insert(map<string, int>::value_type("geq", 1));
	fWeights.insert(map<string, int>::value_type("grt", 1));
	fWeights.insert(map<string, int>::value_type("hlt", 1));
	fWeights.insert(map<string, int>::value_type("in", 1));
	fWeights.insert(map<string, int>::value_type("inc", 1));
	fWeights.insert(map<string, int>::value_type("ind", 1));
	fWeights.insert(map<string, int>::value_type("ixa", 1));
	fWeights.insert(map<string, int>::value_type("ixj", 1));
	fWeights.insert(map<string, int>::value_type("lda", 1));
	fWeights.insert(map<string, int>::value_type("ldc", 1));
	fWeights.insert(map<string, int>::value_type("ldd", 1));
	fWeights.insert(map<string, int>::value_type("ldo", 1));
	fWeights.insert(map<string, int>::value_type("leq", 1));
	fWeights.insert(map<string, int>::value_type("les", 1));
	fWeights.insert(map<string, int>::value_type("lod", 1));
	fWeights.insert(map<string, int>::value_type("movd", 1));
	fWeights.insert(map<string, int>::value_type("movs", 1));
	fWeights.insert(map<string, int>::value_type("mst", 1));
	fWeights.insert(map<string, int>::value_type("mstf", 1));
	fWeights.insert(map<string, int>::value_type("mul", 1));
	fWeights.insert(map<string, int>::value_type("neg", 1));
	fWeights.insert(map<string, int>::value_type("neq", 1));
	fWeights.insert(map<string, int>::value_type("new", 1));
	fWeights.insert(map<string, int>::value_type("not", 1));
	fWeights.insert(map<string, int>::value_type("or", 1));
	fWeights.insert(map<string, int>::value_type("out", 1));
	fWeights.insert(map<string, int>::value_type("retf", 1));
	fWeights.insert(map<string, int>::value_type("retp", 1));
	fWeights.insert(map<string, int>::value_type("sep", 1));
	fWeights.insert(map<string, int>::value_type("sli", 1));
	fWeights.insert(map<string, int>::value_type("smp", 1));
	fWeights.insert(map<string, int>::value_type("sro", 1));
	fWeights.insert(map<string, int>::value_type("ssp", 1));
	fWeights.insert(map<string, int>::value_type("sto", 1));
	fWeights.insert(map<string, int>::value_type("str", 1));
	fWeights.insert(map<string, int>::value_type("sub", 1));
	fWeights.insert(map<string, int>::value_type("ujp", 1));
}



TimeCounter::~TimeCounter() {}



void TimeCounter::count(const string &kInstruction)
{
	map<string, int>::iterator it = fWeights.find(kInstruction);
	
	if(it == fWeights.end())
	{
		cerr << "illegal instruction entered for counting purposes" << endl;
	}

	fCounter += fWeights[kInstruction];
}


int TimeCounter::getTime()
{
	return fCounter;
}
