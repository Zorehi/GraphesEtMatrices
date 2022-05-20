/**
 * @file CAnalyseurLexical.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CAnalyseurLexical
 * CAnalyseurLexical permet de 
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <cstdio>
#include <iostream>

#include "CException.h"
#include "CListe.h"

using namespace std;

class CAnalyseurLexical
{
	public:
		/**
		 * @brief Ouvre et analyse un fichier texte pour en extraire les différents mots séparés par " ,=\r\n"
		 * 
		 * @param pcNomFichier Chaine de caractere vers le chemin du fichier
		 * @return CListe<char*> liste des mots contenus dans le fichier texte
		 */
		static CListe<char*> ANLAnalyserFichier(const char* pcNomFichier);

		/**
		 * @brief Recupere la prochaine ligne du fichier
		 * 
		 * @param pFILFichier Pointeur vers l'instance du fichier a lire
		 * @return char* Chaine de charactere contenant la ligne
		 */
		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		/**
		 * @brief Analyse une ligne de charactere pour en extraire les mots séparés par " ,=\r\n" et les ajoutes à la liste des mots placé en parametre
		 * 
		 * @param pcLigne Ligne a analyser
		 * @param LISCorrespondance Liste dans laquelle ajouter les mots trouvé sur la ligne
		 */
		static void ANLExtraireInfoLigne(const char* pcLigne, CListe<char*>& LISCorrespondance);

};