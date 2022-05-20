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
		 * @brief Construit un Graphe à partir du chemin d'un fichier texte définissant un graphe
		 * 
		 * @param pcCheminFichier Chaine de caractere vers le chemin du fichier
		 * @return CGraphe Graphe cree par la suite de la lecture du fichier
		 */
		static CGraphe ANSAnalyserFichier(const char* pcCheminFichier);

		/**
		 * @brief Cherche le nombre de sommet en analysant la liste des mots
		 * 
		 * @param LISListeMot La liste des mots retournees par l'analyseur lexical
		 * @return int Le nombre de sommet
		 */
		static int ANSExtraireNbSommet(CListe<char*>& LISListeMot);
		
		/**
		 * @brief Cherche le nombre d'arc en analysant la liste des mots
		 * 
		 * @param LISListeMot La liste des mots retournees par l'analyseur lexical
		 * @return int Le nombre d'arcs
		 */
		static int ANSExtraireNbArc(CListe<char*>& LISListeMot);

		/**
		 * @brief Cherche les numero de chaque sommet
		 * 
		 * @param LISListeMot La liste des mots retournees par l'analyseur lexical
		 * @param iNbSommet Le nombre de sommet dans le graphe
		 * @return CListe<int> Une liste des numéros des différents sommets
		 */
		static CListe<int> ANSExtraireSommets(CListe<char*>& LISListeMot, int iNbSommet);

		/**
		 * @brief Recupere les informations sur les differents arcs
		 * 
		 * @param LISListeMot La liste des mots retournees par l'analyseur lexical
		 * @param iNbArc Le nombre d'arc
		 * @return CListe<int> Une liste des provenance et destination de chaque arc [provenance, destination, provenance, destination, ...]
		 */
		static CListe<int> ANSExtraireArcs(CListe<char*>& LISListeMot, int iNbArc);
};