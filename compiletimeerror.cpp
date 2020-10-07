
#include "compiletimeerror.h"


CompileTimeError::CompileTimeError(const string &kMessage) : fMessage(kMessage) {}



CompileTimeError::~CompileTimeError() {}



string CompileTimeError::getMsg()
{
	return fMessage;
}
