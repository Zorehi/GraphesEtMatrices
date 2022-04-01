#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class CMatriceBase {
	private :
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;


	public :
		CMatriceBase();
		CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		CMatriceBase(CMatriceBase& MATParam);
		~CMatriceBase();

		
		void MABModifierNbLignes(unsigned int uiParamNbLignes);
		void MABModifierNbColonnes(unsigned int uiParamNbColonnes);
		unsigned int MABLireNbLignes();
		unsigned int MABLireNbColonnes();

};