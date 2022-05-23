/**
 * @file CSommet.cpp
 * @author LJ BV JM
 * @brief Contient la definition des methodes de la classe CSommet
 * CSommet permet de gerer un sommet d'un graphe
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

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
	pLISSOMArrivant = new CListe<CArc*>();
	pLISSOMPartant = new CListe<CArc*>();
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

CListe<CArc*>& CSommet::SOMLireArrivant()
{
	return *pLISSOMArrivant;
}

CListe<CArc*>& CSommet::SOMLirePartant()
{
	return *pLISSOMPartant;
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

CSommet& CSommet::operator=(const CSommet& SOMArg)
{
	iSOMNumero = SOMArg.iSOMNumero;
	pLISSOMArrivant = new CListe<CArc*>();
	pLISSOMPartant = new CListe<CArc*>();

	return *this;
}

