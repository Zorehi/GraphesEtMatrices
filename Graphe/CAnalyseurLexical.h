#pragma once

#include <cstdio>
#include <iostream>

#include "CException.h"
#include "CListe.h"

using namespace std;

typedef struct {
	char* Mot;
	char* Valeur;
}Correpondance;


class CAnalyseurLexical
{
	private:
		

	public:
		static void ANLAnalyserFichier(const char* pcNomFichier); 

		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		static void ANLExtraireInfoLigne(const char* pcLigne, CListe<Correpondance>& pLISCorrespondance);


};