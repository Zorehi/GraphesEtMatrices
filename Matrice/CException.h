#pragma once
#include "stdlib.h"
#include "stdio.h"

class CException
{
private:
	int iEXCval;
	char* pcEXCmsg;
public:
	CException();
	~CException();

	int EXClireval();
	const char* EXCliremsg();
	void EXCmodifierval(int newval);
	void EXCmodifiermsg(char* newmsg);
};

