#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatriceBase.h"

class CMInt : private CMatriceBase{
	private:
		int* piMINTValeurs;


	public:
		CMInt();
		CMInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		CMInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, int* piParamListe);
		CMInt(CMInt& MINTParam);
		~CMInt();


		int MINTLireElement(unsigned int uiParamLigne, unsigned int uiParamColonne);
		void MINTModifierElement(unsigned int uiParamLigne, unsigned int uiParamColonne, int iParamValeur);
		void MINTAfficherMatrice();

		CMInt* MINTTranspose();
		CMInt* MINTMultiplierConstante(int iParamValeur);
		CMInt* MINTDiviserConstante(int iParamValeur);
		CMInt* MINTAdditionnerMatrice(CMInt* MINTParam);
		CMInt* MINTSoustraireMatrice(CMInt* MINTParam);
		CMInt* MINTMultiplierMatrice(CMInt* MINTParam);
		
};