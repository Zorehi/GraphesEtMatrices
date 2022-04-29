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


void CException::EXCModifierVal(int iNewVal)
{
	iEXCVal = iNewVal;
}


void CException::EXCModifierMsg(const char* pcNewMsg)
{
	if (pcNewMsg != NULL) {
		free(pcEXCMsg);
	}
	pcEXCMsg = (char*) pcNewMsg;

}