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

public:
	CGraphe();
	CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc);
	CGraphe(const CGraphe& GRAParam);
	~CGraphe();

	const CListe<CSommet*>& GRALireSommet()const;
	void GRAAjouterSommet(CSommet* pSommet);

	void GRAAfficherGraphe()const;
	void GRAAfficherGrapheGraphique()const;

	CGraphe& operator=(const CGraphe& GRAParam);
};