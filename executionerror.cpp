
#include "executionerror.h"


ExecutionError::ExecutionError(const string &kMessage) : fMessage(kMessage) {}



ExecutionError::~ExecutionError() {}



string ExecutionError::getMsg()
{
	return fMessage;
}
