#include "CSommet.h"

CSommet::CSommet()
{
	iSOMNumero = 0;
	ppSOMArrivant = NULL;
	ppSOMPartant = NULL;
}

CSommet::CSommet(int iNumero)
{
	iSOMNumero = iNumero;
	ppSOMArrivant = NULL;
	ppSOMPartant = NULL;
}

CSommet::CSommet(CSommet& SOMArg)
{
	iSOMNumero = SOMArg.iSOMNumero;
	if (SOMArg.ppSOMArrivant != NULL) {
		ppSOMArrivant = new CListe<CArc*> (SOMArg.SOMLireArrivant().LISLireTaille());
		for (int iBoucleArriv = 0; iBoucleArriv < SOMArg.SOMLireArrivant().LISLireTaille(); iBoucleArriv++) {
			ppSOMArrivant[iBoucleArriv] = SOMArg.SOMLireArrivant()[iBoucleArriv];
		}
	}
	else {
		ppSOMArrivant = NULL;
	}
	if (SOMArg.ppSOMPartant != NULL) {
		ppSOMPartant = new CListe<CArc*>(SOMArg.SOMLirePartant().LISLireTaille());
		for (int iBouclePart = 0; iBouclePart < SOMArg.SOMLirePartant().LISLireTaille(); iBouclePart++) {
			ppSOMPartant[iBouclePart] = SOMArg.SOMLirePartant()[iBouclePart];
		}
	}
	else {
		ppSOMPartant = NULL;
	}
}

CSommet::~CSommet()
{
	delete ppSOMArrivant;
	delete ppSOMPartant;
}

int CSommet::SOMLireNumero()
{
	return iSOMNumero;
}

void CSommet::SOMModifierNumero(int iNumero)
{
	iSOMNumero = iNumero;
}

CListe<CArc*> CSommet::SOMLireArrivant()
{
	return ppSOMArrivant;
}

CListe<CArc*> CSommet::SOMLirePartant()
{
	return ppSOMPartant;
}

void CSommet::SOMAjouterArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = ppSOMArrivant.LISLireTaille() + 1;
	ppSOMArrivant.LISModifierTaille(uiNewTaille);
	ppSOMPartant[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMAjouterPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = ppSOMPartant.LISLireTaille() + 1;
	ppSOMPartant.LISModifierTaille(uiNewTaille);
	ppSOMPartant[uiNewTaille - 1] = pArcPartant;
}

void CSommet::SOMSupprimerArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = ppSOMArrivant.LISLireTaille() - 1;
	ppSOMArrivant.LISModifierTaille(uiNewTaille);
	ppSOMPartant[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMSupprimerPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = ppSOMPartant.LISLireTaille() - 1;
	ppSOMPartant.LISModifierTaille(uiNewTaille);
	ppSOMPartant[uiNewTaille - 1] = pArcPartant;
}

