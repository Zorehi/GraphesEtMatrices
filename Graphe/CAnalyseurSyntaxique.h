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
		static CGraphe& ANSAnalyserFichier(const char* pcCheminFichier);

		static int ANSExtraireNbSommet(CListe<char*> pcLISListeMot);

		static int ANSExtraireNbArc(CListe<char*> pcLISListeMot);

		static CListe<int> ANSExtraireSommets(CListe<char*> pcLISListeMot, int iNbSommet);

		static CListe<int> ANSExtraireArcs(CListe<char*> pcLISListeMot, int iNbArc);
};