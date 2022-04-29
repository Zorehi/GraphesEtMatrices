#pragma once
#include "stdlib.h"
#include "stdio.h"

class CException
{
private:
	int iEXCVal;
	char* pcEXCMsg;
public:
	CException();
	CException(int iNewVal, const char* pcNewMsg);
	~CException();

	int EXCLireVal();
	const char* EXCLireMsg();
	void EXCModifierVal(int iNewVal);
	void EXCModifierMsg(const char* pcNewMsg);
};

