

#ifndef LABELCENTER_H
#define LABELCENTER_H

#include "compiletimeerror.h"
#include "executionerror.h"

#include <map>
#include <string>
using namespace std;



class LabelCenter
{
	public:
		LabelCenter();
		~LabelCenter();
		int getAddress(const string &kLabel);
		void addAddress(const string &kLabel, int location);
		void print();
	
	private:
		map<string, int> fLabels;
};


#endif

