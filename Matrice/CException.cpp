#include "CException.h"


CException::CException()
{
	iEXCVal = 0;
	pcEXCMsg = NULL;
}

CException::CException(int iNewVal, const char* pcNewMsg)
{
	iEXCVal = iNewVal;
	pcEXCMsg = (char*)malloc((strlen(pcNewMsg) + 1) * sizeof(char));
	if (pcEXCMsg != NULL) {
		strcpy_s(pcEXCMsg, strlen(pcNewMsg) + 1, pcNewMsg);
	}
}

CException::~CException()
{
	if (pcEXCMsg) {
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
	if (pcEXCMsg) {
		free(pcEXCMsg);
	}

	if (pcNewMsg) {
		pcEXCMsg = (char*)malloc((strlen(pcNewMsg) + 1) * sizeof(char));
		if (pcEXCMsg != NULL) {
			strcpy_s(pcEXCMsg, strlen(pcNewMsg) + 1, pcNewMsg);
		}
	}
	else {
		pcEXCMsg = NULL;
	}
}