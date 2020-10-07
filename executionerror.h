
#ifndef EXECUTIONERROR_H
#define EXECUTIONERROR_H

#include <string>
using namespace std;



class ExecutionError
{
	public:
		ExecutionError(const string &kMessage);
		~ExecutionError();
		
		string getMsg();
		
	private:
		string fMessage;
};

#endif

