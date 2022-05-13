#pragma once

#include <cstdio>
#include <iostream>

#include "CException.h"
#include "CListe.h"

using namespace std;

class CAnalyseurLexical
{
	public:
		static CListe<char*>& ANLAnalyserFichier(const char* pcNomFichier); 

		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		static void ANLExtraireInfoLigne(const char* pcLigne, CListe<char*>& pLISCorrespondance);


};