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


int CException::EXCLireval()
{
	return iEXCVal;
}


const char* CException::EXCLiremsg()
{
	return pcEXCMsg;
}


void CException::EXCModifierval(int iNewVal)
{
	iEXCVal = iNewVal;
}


void CException::EXCModifiermsg(const char* pcNewMsg)
{
	if (pcNewMsg != NULL) {
		free(pcEXCMsg);
	}
	pcEXCMsg = (char*) pcNewMsg;

}