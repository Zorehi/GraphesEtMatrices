#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class CMatriceBase {
	private :
		char* pcTypeMatrice;
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;


	public :
		CMatriceBase();
		CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		CMatriceBase(CMatriceBase& MATParam);
		~CMatriceBase();

		
		void MABModifierTypeMatrice(const char* pcParamTypeMatrice);
		void MABModifierNbLignes(unsigned int uiParamNbLignes);
		void MABModifierNbColonnes(unsigned int uiParamNbColonnes);
		
		char* MABLireTypeMatrice();
		unsigned int MABLireNbLignes();
		unsigned int MABLireNbColonnes();

};