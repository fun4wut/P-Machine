

#include "stackboolean.h"



StackBoolean::StackBoolean(bool boolean) : fBoolean(boolean) {}



StackBoolean::~StackBoolean() {}
						


bool StackBoolean::equ(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean == op1->fBoolean)
		return true;
	else
		return false;
}



bool StackBoolean::les(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean < op1->fBoolean)
		return true;
	else
		return false;
}



bool StackBoolean::grt(const StackElement *kOp) const
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	if(fBoolean > op1->fBoolean)
		return true;
	else
		return false;
}



void StackBoolean::andi(const StackElement *kOp)
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	fBoolean = fBoolean && op1->fBoolean;
}



void StackBoolean::ori(const StackElement *kOp)
{
	const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
	fBoolean = fBoolean || op1->fBoolean;
}



void StackBoolean::xori(const StackElement *kOp)
{
    const StackBoolean *op1 = dynamic_cast<const StackBoolean*>(kOp);
    fBoolean = fBoolean ^ op1->fBoolean;
}



void StackBoolean::noti()
{
	fBoolean = !fBoolean;
}



bool StackBoolean::getBoolean() const
{
	return fBoolean;
}


void StackBoolean::inc(int increment)
{
	fBoolean += increment;
}



ostream& StackBoolean::print(ostream &os) const
{
	if(fBoolean)
		os << 't';
	else
		os << 'f';
	return os;

}



char StackBoolean::getType() const
{
	return 'b';
}
		
