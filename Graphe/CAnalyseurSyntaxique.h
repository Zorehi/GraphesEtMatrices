/**
 * @file CAnalyseurSyntaxique.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CAnalyseurSyntaxique
 * CAnalyseurSyntaxique permet de creer un Graphe avec les donnees
 * que CAnalyseurLexicale lui donne
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "CAnalyseurLexical.h"
#include "CGraphe.h"
#include "CListe.h"

class CAnalyseurSyntaxique
{
	public:
		/**
		 * @brief 
		 * 
		 * @param pcCheminFichier Chaine de caractere vers le chemin du fichier
		 * @return CGraphe Graphe cree par la suite de la lecture du fichier
		 */
		static CGraphe ANSAnalyserFichier(const char* pcCheminFichier);

		/**
		 * @brief 
		 * 
		 * @param LISListeMot 
		 * @return int 
		 */
		static int ANSExtraireNbSommet(CListe<char*>& LISListeMot);
		
		/**
		 * @brief 
		 * 
		 * @param LISListeMot 
		 * @return int 
		 */
		static int ANSExtraireNbArc(CListe<char*>& LISListeMot);

		/**
		 * @brief 
		 * 
		 * @param LISListeMot 
		 * @param iNbSommet 
		 * @return CListe<int> 
		 */
		static CListe<int> ANSExtraireSommets(CListe<char*>& LISListeMot, int iNbSommet);

		/**
		 * @brief 
		 * 
		 * @param LISListeMot 
		 * @param iNbArc 
		 * @return CListe<int> 
		 */
		static CListe<int> ANSExtraireArcs(CListe<char*>& LISListeMot, int iNbArc);
};