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
		pLISSOMArrivant = new CListe<CArc*>();;
	}
	if (SOMArg.pLISSOMPartant) {
		pLISSOMPartant = new CListe<CArc*>(SOMArg.pLISSOMPartant->LISLireTaille());
		for (int iBouclePart = 0; iBouclePart < SOMArg.pLISSOMPartant->LISLireTaille(); iBouclePart++) {
			(*pLISSOMPartant)[iBouclePart] = (*SOMArg.pLISSOMPartant)[iBouclePart];
		}
	}
	else {
		pLISSOMPartant = new CListe<CArc*>();;
	}
}

CSommet::~CSommet()
{
	delete pLISSOMArrivant;
	delete pLISSOMPartant;
}

int CSommet::SOMLireNumero()const
{
	return iSOMNumero;
}

void CSommet::SOMModifierNumero(int iNumero)
{
	iSOMNumero = iNumero;

	//Modifier la destination de tout les arcs arrivant dans ce sommet
	for (unsigned int uiBoucle = 0; uiBoucle < pLISSOMArrivant->LISLireTaille(); uiBoucle++) {
		(*pLISSOMArrivant)[uiBoucle]->ARCModifierDestination(iNumero);
	}

}

const CListe<CArc*>& CSommet::SOMLireArrivant()const
{
	return *pLISSOMArrivant;
}

const CListe<CArc*>& CSommet::SOMLirePartant()const
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

}

void CSommet::SOMSupprimerPartant(CArc* pArcPartant)
{

}

