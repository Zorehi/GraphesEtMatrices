#include "CGraphe.h"

using namespace std;

CGraphe::CGraphe()
{
	LISGRASommet = CListe<CSommet*>();
	LISGRAArc = CListe<CArc*>();
}

CGraphe::CGraphe(int iNbSommet, int* piSommet, int iNbArc, int** ppiArc)
{
	LISGRASommet = CListe<CSommet*>(iNbSommet);
	LISGRAArc = CListe<CArc*>(iNbArc);
}

CGraphe::CGraphe(const CGraphe& GRAParam)
{
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet);
	LISGRAArc = CListe<CArc*>(GRAParam.LISGRAArc);
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

const CListe<CSommet*>& CGraphe::GRALireSommet()const
{
	return LISGRASommet;
}

CListe<CArc*>& CGraphe::GRALireArc()
{
	return LISGRAArc;
}

void CGraphe::GRAAjouterSommet(CSommet* pSommet)
{
	LISGRASommet.LISModifierTaille(LISGRASommet.LISLireTaille() + 1);
	LISGRASommet[LISGRASommet.LISLireTaille() - 1] = pSommet;
}

void CGraphe::GRAAjouterArc(CArc* pArc)
{
	LISGRAArc.LISModifierTaille(LISGRAArc.LISLireTaille() + 1);
	LISGRAArc[LISGRAArc.LISLireTaille() - 1] = pArc;
}

void CGraphe::GRAAfficherGraphe()
const CListe<CArc*>& CGraphe::GRALireArc()const
{
	return LISGRAArc;
}

void CGraphe::GRAAfficherGraphe()const
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

void CGraphe::GRAAfficherGrapheGraphique()const
{

}

CGraphe& CGraphe::operator=(const CGraphe& GRAParam)
{
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet);
	LISGRAArc = CListe<CArc*>(GRAParam.LISGRAArc);

	return *this;
}
