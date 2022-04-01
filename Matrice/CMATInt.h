#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatrice.h"

class CMATInt : private CMatrice{
	private:
		int** CMINTppiValeurs;


	public:
		CMATInt();
		CMATInt(int iParamNbLignes, int iParamNbColonnes);
		CMATInt(CMATInt& MINTParam);
		~CMATInt();

		int CMINTGetElement(int iParamLigne, int iParamColonne);
		void CMINTModifierElement(int iParamLigne, int iParamColonne, int iParamValeur);
		void CMINTAfficherMatrice();


	

};