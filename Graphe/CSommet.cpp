
#include "CSommet.h"

CSommet::CSommet()
{
	iSOMNumero = 0;
	LISSOMArrivant = CListe<CArc*>();
	LISSOMPartant = CListe<CArc*>();
}

CSommet::CSommet(int iNumero)
{
	iSOMNumero = iNumero;
	LISSOMArrivant = CListe<CArc*>();
	LISSOMPartant = CListe<CArc*>();
}

CSommet::CSommet(CSommet& SOMArg)
{
	iSOMNumero = SOMArg.iSOMNumero;
	if (SOMArg.LISSOMArrivant) {
		LISSOMArrivant = CListe<CArc*>(SOMArg.SOMLireArrivant().LISLireTaille());
		for (int iBoucleArriv = 0; iBoucleArriv < SOMArg.SOMLireArrivant().LISLireTaille(); iBoucleArriv++) {
			LISSOMArrivant[iBoucleArriv] = SOMArg.SOMLireArrivant()[iBoucleArriv];
		}
	}
	else {
		LISSOMArrivant = NULL;
	}
	if (SOMArg.LISSOMPartant != NULL) {
		LISSOMPartant = new CListe<CArc*>(SOMArg.SOMLirePartant().LISLireTaille());
		for (int iBouclePart = 0; iBouclePart < SOMArg.SOMLirePartant().LISLireTaille(); iBouclePart++) {
			(*LISSOMPartant)[iBouclePart] = SOMArg.SOMLirePartant()[iBouclePart];
		}
	}
	else {
		LISSOMPartant = NULL;
	}
}

CSommet::~CSommet()
{
	delete LISSOMArrivant;
	delete LISSOMPartant;
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
	return LISSOMArrivant;
}

CListe<CArc*> CSommet::SOMLirePartant()
{
	return LISSOMPartant;
}

void CSommet::SOMAjouterArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = LISSOMArrivant.LISLireTaille() + 1;
	LISSOMArrivant.LISModifierTaille(uiNewTaille);
	LISSOMPartant[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMAjouterPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = LISSOMPartant.LISLireTaille() + 1;
	LISSOMPartant.LISModifierTaille(uiNewTaille);
	LISSOMPartant[uiNewTaille - 1] = pArcPartant;
}

void CSommet::SOMSupprimerArrivant(CArc* pArcArrivant)
{
	unsigned int uiNewTaille = LISSOMArrivant.LISLireTaille() - 1;
	LISSOMArrivant.LISModifierTaille(uiNewTaille);
	LISSOMPartant[uiNewTaille - 1] = pArcArrivant;
}

void CSommet::SOMSupprimerPartant(CArc* pArcPartant)
{
	unsigned int uiNewTaille = LISSOMPartant.LISLireTaille() - 1;
	LISSOMPartant.LISModifierTaille(uiNewTaille);
	LISSOMPartant[uiNewTaille - 1] = pArcPartant;
}

