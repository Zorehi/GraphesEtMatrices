#pragma once

#include <cstdio>
#include <iostream>

#include "CException.h"

using namespace std;

class CAnalyseurLexical
{
	private:
		

	public:
		static void ANLAnalyserFichier(const char* pcNomFichier); 

		static char* ANLLireProchaineLigne(FILE* pFILFichier);

		static char** ANLExtraireInfoLigne(const char* pcLigne);


};