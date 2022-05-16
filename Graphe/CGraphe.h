#pragma once

#include <iostream>
#include <stdio.h>

#include "CSommet.h"
#include "CListe.h"
#include "CArc.h"

class CGraphe
{
private:
	CListe<CSommet*> LISGRASommet;
	unsigned int uiType;

public:
	CGraphe();
	CGraphe(unsigned int uiType);
	CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc);
	CGraphe(const CGraphe& GRAParam);
	~CGraphe();



	const CListe<CSommet*>& GRALireSommet()const;
	const unsigned int GRALireType()const;

	void GRAAjouterSommet(CSommet* pSommet);
	void GRAAjouterArc(int iDebut, int iDestination);

	void GRAModifierSommet(CSommet* pSommet, int iNewNum);
	void GRAModifierSommet(int iOldNum, int iNewNum);

	void GRASupprimerSommet(CSommet* pSommet);
	void GRASupprimerSommet(int iNumSommet);

	void GRAAfficherGraphe()const;
	void GRAAfficherGrapheGraphique()const;

	CGraphe& operator=(const CGraphe& GRAParam);
};