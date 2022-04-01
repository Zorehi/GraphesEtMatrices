#pragma once

#include <stdlib.h>
#include <stdio.h>

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
		int MABLireNbLignes();
		int MABLireNbColonnes();

};