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
	CGraphe GrapheNew(GrapheOriente); //graphnew doit avoir tout les sommets de graag mais vides
	unsigned int uiNombreSommet = GRAArg.GRALireSommet().LISLireTaille();

	for (int iBoucle1 = 0; iBoucle1 < uiNombreSommet; iBoucle1++) { //pour chaque Sommet dans GRAArg
		// on crée des nouveaux sommets dans GrapheNew ayant les mêmes numéros que ceux dans GRAArg
		GrapheNew.GRAAjouterSommet(new CSommet(GRAArg.GRALireSommet()[iBoucle1]->SOMLireNumero())); 
	}
	for (int iBoucle2 = 0; iBoucle2 < uiNombreSommet; iBoucle2++) { //pour chaque Sommet dans GRAArg
		unsigned int uiNombreArcPartant = GRAArg.GRALireSommet()[iBoucle2]->SOMLirePartant().LISLireTaille();

		for (int iBoucle3 = 0; iBoucle3 < uiNombreArcPartant; iBoucle3++) { // pour chaque arcPartant dans chaque sommet dans GRAArg
			int destination = GRAArg.GRALireSommet()[iBoucle2]->SOMLireNumero(); // numéro du sommet de destination du nouveau arc
			int depart = GRAArg.GRALireSommet()[iBoucle2]->SOMLirePartant()[iBoucle3]->ARCLireDestination(); // numéro du sommet d'où va partir le nouveau arc

			GrapheNew.GRAAjouterArc(depart, destination); //ajout de l'arc dans les sommets arrivant et partant du nouveau graphe

		}
	}
	return GrapheNew;
}

CGraphe CGrapheOperation::GROCreeNonOriente(const CGraphe& GRAArgOriente)
{
	CGraphe GrapheNew(GrapheNonOriente); //graphnew doit avoir tout les sommets de graag mais vides
	unsigned int uiNombreSommet = GRAArgOriente.GRALireSommet().LISLireTaille();

	for (int iBoucleI = 0; iBoucleI < uiNombreSommet; iBoucleI++) { //pour chaque Sommet dans GRAArgOriente
		// on crée des nouveaux sommets dans GrapheNew ayant les mêmes numéros que ceux dans GRAArgOriente
		GrapheNew.GRAAjouterSommet(new CSommet(GRAArgOriente.GRALireSommet()[iBoucleI]->SOMLireNumero()));
	}
	for (int iBoucleI = 0; iBoucleI < uiNombreSommet; iBoucleI++) { //pour chaque Sommet dans GRAArgOriente
		unsigned int uiNombreArcPartant = GRAArgOriente.GRALireSommet()[iBoucleI]->SOMLirePartant().LISLireTaille();

		for (int iBoucleJ = 0; iBoucleJ < uiNombreArcPartant; iBoucleJ++) { // pour chaque arcPartant dans chaque sommet dans GRAArgOriente
			int destination = GRAArgOriente.GRALireSommet()[iBoucleI]->SOMLireNumero(); // numéro du sommet de destination du nouveau arc
			int depart = GRAArgOriente.GRALireSommet()[iBoucleI]->SOMLirePartant()[iBoucleJ]->ARCLireDestination(); // numéro du sommet d'où va partir le nouveau arc

			GrapheNew.GRAAjouterArc(depart, destination); //ajout de l'arc dans les sommets arrivant et partant du nouveau graphe
			GrapheNew.GRAAjouterArc(destination, depart);
		}
	}
	return GrapheNew;
}
