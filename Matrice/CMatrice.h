#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CListe.h"

template <typename ELEMENT>
class CMatrice {
	
	private :	
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;
		CListe<ELEMENT>* pLISMATListe;

	public :
		CMatrice();
		CMatrice(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, char* pcParamTypeMatrice);
		CMatrice(CMatrice& MATParam);
		~CMatrice();



};