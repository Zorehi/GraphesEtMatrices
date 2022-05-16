/**
 * @file CGraphe.cpp
 * @author LJ BV JM
 * @brief Contient la definition des methodes de la classe CGraphe
 * CGraphe permet de creer et gerer un graphe contenant
 * des sommets relier par des arcs
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CGraphe.h"

using namespace std;

CGraphe::CGraphe()
{
	LISGRASommet = CListe<CSommet*>();
}

CGraphe::CGraphe(const CGraphe& GRAParam)
{
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet.LISLireTaille());
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet[uiBoucle] = new CSommet(*GRAParam.LISGRASommet[uiBoucle]);
	}
}

CGraphe::~CGraphe()
{
	int iNbSommets = LISGRASommet.LISLireTaille();
	for (int iBoucleI = 0; iBoucleI < iNbSommets; iBoucleI++)
	{
		int NbArcPartant = LISGRASommet[iBoucleI]->SOMLirePartant().LISLireTaille();
		for (int iBoucleJ = 0; iBoucleJ < NbArcPartant; iBoucleJ++)
		{
			delete LISGRASommet[iBoucleI]->SOMLirePartant()[iBoucleJ];
		}
		delete LISGRASommet[iBoucleI];
	}
}

const CListe<CSommet*>& CGraphe::GRALireSommet()const
{
	return LISGRASommet;
}

void CGraphe::GRAAjouterSommet(CSommet* pSommet)
{
	LISGRASommet.LISModifierTaille(LISGRASommet.LISLireTaille() + 1);
	LISGRASommet[LISGRASommet.LISLireTaille() - 1] = pSommet;
}


void CGraphe::GRAAfficherGraphe()const
{
	int iNbSommet = LISGRASommet.LISLireTaille();
	for (int iBoucleI = 0; iBoucleI < iNbSommet; iBoucleI++)
	{
		cout << "Sommet " << LISGRASommet[iBoucleI]->SOMLireNumero() << " :\n";

		CListe<CArc*> LISArcArrivant = LISGRASommet[iBoucleI]->SOMLireArrivant();
		int iNbArcArrivant = LISArcArrivant.LISLireTaille();

		if (iNbArcArrivant > 0) {
			cout << "\tArcs Arrivants :\n";

			for (int iBoucleJ = 0; iBoucleJ < iNbArcArrivant; iBoucleJ++)
			{
				for (int iBoucleW = 0; iBoucleW < iNbSommet; iBoucleW++) {
					for (int iBoucleX = 0; iBoucleX < LISGRASommet[iBoucleW]->SOMLirePartant().LISLireTaille(); iBoucleX++) {
						if (LISGRASommet[iBoucleW]->SOMLirePartant()[iBoucleX] == LISArcArrivant[iBoucleJ]) {
							cout << "\t\tArc " << iBoucleJ << " : Provenant : " << LISGRASommet[iBoucleW]->SOMLireNumero() << "\n";
						}
					}
				}
			}
		}
		cout << "\n";

		CListe<CArc*> LISArcPartant = LISGRASommet[iBoucleI]->SOMLirePartant();
		int iNbArcPartant = LISArcPartant.LISLireTaille();

		if (iNbArcPartant > 0) {
			cout << "\tArcs Partants :\n";

			for (int iBoucleZ = 0; iBoucleZ < iNbArcPartant; iBoucleZ++)
			{
				cout << "\t\tArc " << iBoucleZ << " : Destination : " << LISArcPartant[iBoucleZ]->ARCLireDestination() << "\n";
			}
		}
		cout << "\n";
	}
}

CGraphe& CGraphe::operator=(const CGraphe& GRAParam)
{
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet.LISLireTaille());
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet[uiBoucle] = new CSommet(*GRAParam.LISGRASommet[uiBoucle]);
	}

	return *this;
}
