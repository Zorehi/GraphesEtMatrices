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
	CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc);
	~CGraphe();

	CListe<CSommet*>& GRALireSommet();
	CListe<CArc*>& GRALireArc();
	void GRAAfficherGraphe();
	void GRAAfficherGrapheGraphique();
};