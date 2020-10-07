
#include "stackreal.h"



StackReal::StackReal(double real) : fReal(real) {}



StackReal::~StackReal() {}



void StackReal::add(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal += op1->fReal;
}



void StackReal::sub(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal -= op1->fReal;
}



void StackReal::mul(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal *= op1->fReal;
}



void StackReal::div(StackElement *op)
{
	StackReal *op1 = dynamic_cast<StackReal*>(op);
	fReal /= op1->fReal;
}



void StackReal::neg()
{
	fReal = -fReal;
}



bool StackReal::equ(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal == op1->fReal)
		return true;
	else
		return false;
}



bool StackReal::les(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal < op1->fReal)
		return true;
	else
		return false;
}



bool StackReal::grt(const StackElement *kOp) const
{
	const StackReal *op1 = dynamic_cast<const StackReal*>(kOp);
	if(fReal > op1->fReal)
		return true;
	else
		return false;
}



double StackReal::getReal() const
{
	return fReal;
}



void StackReal::inc(int increment)
{	
	fReal += increment;
}



bool StackReal::isZero()
{
	if (fReal == 0)
		return true;
	else
		return false;
}



ostream& StackReal::print(ostream &os) const
{
	os << fReal;
	return os;
}



char StackReal::getType() const
{
	return 'r';
}

