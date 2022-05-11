/**
 * @file CParseur.cpp
 * @author LJ BV JM
 * @brief Contient les definitions des methodes de la classe CParseur
 * CParseur contient des methodes statiques permettant
 * de creer des graphes a partir de fichier
 *
 * @version 0.1
 * @date 2022-05-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "CParseur.h"
#include "CException.h"

using namespace std;

char* CParseur::PARLireLigne(FILE* pFILFichier)
{
	//Si pas de fichier -> Erreur
	if (pFILFichier == NULL) {
		throw CException(160, "Exception : Absence de fichier a ce chemin");
	}

	char* pcChaine = (char*)malloc(sizeof(char) * 64);
	if (pcChaine == NULL) {
		throw CException(170, "Exception : Erreur d'allocation");
	}

	fgets(pcChaine, 64, pFILFichier);


	//Si la ligne est seulement un retour a la ligne -> lire la ligne suivante
	if (strcmp(pcChaine, "\n\0") == 0) {
		char* pcChaine2 = PARLireLigne(pFILFichier);
		free(pcChaine);
		errno_t err = strcpy_s(pcChaine, 64, pcChaine2);
		if (err != 0) {
			throw CException(170, "Exception : Erreur lors d'une copie d'une chaine de caractere");
		}
		if (pcChaine2) {
			free(pcChaine2);
		}
	}

	return pcChaine;
}


CGraphe CParseur::PARLirefichier(const char* pcNomFichier)
{
	//Ouverture du fichier
	FILE* pFILFichier;
	errno_t err = fopen_s(&pFILFichier, pcNomFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw CException(180, "Exception : Erreur lors de l'ouverture du fichier");
	}

	const char* pcChiffres = "-1234567890";
	const char* pcEspace = " ";
	const char* pcSeparateurs = " \0\n\r";

	size_t uiLongueur;

	unsigned int uiNbSommet;
	unsigned int uiNbArc;
	int* piNomsSommet;
	int** ppiArcs;



	//Extrait le nombre de sommet
	//Lecture et interpretation de la premiere ligne (Nombre de sommets)
	char* pcLigneNbSommet = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneNbSommet, "=") + 1; //Cerche le "=" de la ligne NBSommets= et garde l'index du charactere suivant
	uiNbSommet = atoi(pcLigneNbSommet + uiLongueur);

	free(pcLigneNbSommet);

	cout << "Nombre de sommets : " << uiNbSommet << "\n"; //(debug)


	//Extrait le nombre d'arc
	//Lecture et interpretation de la premiere ligne (Nombre d'arc)
	char* pcLigneNbArc = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneNbArc, "=") + 1; //Cerche le "=" de la ligne NBArcs= et garde l'index du charactere suivant
	uiNbArc = atoi(pcLigneNbArc + uiLongueur);

	free(pcLigneNbArc);

	cout << "Nombre d'arc : " << uiNbArc << "\n"; //(debug)


	//Passe la ligne "Sommets=["
	char* pcLigne = PARLireLigne(pFILFichier);
	free(pcLigne);

	//Extrait le numero de chaque sommet (dans l'ordre)
	piNomsSommet = (int*)malloc(uiNbSommet * sizeof(int));

	for (unsigned int uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		char* pcLigneSommet = PARLireLigne(pFILFichier);
		uiLongueur = strcspn(pcLigneSommet, "=") + 1; //Cerche le "=" de la ligne Numero= et garde l'index du charactere suivant
		piNomsSommet[uiBoucle] = atoi(pcLigneSommet + uiLongueur);

		cout << "Numero : " << piNomsSommet[uiBoucle] << "\n"; //(debug)
	}


	//Passe la ligne "]"
	char* pcLigne1 = PARLireLigne(pFILFichier);
	free(pcLigne1);

	//Passe la ligne "Arcs=["
	char* pcLigne2 = PARLireLigne(pFILFichier);
	free(pcLigne2);

	//Extrait les infos de chaque arcs (Debut, Fin)
	ppiArcs = (int**)malloc(uiNbArc * sizeof(int*));

	for (unsigned int uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		ppiArcs[uiBoucle] = (int*)malloc(2 * sizeof(int));

		char* pcLigneArc = PARLireLigne(pFILFichier);
		uiLongueur = strcspn(pcLigneArc, "=") + 1; //Cerche le "=" de la ligne Numero= et garde l'index du charactere suivant
		ppiArcs[uiBoucle][0] = atoi(pcLigneArc + uiLongueur);

		uiLongueur += strcspn(pcLigneArc + uiLongueur, "=") + 1; //Cerche le "=" de la ligne Numero= et garde l'index du charactere suivant
		ppiArcs[uiBoucle][1] = atoi(pcLigneArc + uiLongueur);

		cout << "Debut : " << ppiArcs[uiBoucle][0] << " Fin : " << ppiArcs[uiBoucle][1] << "\n"; //(debug)
	}


	_fcloseall();
	return CGraphe();
}

