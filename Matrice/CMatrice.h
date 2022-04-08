#pragma once

#include <stdlib.h>
#include <stdio.h>

class CMatrice {
	
	private :	
		//(void*)pMATMatrice;

	public :
		CMatrice();
		CMatrice(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, char* pcParamTypeMatrice);
		CMatrice(CMatrice& MATParam);
		~CMatrice();



};