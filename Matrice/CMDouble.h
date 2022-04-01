#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatriceBase.h"

class CMDouble : private CMatriceBase {
private:
	double *pdMDOValeurs;

public:
	CMDouble();
	CMDouble(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, double *dParamValeurs);
	CMDouble(CMDouble& MDOParam);
	~CMDouble();

	double MDOLireElement(unsigned int iParamLigne, unsigned int iParamColonne);
	void MDOModifierElement(unsigned int iParamLigne, unsigned int iParamColonne, double iParamValeur);
	void MDOAfficherMatrice();

};

