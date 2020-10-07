

#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <map>
#include <string>
using namespace std;



class TimeCounter
{
	public:
		TimeCounter();
		~TimeCounter();
		void count(const string &kInstruction);
		int getTime();
	
	private:
		map<string, int> fWeights;
		int fCounter;
};


#endif

