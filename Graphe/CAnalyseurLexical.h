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
		 * @brief 
		 * 
		 * @param pcNomFichier Chaine de caractere vers le chemin du fichier
		 * @return CListe<char*> 
		 */
		static CListe<char*> ANLAnalyserFichier(const char* pcNomFichier);

		/**
		 * @brief 
		 * 
		 * @param pFILFichier Pointeur vers l'instance du fichier a lire
		 * @return char* 
		 */
		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		/**
		 * @brief 
		 * 
		 * @param pcLigne 
		 * @param LISCorrespondance 
		 */
		static void ANLExtraireInfoLigne(const char* pcLigne, CListe<char*>& LISCorrespondance);

};