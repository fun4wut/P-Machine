#include "stackelement.h"



StackElement::StackElement() {}



StackElement::~StackElement() {}

void StackElement::mod(StackElement *op)
{
    cerr << "add not available for class StackElement" << endl;
}

void StackElement::add(StackElement *op)
{
	cerr << "add not available for class StackElement" << endl;
}

void StackElement::sub(StackElement *op)
{
	cerr << "sub not available for class StackElement" << endl;
}

void StackElement::mul(StackElement *op)
{
	cerr << "mul not available for class StackElement" << endl;
}

void StackElement::div(StackElement *op)
{
	cerr << "dib not available for class StackElement" << endl;
}

void StackElement::andi(const StackElement *kOp)
{
	cerr << "andi not available for class StackElement" << endl;
}

void StackElement::ori(const StackElement *kOp)
{
	cerr << "ori not available for class StackElement" << endl;
}

void StackElement::xori(const StackElement *kOp)
{
    cerr << "xori not available for class StackElement" << endl;
}

void StackElement::noti()
{
	cerr << "noti not available for class StackElement" << endl;
}

void StackElement::neg()
{
	cerr << "neg not available for class StackElement" << endl;
}

bool StackElement::equ(const StackElement *kOp) const
{
	cerr << "equ not available for class StackElement" << endl;
	return true;
}

bool StackElement::les(const StackElement *kOp) const
{
	cerr << "les not available for class StackElement" << endl;
	return true;
}

bool StackElement::grt(const StackElement *kOp) const
{
	cerr << "grt not available for class StackElement" << endl;
	return true;
}

int StackElement::getValue() const
{
	cerr << "getValue() not available for class StackElement" << endl;
	return 0;
}

bool StackElement::getBoolean() const
{
	cerr << "getBoolean() not available for class StackElement" << endl;
	return true;
}

double StackElement::getReal() const
{
	cerr << "getReal() not available for class StackElement" << endl;
	return 0;
}

void StackElement::inc(int increment)
{
	cerr << "inc() is not available for class StackElement" << endl;
}

bool StackElement::heapAddress()
{
	cerr << "heapAddress() is not available for class StackElement" << endl;
	return true;
}

bool StackElement::isZero()
{
	cerr << "isZero() is not available for class StackElement" << endl;
	return true;
}



ostream& operator<<(ostream &os, const StackElement &kOutput)
{ 
	return kOutput.print(os);
}



bool operator==(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.equ(&kOp2);
}



bool operator!=(const StackElement &kOp1, const StackElement &kOp2)
{
	return !kOp1.equ(&kOp2);
}



bool operator>=(const StackElement &kOp1, const StackElement &kOp2)
{
	return (kOp1.equ(&kOp2) || kOp1.grt(&kOp2));
}



bool operator<=(const StackElement &kOp1, const StackElement &kOp2)
{
	return (kOp1.equ(&kOp2) || kOp1.les(&kOp2));
}



bool operator<(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.les(&kOp2);
}



bool operator>(const StackElement &kOp1, const StackElement &kOp2)
{
	return kOp1.grt(&kOp2);
}

ostream& StackElement::print(ostream &os) const
{
	os << "empty space";
	return os;
}

char StackElement::getType() const
{
	return ' ';
}







	

