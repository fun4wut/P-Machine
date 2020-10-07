
#ifndef COMPILETIMEERROR_H
#define COMPILETIMEERROR_H

#include <string>
using namespace std;



class CompileTimeError
{
	public:
		CompileTimeError(const string &kMessage);
		~CompileTimeError();
		
		string getMsg();
		
	private:
		string fMessage;
};

#endif

