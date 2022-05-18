/**
 * @file CGrapheOperation.cpp
 * @author LJ BV JM
 * @brief Contient la defintion des methodes de la classe CGrapheOperation
 * CGrapheOperation permet de faire des operations sur un Graphe
 * 
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CGrapheOperation.h"

CGraphe CGrapheOperation::GROInverserArc(const CGraphe& GRAArg)
{
	CGraphe* GrapheNew = new CGraphe(); //graphnew doit avoir tout les sommets de graag mais vides
	unsigned int uiNombreSommet = GRAArg.GRALireSommet().LISLireTaille();

	for (int iBoucle1 = 0; iBoucle1 < uiNombreSommet; iBoucle1++) { //pour chaque Sommet dans GRAArg
		GrapheNew->GRAAjouterSommet(GRAArg.GRALireSommet()[iBoucle1]); // on ajoute le sommet de GRAArg sur GrapheNew
	}
	for (int iBoucle2 = 0; iBoucle2 < uiNombreSommet; iBoucle2++) { //pour chaque Sommet dans GRAArg
		unsigned int uiNombreArcPartant = GRAArg.GRALireSommet()[iBoucle2]->SOMLirePartant().LISLireTaille();

		for (int iBoucle3 = 0; iBoucle3 < uiNombreArcPartant; iBoucle3++) { // pour chaque arcPartant dans chaque sommet dans GRAArg
			CArc* ArcNew = new CArc(GRAArg.GRALireSommet()[iBoucle2]->SOMLireNumero()); // creation d'un arc avec destination sur le sommet ou l'on est
			// ajout de l'arc au sommet d'ou il part 
			int DestiNewDepart = GRAArg.GRALireSommet()[iBoucle2]->SOMLirePartant()[iBoucle3]->ARCLireDestination(); // numéro du sommet d'où va partir le nouveau arc


			// on cherche l'indice dans la liste des sommets, du sommet d'ou va partir le nouveau arc
			bool trouve = false;
			int iBoucle4 = 0;
			while ((iBoucle4 < uiNombreSommet) && (trouve == false)) {
				int iNumTemp = GRAArg.GRALireSommet()[iBoucle4]->SOMLireNumero();
				if (iNumTemp == DestiNewDepart){
					trouve = true;
				}
				else {
					iBoucle4++;
				}

			}
			GrapheNew->GRALireSommet()[iBoucle4]->SOMAjouterPartant(ArcNew);
		}
	}
	return *GrapheNew;
}
