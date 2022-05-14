#include "CAnalyseurSyntaxique.h"


CGraphe& CAnalyseurSyntaxique::ANSAnalyserFichier(const char* pcCheminFichier)
{
	//Appel de l'analyseur lexical qui retourne la liste des mots dans l'odre contenu dans le fichier
	CListe<char*> pcListeMots = CAnalyseurLexical::ANLAnalyserFichier(pcCheminFichier);

	/*
	//(debug) affiche les mots recuperes
	for (unsigned int uiBoucle = 0; uiBoucle < (pcListeMots).LISLireTaille(); uiBoucle++) {
		cout << (pcListeMots)[uiBoucle] << endl;
	}
	*/	
	
	int nbSommet = ANSExtraireNbSommet(pcListeMots);
	/*
	cout << nbSommet << endl;
	*/

	int nbArc = ANSExtraireNbArc(pcListeMots);
	/*
	cout << nbArc << endl;
	*/

	CListe<int> listeSommet = ANSExtraireSommets(pcListeMots, nbSommet);
	/*
	//(debug) affiche les numeros des sommets
	for (unsigned int uiBoucle = 0; uiBoucle < listeSommet.LISLireTaille(); uiBoucle++) {
		cout << listeSommet[uiBoucle] << endl;
	}
	*/

	CListe<int> listeArc = ANSExtraireArcs(pcListeMots, nbArc);
	/*
	//(debug) affiche le depart des arcs et la destination des arcs
	for (unsigned int uiBoucle = 0; uiBoucle < listeArc.LISLireTaille(); uiBoucle++) {
		cout << listeArc[uiBoucle] << endl;
	}
	*/

	//Creation du graphe
	CGraphe* monGraphe = new CGraphe();

	//Creation et ajout des sommets au graphe (sans les arcs)
	for (unsigned int uiBoucle = 0; uiBoucle < nbSommet; uiBoucle++) {
		(*monGraphe).GRAAjouterSommet(new CSommet(listeSommet[uiBoucle]));
	}

	//Creation et ajout des arcs dans les Sommets
	for (unsigned int uiBoucle = 0; uiBoucle < nbArc; uiBoucle++) {
		CArc* pArc = new CArc(listeArc[uiBoucle * 2 + 1]);
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < (*monGraphe).GRALireSommet().LISLireTaille(); uiBoucleJ++) {
			//Si l'arc doit arriver part de ce sommet -> ajouter l'arc aux partants
			if ((*monGraphe).GRALireSommet()[uiBoucleJ]->SOMLireNumero() == listeArc[uiBoucle * 2]) {
				(*monGraphe).GRALireSommet()[uiBoucleJ]->SOMAjouterPartant(pArc);
			}
			//Si l'arc doit arriver arrive a ce sommet -> ajouter l'arc aux arrivants
			if ((*monGraphe).GRALireSommet()[uiBoucleJ]->SOMLireNumero() == pArc->ARCLireDestination()) {
				(*monGraphe).GRALireSommet()[uiBoucleJ]->SOMAjouterArrivant(pArc);
			}
		}
	}

	//libere la memore de la liste des mots
	for (unsigned int uiBoucle = 0; uiBoucle < pcListeMots.LISLireTaille(); uiBoucle++) {
		if (pcListeMots[uiBoucle]) {
			free(pcListeMots[uiBoucle]);
		}
	}


	//question est ce qu'il faut creer le grapeh en tant qu'un nouvel objet ?
	return *monGraphe;
}

int CAnalyseurSyntaxique::ANSExtraireNbSommet(CListe<char*> pcLISListeMot)
{
	int nbSommet = -1;
	for (unsigned int uiBoucle = 0; uiBoucle < pcLISListeMot.LISLireTaille(); uiBoucle++) {
		if (strcmp(pcLISListeMot[uiBoucle],"NBSommets") == 0) {
			nbSommet = atoi(pcLISListeMot[uiBoucle + 1]);
		}
	}
	if (nbSommet < 1) {
		throw CException(999, "Pas de nombre de sommets déclaré dans le fichier texte");
	}
	return nbSommet;
}

int CAnalyseurSyntaxique::ANSExtraireNbArc(CListe<char*> pcLISListeMot)
{
	int nbArc = -1;
	for (unsigned int uiBoucle = 0; uiBoucle < pcLISListeMot.LISLireTaille(); uiBoucle++) {
		if (strcmp(pcLISListeMot[uiBoucle], "NBArcs") == 0) {
			nbArc = atoi(pcLISListeMot[uiBoucle + 1]);
		}
	}
	if (nbArc < 1) {
		throw CException(998, "Pas de nombre d'arc déclaré dans le fichier texte");
	}
	return nbArc;
}

CListe<int> CAnalyseurSyntaxique::ANSExtraireSommets(CListe<char*> pcLISListeMot, int iNbSommet)
{
	CListe<int> listeNumSommet = CListe<int>(0);

	for (unsigned int uiBoucleI = 0; uiBoucleI < pcLISListeMot.LISLireTaille(); uiBoucleI++) {
		if (strcmp(pcLISListeMot[uiBoucleI], "Sommets") == 0 && strcmp(pcLISListeMot[uiBoucleI + 1], "[") == 0) {
			int iIndice = uiBoucleI + 2;
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < iNbSommet * 2; uiBoucleJ += 2) {
				if (strcmp(pcLISListeMot[iIndice + uiBoucleJ], "Numero") == 0) {
					listeNumSommet.LISModifierTaille(listeNumSommet.LISLireTaille() + 1);
					listeNumSommet[listeNumSommet.LISLireTaille() - 1] = atoi(pcLISListeMot[iIndice + uiBoucleJ + 1]);
				}
			}
		}
	}

	if (listeNumSommet.LISLireTaille() != iNbSommet) {
		throw CException(997, "Le nombre de sommet défini est different du nomnbre de sommet annonce");
	}

	return listeNumSommet;
}

CListe<int> CAnalyseurSyntaxique::ANSExtraireArcs(CListe<char*> pcLISListeMot, int iNbArc)
{
	CListe<int> listeNumArc = CListe<int>(0);

	for (unsigned int uiBoucleI = 0; uiBoucleI < pcLISListeMot.LISLireTaille(); uiBoucleI++) {
		if (strcmp(pcLISListeMot[uiBoucleI], "Arcs") == 0 && strcmp(pcLISListeMot[uiBoucleI + 1], "[") == 0) {
			int iIndice = uiBoucleI + 2;
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < iNbArc * 4; uiBoucleJ += 4) {
				if (strcmp(pcLISListeMot[iIndice + uiBoucleJ], "Debut") == 0) {
					listeNumArc.LISModifierTaille(listeNumArc.LISLireTaille() + 1);
					listeNumArc[listeNumArc.LISLireTaille() - 1] = atoi(pcLISListeMot[iIndice + uiBoucleJ + 1]);
				}
				else {
					throw CException(996, "Arc mal défini (Debut=x, Fin=x)");
				}
				if (strcmp(pcLISListeMot[iIndice + uiBoucleJ + 2], "Fin") == 0) {
					listeNumArc.LISModifierTaille(listeNumArc.LISLireTaille() + 1);
					listeNumArc[listeNumArc.LISLireTaille() - 1] = atoi(pcLISListeMot[iIndice + uiBoucleJ + 3]);
				}
				else {
					throw CException(996, "Arc mal défini (Debut=x, Fin=x)");
				}
			}
		}
	}
	
	if (listeNumArc.LISLireTaille() != iNbArc*2) {
		throw CException(997, "Le nombre de sommet défini est different du nomnbre de sommet annonce");
	}

	return listeNumArc;
}

