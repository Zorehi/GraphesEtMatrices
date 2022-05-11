#include "CArc.h"

CArc::CArc(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}

int CArc::ARCLireDestination()
{
	return iARCDestination;
}

void CArc::ARCModifierDestination(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}