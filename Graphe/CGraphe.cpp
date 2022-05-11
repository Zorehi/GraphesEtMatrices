#include "CGraphe.h"

using namespace std;

CGraphe::CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc)
{
	LISGRASommet = CListe<CSommet*>(iNbSommet);
	LISGRAArc = CListe<CArc*>(iNbArc);
}

CGraphe::~CGraphe()
{
	int iNbSommets = LISGRASommet.LISLireTaille();
	for (int iBoucle = 0; iBoucle < iNbSommets; iBoucle++)
	{
		delete LISGRASommet[iBoucle];
	}
	int iNbArcs = LISGRAArc.LISLireTaille();
	for (int iBoucle = 0; iBoucle < iNbArcs; iBoucle++)
	{
		delete LISGRAArc[iBoucle];
	}
}

CListe<CSommet*>& CGraphe::GRALireSommet()
{
	return LISGRASommet;
}

CListe<CArc*>& CGraphe::GRALireArc()
{
	return LISGRAArc;
}

void CGraphe::GRAAfficherGraphe()
{
	int iNbSommet = LISGRASommet.LISLireTaille();
	for (int iBoucleI = 0; iBoucleI < iNbSommet; iBoucleI++)
	{
		cout << "Sommet " << iBoucleI << " :\n";

		CListe<CArc*> LISArcArrivant = LISGRASommet[iBoucleI]->SOMLireArrivant();
		int iNbArcArrivant = LISArcArrivant.LISLireTaille();

		if (iNbArcArrivant > 0) {
			cout << "\tArcs Arrivants :\n";

			for (int iBoucleJ = 0; iBoucleJ < iNbArcArrivant; iBoucleJ++)
			{
				cout << "\t\tArc " << iBoucleJ << " : Provenant : " << LISArcArrivant[iBoucleJ]->ARCLireDestination() << "\n";
			}
		}
		cout << "\n";

		CListe<CArc*> LISArcPartant = LISGRASommet[iBoucleI]->SOMLirePartant();
		int iNbArcArrivant = LISArcPartant.LISLireTaille();

		if (iNbArcArrivant > 0) {
			cout << "\tArcs Arrivants :\n";

			for (int iBoucleJ = 0; iBoucleJ < iNbArcArrivant; iBoucleJ++)
			{
				cout << "\t\tArc " << iBoucleJ << " : Provenant : " << LISArcPartant[iBoucleJ]->ARCLireDestination() << "\n";
			}
		}
		cout << "\n";
	}
}

void CGraphe::GRAAfficherGrapheGraphique()
{

}
