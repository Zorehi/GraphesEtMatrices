#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "CMatricePlus.h"
#include "CException.h"

#define Fichier_Introuvable 160
#define Erreur_Allocation 170
#define Erreur_Ouverture_Fichier 180
#define Type_Matrice_Fichier_Impossible 190

class CParseur
{
	public:
		static const char* PARLireLigne(FILE * pFILFichier);
		
		static CMatricePlus<double>& PARLirefichier(const char* pcNomFichier);
};
