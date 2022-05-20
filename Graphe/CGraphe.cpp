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
	uiGRAType = GrapheOriente;
}

CGraphe::CGraphe(unsigned int uiType) 
{
	uiGRAType = uiType;
	LISGRASommet = CListe<CSommet*>();
}

CGraphe::CGraphe(const CGraphe& GRAParam)
{
	uiGRAType = GRAParam.GRALireType();
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet.LISLireTaille());
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet[uiBoucle] = new CSommet(*GRAParam.LISGRASommet[uiBoucle]);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		//Creer les arcs
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < GRAParam.LISGRASommet[uiBoucle]->SOMLirePartant().LISLireTaille(); uiBoucleJ++) {
			GRAAjouterArc(LISGRASommet[uiBoucle]->SOMLireNumero(), GRAParam.LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ]->ARCLireDestination());
		}
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
			if (LISGRASommet[iBoucleI]->SOMLirePartant()[iBoucleJ]) {

				delete LISGRASommet[iBoucleI]->SOMLirePartant()[iBoucleJ];
			}
		}

		delete LISGRASommet[iBoucleI];
	}
}

const CListe<CSommet*>& CGraphe::GRALireSommet()const
{
	return LISGRASommet;
}

const unsigned int CGraphe::GRALireType() const
{
	return uiGRAType;
}

void CGraphe::GRAAjouterSommet(CSommet* pSommet)
{
	unsigned int uiPresent = 0;
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == pSommet->SOMLireNumero()) {
			uiPresent = 1;
		}
	}

	if (uiPresent) {
		delete pSommet;
		throw CException(996, "Au moins deux sommets ont le meme numero");
	}

	LISGRASommet.LISModifierTaille(LISGRASommet.LISLireTaille() + 1);
	LISGRASommet[LISGRASommet.LISLireTaille() - 1] = pSommet;
}

void CGraphe::GRAModifierSommet(CSommet* pSommet, int iNewNum)
{
	GRAModifierSommet(pSommet->SOMLireNumero(), iNewNum);
}

void CGraphe::GRAModifierSommet(int iOldNum, int iNewNum)
{
	unsigned int uiExiste = 0;
	//Parcours tout les sommets pour trouver le sommet a modifier
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		//Si c'est le sommet a modifier
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iOldNum) {
			uiExiste = 1;
			LISGRASommet[uiBoucle]->SOMModifierNumero(iNewNum); //Modifier le numero du sommet
		}
	}

	//Si le sommet a modifier n'a pas ete trouve -> erreur
	if (uiExiste == 0) {
		throw CException(993, "Le sommet a modifier n'existe pas");
	}
}

void CGraphe::GRASupprimerSommet(CSommet* pSommet)
{
	GRASupprimerSommet(pSommet->SOMLireNumero());
}

void CGraphe::GRASupprimerSommet(int iNumSommet)
{
	/*
	//Recherche le sommet
	unsigned int uiNbSommet = LISGRASommet.LISLireTaille();
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iNumSommet) {
			CSommet* SOMSommet = LISGRASommet[uiBoucle];

			//Parcours les arcs partants
			unsigned int uiNbArcPartant = SOMSommet->SOMLirePartant().LISLireTaille();
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbArcPartant; uiBoucleJ++) {
				//Parcours les sommets pour chercher le sommet de destination de l'arc
				for (unsigned int uiBoucleZ = 0; uiBoucleZ < uiNbSommet; uiBoucleZ++) {
					CSommet* SOMSommet2 = LISGRASommet[uiBoucleZ];
					//Si le numero du sommet est le meme que la destination de l'arc
					if (SOMSommet2->SOMLireNumero() == SOMSommet->SOMLirePartant()[uiBoucleJ]->ARCLireDestination()) {

						unsigned int uiNbArcArrivant = SOMSommet2->SOMLireArrivant().LISLireTaille();
						//Cherche l'arc dans la liste des arrivants
						for (unsigned int uiBoucleY = 0; uiBoucleY < uiNbArcArrivant; uiBoucleY++) {
							//Si l'arc est le bon
							if (SOMSommet2->SOMLireArrivant()[uiBoucleY]->ARCLireDestination() == SOMSommet->SOMLireNumero()) {
								//Modifier la liste des arrivants du sommet2 pour qu'elle ne contiennent plus l'arc
								SOMSommet2->SOMLireArrivant().LISSupprimerElement(uiBoucleY);
							}
						}
					}
				}

				//Supprime l'arc partant
				delete SOMSommet->SOMLirePartant()[uiBoucleJ];
			}



			//PArcours tout les sommets
			//Regarde les partants
			//Regarde si le partant a comme direction notre sommet
			//Enleve cet arc partant de la liste des partants

			//Parcours tout les sommets
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbSommet; uiBoucleJ++) {
				CSommet* SOMSommet3 = LISGRASommet[uiBoucleJ];
				unsigned int uiNbPartant = SOMSommet3->SOMLirePartant().LISLireTaille();;
				//Regarde les partants
				for (unsigned int uiBoucleZ = 0; uiBoucleZ < uiNbPartant; uiBoucleZ++) {
					//Regarde si le partant a comme direction notre sommet
					if (SOMSommet3->SOMLirePartant()[uiBoucleZ]->ARCLireDestination() == SOMSommet->SOMLireNumero()) {
						//Enleve cet arc partant de la liste des partants
						SOMSommet3->SOMLirePartant().LISSupprimerElement(uiBoucleZ);
					}
				}
			}

			//Parcours tout les arrivants du sommet pour les supprimer
			for (unsigned int uiBoucle = 0; uiBoucle < SOMSommet->SOMLireArrivant().LISLireTaille(); uiBoucle++) {
				delete SOMSommet->SOMLireArrivant()[uiBoucle];
			}

			//Supprime les deux listes d'arc (arrivant, partant)
			delete SOMSommet->SOMLirePartant();
			delete SOMSommet->SOMLireArrivant();
		}

	}
	*/
}


void CGraphe::GRAAjouterArc(int iDebut, int iDestination)
{
	//Verification que les les sommets de Debut et de Destination existes
	unsigned int uiDebutExiste = 0;
	unsigned int uiDestinationExiste = 0;
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDebut) {
			uiDebutExiste = 1;
		}
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDestination) {
			uiDestinationExiste = 1;
		}
	}
	if (uiDebutExiste == 0) {
		throw CException(995, "Le sommet de depart d'un arc est inexistant");
	}
	if (uiDestinationExiste == 0) {
		throw CException(994, "Le sommet de destination d'un arc est inexistant");
	}

	unsigned int uiArcExiste = 0;
	//Verification que l'arc n'existe pas deja
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDebut) {
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < LISGRASommet[uiBoucle]->SOMLirePartant().LISLireTaille(); uiBoucleJ++) {
				if (LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ]->ARCLireDestination() == iDestination) {
					uiArcExiste = 1;
				}
			}
		}
	}
	if (uiArcExiste == 1) {
		throw CException(993, "L'arc existe deja");
	}

	//Cration de l'arc
	CArc* pARCmonArc = new CArc(iDestination);

	//Ajout de l'arc aux sommets concernes
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDebut) {
			LISGRASommet[uiBoucle]->SOMAjouterPartant(pARCmonArc);
		}
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDestination) {
			LISGRASommet[uiBoucle]->SOMAjouterArrivant(pARCmonArc);
		}
	}

	//Si graphe non oriente, ajout de l'arc inverse
	if (uiGRAType == 1) {
		//Creation de l'arc inverse + ajout de cet arc aux sommets concernes
		CArc* pARCmonArc2 = new CArc(iDestination);
		for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
			if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDestination) {
				LISGRASommet[uiBoucle]->SOMAjouterPartant(pARCmonArc2);
			}
			if (LISGRASommet[uiBoucle]->SOMLireNumero() == iDebut) {
				LISGRASommet[uiBoucle]->SOMAjouterArrivant(pARCmonArc2);
			}
		}
	}
}

void CGraphe::GRAModifierArc(CArc* pArc) {
	
}

void CGraphe::GRASupprimerArc(CArc* pArc) {
	//Parcours la liste des sommets 
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		//Parcours la liste des arcs partant de ce sommet pour voir si il y a l'arc dans les partant
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < LISGRASommet[uiBoucle]->SOMLirePartant().LISLireTaille(); uiBoucleJ++) {
			if (LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ] == pArc) {
				LISGRASommet[uiBoucle]->SOMLirePartant().LISSupprimerElement(uiBoucleJ);
			}
		}

		//Parcours la liste des arcs arrivant de ce sommet pour voir si il y a l'arc dans les arrivant
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < LISGRASommet[uiBoucle]->SOMLireArrivant().LISLireTaille(); uiBoucleJ++) {
			if (LISGRASommet[uiBoucle]->SOMLireArrivant()[uiBoucleJ] == pArc) {
				LISGRASommet[uiBoucle]->SOMLireArrivant().LISSupprimerElement(uiBoucleJ);
			}
		}
	}
}

void CGraphe::GRASupprimerArc(int iProvenance, int iDestination) {
	//Parcours la liste des sommet
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		//Si le sommet correspond au sommet provenance
		if (LISGRASommet[uiBoucle]->SOMLireNumero() == iProvenance) {
			//Cherche l'arc correspondant a la destination
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < LISGRASommet[uiBoucle]->SOMLirePartant().LISLireTaille(); uiBoucleJ++) {
				if (LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ]->ARCLireDestination() == iDestination) {
					//Supprime l'arc en question
					GRASupprimerArc(LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ]);
				}
			}
		}
	}
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
	uiGRAType = GRAParam.GRALireType();
	LISGRASommet = CListe<CSommet*>(GRAParam.LISGRASommet.LISLireTaille());
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet[uiBoucle] = new CSommet(*GRAParam.LISGRASommet[uiBoucle]);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < GRAParam.LISGRASommet.LISLireTaille(); uiBoucle++) {
		//Creer les arcs
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < GRAParam.LISGRASommet[uiBoucle]->SOMLirePartant().LISLireTaille(); uiBoucleJ++) {
			GRAAjouterArc(LISGRASommet[uiBoucle]->SOMLireNumero(), GRAParam.LISGRASommet[uiBoucle]->SOMLirePartant()[uiBoucleJ]->ARCLireDestination());
		}

	}

	return *this;
}