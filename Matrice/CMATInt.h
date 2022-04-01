#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatriceBase.h"

class CMATInt : private CMatriceBase{
	private:
		int* piMINTValeurs;


	public:
		CMATInt();
		CMATInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		CMATInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, int* piParamListe);
		CMATInt(CMATInt& MINTParam);
		~CMATInt();


		int MINTLireElement(unsigned int uiParamLigne, unsigned int uiParamColonne);
		void MINTModifierElement(unsigned int uiParamLigne, unsigned int uiParamColonne, int iParamValeur);
		void MINTAfficherMatrice();

		CMATInt* MINTTranspose();
		CMATInt* MINTMultiplierConstante(int iParamValeur);
		CMATInt* MINTDiviserConstante(int iParamValeur);
		CMATInt* MINTAdditionnerMatrice(CMATInt* MINTParam);
		CMATInt* MINTSoustraireMatrice(CMATInt* MINTParam);
		CMATInt* MINTMultiplierMatrice(CMATInt* MINTParam);
		
};