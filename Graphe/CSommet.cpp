#include "CSommet.h"

CSommet::CSommet()
{
	iSOMNumero = 0;
	pLISSOMArrivant = new CListe<CArc*>();
	pLISSOMPartant = new CListe<CArc*>();
}

CSommet::CSommet(int iNumero)
{
	iSOMNumero = iNumero;
	pLISSOMArrivant = new CListe<CArc*>();
	pLISSOMPartant = new CListe<CArc*>();
}

CSommet::CSommet(const CSommet& SOMArg)
{
	iSOMNumero = SOMArg.iSOMNumero;
	if (SOMArg.pLISSOMArrivant != NULL) {
		pLISSOMArrivant = new CListe<CArc*>(SOMArg.pLISSOMArrivant->LISLireTaille());
		for (int iBoucleArriv = 0; iBoucleArriv < SOMArg.pLISSOMArrivant->LISLireTaille(); iBoucleArriv++) {
			(*pLISSOMArrivant)[iBoucleArriv] = (*SOMArg.pLISSOMArrivant)[iBoucleArriv];
		}
	}
	else {
		pLISSOMArrivant = NULL;
	}
	if (SOMArg.pLISSOMPartant) {
		pLISSOMPartant = new CListe<CArc*>(SOMArg.pLISSOMPartant->LISLireTaille());
		for (int iBouclePart = 0; iBouclePart < SOMArg.pLISSOMPartant->LISLireTaille(); iBouclePart++) {
			(*pLISSOMPartant)[iBouclePart] = (*SOMArg.pLISSOMPartant)[iBouclePart];
		}
	}
	else {
		pLISSOMPartant = NULL;
	}
}

CSommet::~CSommet()
{
	delete pLISSOMArrivant;
	delete pLISSOMPartant;
}

int CSommet::SOMLireNumero()
{
	return iSOMNumero;
}

void CSommet::SOMModifierNumero(int iNumero)
{
	iSOMNumero = iNumero;
}

CListe<CArc*>& CSommet::SOMLireArrivant()
{
	return *pLISSOMArrivant;
}

CListe<CArc*>& CSommet::SOMLirePartant()
{
	return *pLISSOMPartant;
}

void CSommet::SOMAjouterArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = pLISSOMArrivant->LISLireTaille() + 1;
	pLISSOMArrivant->LISModifierTaille(uiNewTaille);
	(*pLISSOMArrivant)[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMAjouterPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = pLISSOMPartant->LISLireTaille() + 1;
	pLISSOMPartant->LISModifierTaille(uiNewTaille);
	(*pLISSOMPartant)[uiNewTaille - 1] = pArcPartant;
}

void CSommet::SOMSupprimerArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = pLISSOMArrivant->LISLireTaille() - 1;
	pLISSOMArrivant->LISModifierTaille(uiNewTaille);
	(*pLISSOMPartant)[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMSupprimerPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = pLISSOMPartant->LISLireTaille() - 1;
	pLISSOMPartant->LISModifierTaille(uiNewTaille);
	(*pLISSOMPartant)[uiNewTaille - 1] = pArcPartant;
}

