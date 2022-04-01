#pragma once

#include <stdlib.h>
#include <stdio.h>

class CMatrice {
	private :
		int CMATiNbLignes;
		int CMATiNbColonnes;


	public :
		CMatrice();
		CMatrice(int iParamNbLignes, int iParamNbColonnes);
		CMatrice(CMatrice& MATParam);
		~CMatrice();

		
		void CMATModifierNbLignes(int iParamNbLignes);
		void CMATModifierNbColonnes(int iParamNbColonnes);
		int CMATGetNbLignes();
		int CMATGetNbColonnes();

};