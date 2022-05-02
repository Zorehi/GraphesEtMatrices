#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "CMatricePlus.h"

#define Fichier_Introuvable 160
#define Erreur_Allocation 170
#define Erreur_Ouverture_Fichier 180
#define Type_Matrice_Fichier_Impossible 190

class CParseur
{
	private:
		char* pcPARFichier;
		FILE* pFILPARFichier;

	public:
		CParseur();
		CParseur(const char* pcCheminFichier);

		char* PARLireChemin();
		const char* PARLireLigne();
		
		CMatricePlus<double>& PARLirefichier();


};
