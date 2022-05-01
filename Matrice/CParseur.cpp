#include "CParseur.h"
#include "CMatricePlus.h"
#include <stdio.h>

CParseur::CParseur()
{
	pcPARFichier = NULL;
	pFILPARFichier = NULL;
}


CParseur::CParseur(const char* pcCheminFichier)
{
	pcPARFichier = (char*)pcCheminFichier;
	pFILPARFichier = NULL;
}

char* CParseur::PARLireChemin()
{
	return pcPARFichier;
}

const char* CParseur::PARLireLigne()
{
	//Si pas de fichier -> Erreur
	if (pFILPARFichier == NULL) {
		throw "pas de fichier à ce chemin";
	}

	char* pcChaine = (char*)malloc(sizeof(char) * 64);
	if (pcChaine == NULL) {
		throw "erreur d'allocation";
	}

	fgets(pcChaine, 64, pFILPARFichier);

	return pcChaine;
}


CMatricePlus<double>& CParseur::PARLirefichier()
{
	//Ouverture du fichier
	errno_t err = fopen_s(&pFILPARFichier, pcPARFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw "Erreur lors de l'ouverture du fichier";
	}

	const char* pcChiffres = "-1234567890";
	const char* pcEspace = " ";
	const char* pcSeparateurs = "\0\n\r";

	//Je considere size_t comme un unsigned int pour le nommage de la variable, à voir avec le prof
	size_t uiLongueur;
	size_t uiLongueur2;

	//Lecture et interpretation de la premiere ligne (type de la matrice)
	const char* pcLigneMatrice = PARLireLigne();
	
	uiLongueur = strcspn(pcLigneMatrice, "=");
	uiLongueur2 = strcspn(pcLigneMatrice + uiLongueur + 1, pcSeparateurs) - 1;
	char pcTypeMatrice[20];
	strncpy_s(pcTypeMatrice, pcLigneMatrice + uiLongueur + 1, uiLongueur2);

	//Erreur si le type de la matrice du fichier n'est pas double
	if (strcmp(pcTypeMatrice, "double") != 0) {
		throw "le type de la matrice rentrée dans le fichier n'est pas (double)";
		exit;
	}
	cout << "Type = " << pcTypeMatrice << "\n"; //(debug) Affiche le type de la matrice

	//Lecture et interpretation de la seconde ligne (nombre de lignes)
	
	const char* pcLigneLigne = PARLireLigne();
	uiLongueur = strcspn(pcLigneLigne, pcChiffres);
	unsigned int uiNbLignes = atof(pcLigneLigne + uiLongueur);
	cout << "nbLignes = " << uiNbLignes << "\n"; //(debug) Affiche le nombre de ligne de la matrice

	//Lecture et interpretation de la troisieme ligne (nombre de colonnes)
	const char* pcLigneColonne = PARLireLigne();
	uiLongueur = strcspn(pcLigneColonne, pcChiffres);
	unsigned int uiNbColonnes = atof(pcLigneColonne + uiLongueur);
	cout << "nbColonnes = " << uiNbColonnes << "\n"; //(debug) Affiche le nombre de colonnes de la matrice

	//Creation de la matrice
	CMatricePlus<double>* MAPMatrice = new CMatricePlus<double>(uiNbLignes, uiNbColonnes);

	//Saute la ligne "Matrice=[
	PARLireLigne();

	//Lecture et interpretation des nblignes prochaines lignes (elements de la matrice)
	for (int iBoucleI = 0; iBoucleI < uiNbLignes; iBoucleI++) {
		const char* pcLigne = PARLireLigne();
		uiLongueur = 0;
		for (int iBoucleJ = 0; iBoucleJ < uiNbColonnes; iBoucleJ++) {
			uiLongueur += strcspn(pcLigne + uiLongueur, pcChiffres);
			double iElement = atof(pcLigne + uiLongueur);
			(*MAPMatrice)[iBoucleI][iBoucleJ] = iElement;
			uiLongueur += strcspn(pcLigne + uiLongueur, pcEspace);
		}
	}
	
	return *MAPMatrice;
}

