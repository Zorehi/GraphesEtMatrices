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
	~CException();

	int EXCLireval();
	const char* EXCLiremsg();
	void EXCModifierval(int iNewVal);
	void EXCModifiermsg(const char* pcNewMsg);
};

