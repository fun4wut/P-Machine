

#ifndef STACKELEMENT_H
#define STACKELEMENT_H

#include <iostream>
using namespace std;


enum StackElementType {real, integer, boolean, character, address, none};

class StackElement
{
	public:
		StackElement();
		~StackElement();
		
				virtual void add(StackElement *op);
				virtual void sub(StackElement *op);
				virtual void mul(StackElement *op);
				virtual void div(StackElement *op);
		        virtual void mod(StackElement *op);
        		virtual void neg();

				virtual void andi(const StackElement *kOp);
				virtual void ori(const StackElement *kOp);
		        virtual void xori(const StackElement *kOp);
        		virtual void noti();
		
				virtual bool equ(const StackElement *kOp) const;
				virtual bool les(const StackElement *kOp) const;
				virtual bool grt(const StackElement *kOp) const;
		
				virtual int getValue() const;
				virtual bool getBoolean() const;
				virtual double getReal() const;
		
				virtual void inc(int increment);
		
				virtual bool heapAddress();
		
				virtual bool isZero();
		
				virtual ostream& print(ostream &os) const;
		
				virtual char getType() const;
		
		friend ostream& operator<<(ostream &os, const StackElement &kOutput);
		
				friend bool operator==(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator!=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator>=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator<=(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator<(const StackElement &kOp1, const StackElement &kOp2);
		friend bool operator>(const StackElement &kOp1, const StackElement &kOp2);
};


#endif

