#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "CMatricePlus.h"
#include "CException.h"

class CParseur
{
	public:
		static const char* PARLireLigne(FILE * pFILFichier);
		
		static CMatricePlus<double>& PARLirefichier(const char* pcNomFichier);
};
