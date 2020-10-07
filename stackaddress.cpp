
#include "stackaddress.h"



StackAddress::StackAddress(int address) : fAddress(address) {}



StackAddress::~StackAddress() {}



void StackAddress::add(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress += op1->fAddress;
}



void StackAddress::sub(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress -= op1->fAddress;
}



void StackAddress::mul(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress *= op1->fAddress;
}



void StackAddress::div(StackElement *op)
{
	StackAddress *op1 = dynamic_cast<StackAddress*>(op);
	fAddress /= op1->fAddress;
}



void StackAddress::neg()
{
	fAddress = -fAddress;
}



bool StackAddress::equ(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress == op1->fAddress)
		return true;
	else
		return false;
}



bool StackAddress::les(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress < op1->fAddress)
		return true;
	else
		return false;
}



bool StackAddress::grt(const StackElement *kOp) const
{
	const StackAddress *op1 = dynamic_cast<const StackAddress*>(kOp);
	if(fAddress > op1->fAddress)
		return true;
	else
		return false;
}



int StackAddress::getValue() const
{
	return fAddress;
}



void StackAddress::inc(int increment)
{
	fAddress += increment;
}



bool StackAddress::heapAddress()
{
	if(fAddress < 0)
		return true;
	else
		return false;
}



ostream& StackAddress::print(ostream &os) const
{
	os << fAddress;
	return os;
}



char StackAddress::getType() const
{
	return 'a';
}
