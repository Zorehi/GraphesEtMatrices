#pragma once

#include "CAnalyseurLexical.h"
#include "CGraphe.h"
#include "CListe.h"

class CAnalyseurSyntaxique
{
	public:
		/**
		 * @brief 
		 * @param pcCheminFichier 
		 * @return 
		*/
		static CGraphe ANSAnalyserFichier(const char* pcCheminFichier);

		static int ANSExtraireNbSommet(CListe<char*>& LISListeMot);

		static int ANSExtraireNbArc(CListe<char*>& LISListeMot);

		static CListe<int> ANSExtraireSommets(CListe<char*>& LISListeMot, int iNbSommet);

		static CListe<int> ANSExtraireArcs(CListe<char*>& LISListeMot, int iNbArc);
};