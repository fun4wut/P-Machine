
#include "stackcharacter.h"



StackCharacter::StackCharacter(char character) : fCharacter(character) {}



StackCharacter::~StackCharacter() {}



bool StackCharacter::equ(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter == op1->fCharacter)
		return true;
	else
		return false;
}


bool StackCharacter::les(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter < op1->fCharacter)
		return true;
	else
		return false;

}



bool StackCharacter::grt(const StackElement *kOp) const
{
	const StackCharacter *op1 = dynamic_cast<const StackCharacter*>(kOp);
	if(fCharacter > op1->fCharacter)
		return true;
	else
		return false;
}



int StackCharacter::getValue() const
{
	return static_cast<int>(fCharacter);
}



void StackCharacter::inc(int increment)
{
	fCharacter += increment;
}



ostream& StackCharacter::print(ostream &os) const
{
	os << fCharacter;
	return os;
}



char StackCharacter::getType() const
{
	return 'c';
}
