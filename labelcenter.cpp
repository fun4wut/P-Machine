
#include "labelcenter.h"
#include <iostream>


LabelCenter::LabelCenter() {}



LabelCenter::~LabelCenter() {}



int LabelCenter::getAddress(const string &kLabel)
{
	map<string, int>::iterator it = fLabels.find(kLabel);
	
	if(it == fLabels.end())
	{
		throw ExecutionError("label " + kLabel + " was not defined");
	}
	
	return fLabels[kLabel] - 1;	
}



void LabelCenter::addAddress(const string &kLabel, int location)
{
	map<string, int>::iterator it = fLabels.find(kLabel);
	
	if(it != fLabels.end())
	{
		throw CompileTimeError("Label " + kLabel + " is being redeclared");
	}
	
	fLabels.insert(map<string, int>::value_type(kLabel, location));
}



void LabelCenter::print()
{
	for(map<string, int>::iterator it = fLabels.begin(); it != fLabels.end(); ++it)
	{
		std::cout << "pair: " << it->first << ", " << it->second << endl;
	}
}
	
