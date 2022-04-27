#include "CException.h"
#include "stdlib.h"
#include "stdio.h"

CException::CException()
{
	iEXCval = 0;
	pcEXCmsg = NULL;
}


CException::~CException()
{
	if (pcEXCmsg != NULL) {
		free(pcEXCmsg);
	}
}


int CException::EXClireval()
{
	return iEXCval;
}


const char* CException::EXCliremsg()
{
	return pcEXCmsg;
}


void CException::EXCmodifierval(int newval)
{
	iEXCval = newval;
}


void CException::EXCmodifiermsg(char* newmsg)
{
	if (newmsg != NULL) {
		free(pcEXCmsg);
	}
	pcEXCmsg = newmsg;

}