
#include "stackinteger.h"



StackInteger::StackInteger(int integer) : fInteger(integer) {}



StackInteger::~StackInteger() {}



void StackInteger::add(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger += op1->fInteger;
}



void StackInteger::sub(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger -= op1->fInteger;
}



void StackInteger::mul(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger *= op1->fInteger;
}



void StackInteger::div(StackElement *op)
{
	StackInteger *op1 = dynamic_cast<StackInteger*>(op);
	fInteger /= op1->fInteger;
}


void StackInteger::mod(StackElement *op)
{
    StackInteger *op1 = dynamic_cast<StackInteger*>(op);
    fInteger %= op1->fInteger;
}



void StackInteger::neg()
{
	fInteger = -fInteger;
}



bool StackInteger::equ(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger == op1->fInteger)
		return true;
	else
		return false;
}



bool StackInteger::les(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger < op1->fInteger)
		return true;
	else
		return false;

}



bool StackInteger::grt(const StackElement *kOp) const
{
	const StackInteger *op1 = dynamic_cast<const StackInteger*>(kOp);
	if(fInteger > op1->fInteger)
		return true;
	else
		return false;

}



int StackInteger::getValue() const
{
	return fInteger;
}



void StackInteger::inc(int increment)
{
	fInteger += increment;
}



bool StackInteger::isZero()
{
	if (fInteger == 0)
		return true;
	else
		return false;
}



ostream& StackInteger::print(ostream &os) const
{
	os << fInteger;
	return os;
}



char StackInteger::getType() const
{
	return 'i';
}
