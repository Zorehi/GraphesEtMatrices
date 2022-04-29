#include "CException.h"
#include "stdlib.h"
#include "stdio.h"

CException::CException()
{
	iEXCVal = 0;
	pcEXCMsg = NULL;
}


CException::~CException()
{
	if (pcEXCMsg != NULL) {
		free(pcEXCMsg);
	}
}


int CException::EXCLireVal()
{
	return iEXCVal;
}


const char* CException::EXCLireMsg()
{
	return pcEXCMsg;
}


void CException::EXCModifierVal(int newval)
{
	iEXCVal = newval;
}


void CException::EXCModifierMsg(char* newmsg)
{
	if (newmsg != NULL) {
		free(pcEXCMsg);
	}
	pcEXCMsg = newmsg;

}