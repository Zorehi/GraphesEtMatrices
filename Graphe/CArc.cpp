#include "CArc.h"

CArc::CArc(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}

int CArc::ARCLireDestination()const
{
	return iARCDestination;
}

void CArc::ARCModifierDestination(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}