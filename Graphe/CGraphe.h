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
	CListe<CArc*> LISGRAArc;

public:
	CGraphe();
	CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc);
	CGraphe(const CGraphe& GRAParam);
	~CGraphe();

	CListe<CSommet*>& GRALireSommet();
	const CListe<CSommet*>& GRALireSommet()const;
	CListe<CArc*>& GRALireArc();
	void GRAAjouterSommet(CSommet* pSommet);
	void GRAAjouterArc(CArc* pArc);
	void GRAAfficherGraphe();
	void GRAAfficherGrapheGraphique();

	const CListe<CArc*>& GRALireArc()const;
	void GRAAfficherGraphe()const;
	void GRAAfficherGrapheGraphique()const;
	CGraphe& operator=(const CGraphe& GRAParam);
};