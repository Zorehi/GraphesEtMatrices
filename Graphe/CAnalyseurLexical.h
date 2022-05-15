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
		 * @param pcNomFichier 
		 * @return 
		*/
		static CListe<char*> ANLAnalyserFichier(const char* pcNomFichier);

		/**
		 * @brief 
		 * @param pFILFichier 
		 * @return 
		*/
		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		/**
		 * @brief 
		 * @param pcLigne 
		 * @param pLISCorrespondance 
		*/
		static void ANLExtraireInfoLigne(const char* pcLigne, CListe<char*>& LISCorrespondance);

};