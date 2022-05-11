#include "CSommet.h"

CSommet::CSommet()
{
	iSOMNumero = 0;
	pLISSOMArrivant = NULL;
	pLISSOMPartant = NULL;
}

CSommet::CSommet(int iNumero)
{
	iSOMNumero = iNumero;
	pLISSOMArrivant = NULL;
	pLISSOMPartant = NULL;
}

CSommet::CSommet(CSommet& SOMArg)
{
	iSOMNumero = SOMArg.iSOMNumero;
	if (SOMArg.pLISSOMArrivant != NULL) {
		pLISSOMArrivant = new CListe<CArc*>(SOMArg.SOMLireArrivant().LISLireTaille());
		for (int iBoucleArriv = 0; iBoucleArriv < SOMArg.SOMLireArrivant().LISLireTaille(); iBoucleArriv++) {
			(*pLISSOMArrivant)[iBoucleArriv] = SOMArg.SOMLireArrivant()[iBoucleArriv];
		}
	}
	else {
		pLISSOMArrivant = NULL;
	}
	if (SOMArg.pLISSOMPartant) {
		pLISSOMPartant = new CListe<CArc*>(SOMArg.SOMLirePartant().LISLireTaille());
		for (int iBouclePart = 0; iBouclePart < SOMArg.SOMLirePartant().LISLireTaille(); iBouclePart++) {
			(*pLISSOMPartant)[iBouclePart] = SOMArg.SOMLirePartant()[iBouclePart];
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
	(*pLISSOMPartant)[uiNewTaille - 1] = pArcArrivant;
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

