/**
 * @file CParseur.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CParseur
 * CParseur contient des methodes statiques permettant
 * de creer des matrices a partir de fichier
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
		/**
		 * @brief Lis une ligne du fichier texte et la retourne
		 * 
		 * @param pFILFichier Pointeur sur le fichier à lire
		 * @return const char* Chaine lu dans le fichier
		 */
		static char* PARLireLigne(FILE * pFILFichier);
		
		/**
		 * @brief Genere une matrice lu dans un fichier texte
		 * 
		 * @param pcNomFichier Nom du fichier 
		 * @return CMatricePlus<double>& Matrice generee
		 */
		static CMatricePlus<double> PARLirefichier(const char* pcNomFichier);
};
