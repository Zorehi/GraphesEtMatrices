/**
 * @file CAnalyseurSyntaxique.cpp
 * @author LJ BV JM
 * @brief Contient la definition des methodes de la classe CAnalyseurSyntaxique
 * CAnalyseurSyntaxique permet de creer un Graphe avec les donnees
 * que CAnalyseurLexicale lui donne
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CAnalyseurSyntaxique.h"

CGraphe CAnalyseurSyntaxique::ANSAnalyserFichier(const char* pcCheminFichier)
{
	//Appel de l'analyseur lexical qui retourne la liste des mots dans l'odre contenu dans le fichier
	CListe<char*> LISListeMots = CAnalyseurLexical::ANLAnalyserFichier(pcCheminFichier);

	/*
	//(debug) affiche les mots recuperes
	for (unsigned int uiBoucle = 0; uiBoucle < (LISListeMots).LISLireTaille(); uiBoucle++) {
		cout << (LISListeMots)[uiBoucle] << endl;
	}
	*/	
	
	int iNbSommet = ANSExtraireNbSommet(LISListeMots);
	/*
	cout << iNbSommet << endl;
	*/

	int iNbArc = ANSExtraireNbArc(LISListeMots);
	/*
	cout << iNbArc << endl;
	*/

	CListe<int> LISListeSommet = ANSExtraireSommets(LISListeMots, iNbSommet);
	/*
	//(debug) affiche les numeros des sommets
	for (unsigned int uiBoucle = 0; uiBoucle < LISListeSommet.LISLireTaille(); uiBoucle++) {
		cout << LISListeSommet[uiBoucle] << endl;
	}
	*/

	CListe<int> LISListeArc = ANSExtraireArcs(LISListeMots, iNbArc);
	/*
	//(debug) affiche le depart des arcs et la destination des arcs
	for (unsigned int uiBoucle = 0; uiBoucle < LISListeArc.LISLireTaille(); uiBoucle++) {
		cout << LISListeArc[uiBoucle] << endl;
	}
	*/

	//Creation du graphe
	CGraphe GRAMonGraphe;

	//Creation et ajout des sommets au graphe (sans les arcs)
	for (unsigned int uiBoucle = 0; uiBoucle < iNbSommet; uiBoucle++) {
		GRAMonGraphe.GRAAjouterSommet(new CSommet(LISListeSommet[uiBoucle]));
	}

	//Ajout des arcs dans les Sommets
	for (unsigned int uiBoucle = 0; uiBoucle < iNbArc; uiBoucle++) {
		GRAMonGraphe.GRAAjouterArc(LISListeArc[uiBoucle * 2], LISListeArc[uiBoucle * 2 + 1]);
	}

	//Libere la memore de la liste des mots
	for (unsigned int uiBoucle = 0; uiBoucle < LISListeMots.LISLireTaille(); uiBoucle++) {
		if (LISListeMots[uiBoucle]) {
			free(LISListeMots[uiBoucle]);
		}
	}

	//question est ce qu'il faut creer le grapeh en tant qu'un nouvel objet ?
	return GRAMonGraphe;
}

int CAnalyseurSyntaxique::ANSExtraireNbSommet(CListe<char*>& LISListeMot)
{
	int iNbSommet = -1;
	for (unsigned int uiBoucle = 0; uiBoucle < LISListeMot.LISLireTaille(); uiBoucle++) {
		if (strcmp(LISListeMot[uiBoucle], "NBSommets") == 0) {
			iNbSommet = atoi(LISListeMot[uiBoucle + 1]);
		}
	}
	if (iNbSommet < 1) {
		throw CException(999, "Pas de nombre de sommets declare dans le fichier texte");
	}
	return iNbSommet;
}

int CAnalyseurSyntaxique::ANSExtraireNbArc(CListe<char*>& LISListeMot)
{
	int iNbArc = -1;
	for (unsigned int uiBoucle = 0; uiBoucle < LISListeMot.LISLireTaille(); uiBoucle++) {
		if (strcmp(LISListeMot[uiBoucle], "NBArcs") == 0) {
			iNbArc = atoi(LISListeMot[uiBoucle + 1]);
		}
	}
	if (iNbArc < 1) {
		throw CException(998, "Pas de nombre d'arc declare dans le fichier texte");
	}
	return iNbArc;
}

CListe<int> CAnalyseurSyntaxique::ANSExtraireSommets(CListe<char*>& LISListeMot, int iNbSommet)
{
	CListe<int> LISListeNumSommet = CListe<int>(0);

	for (unsigned int uiBoucleI = 0; uiBoucleI < LISListeMot.LISLireTaille(); uiBoucleI++) {
		if (strcmp(LISListeMot[uiBoucleI], "Sommets") == 0 && strcmp(LISListeMot[uiBoucleI + 1], "[") == 0) {
			int iIndice = uiBoucleI + 2;
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < iNbSommet * 2; uiBoucleJ += 2) {
				if (strcmp(LISListeMot[iIndice + uiBoucleJ], "Numero") == 0) {
					LISListeNumSommet.LISModifierTaille(LISListeNumSommet.LISLireTaille() + 1);
					LISListeNumSommet[LISListeNumSommet.LISLireTaille() - 1] = atoi(LISListeMot[iIndice + uiBoucleJ + 1]);
				}
			}
		}
	}

	if (LISListeNumSommet.LISLireTaille() != iNbSommet) {
		throw CException(997, "Le nombre de sommet defini est different du nomnbre de sommet annonce");
	}

	return LISListeNumSommet;
}

CListe<int> CAnalyseurSyntaxique::ANSExtraireArcs(CListe<char*>& LISListeMot, int iNbArc)
{
	CListe<int> LISListeNumArc = CListe<int>(0);

	for (unsigned int uiBoucleI = 0; uiBoucleI < LISListeMot.LISLireTaille(); uiBoucleI++) {
		if (strcmp(LISListeMot[uiBoucleI], "Arcs") == 0 && strcmp(LISListeMot[uiBoucleI + 1], "[") == 0) {
			int iIndice = uiBoucleI + 2;
			for (unsigned int uiBoucleJ = 0; uiBoucleJ < iNbArc * 4; uiBoucleJ += 4) {
				if (strcmp(LISListeMot[iIndice + uiBoucleJ], "Debut") == 0) {
					LISListeNumArc.LISModifierTaille(LISListeNumArc.LISLireTaille() + 1);
					LISListeNumArc[LISListeNumArc.LISLireTaille() - 1] = atoi(LISListeMot[iIndice + uiBoucleJ + 1]);
				}
				else {
					throw CException(996, "Arc mal defini (Debut=x, Fin=x)");
				}
				if (strcmp(LISListeMot[iIndice + uiBoucleJ + 2], "Fin") == 0) {
					LISListeNumArc.LISModifierTaille(LISListeNumArc.LISLireTaille() + 1);
					LISListeNumArc[LISListeNumArc.LISLireTaille() - 1] = atoi(LISListeMot[iIndice + uiBoucleJ + 3]);
				}
				else {
					throw CException(996, "Arc mal defini (Debut=x, Fin=x)");
				}
			}
		}
	}
	
	if (LISListeNumArc.LISLireTaille() != iNbArc*2) {
		throw CException(997, "Le nombre de sommet d�fini est different du nomnbre de sommet annonce");
	}

	return LISListeNumArc;
}

