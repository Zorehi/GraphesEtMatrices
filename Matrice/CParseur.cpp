#include "CParseur.h"
#include "CMatricePlus.h"
#include <stdio.h>

CParseur::CParseur()
{
	pcFichier = NULL;
	pfFichier = NULL;
}


CParseur::CParseur(const char* pcCheminFichier)
{
	pcFichier = (char*)pcCheminFichier;
	pfFichier = NULL;
}

char* CParseur::PARLireChemin()
{
	return pcFichier;
}

const char* CParseur::PARLireLigne()
{
	//Si pas de fichier -> Erreur
	if (pfFichier == NULL) {
		throw "pas de fichier à ce chemin";
	}

	char* chaine = (char*)malloc(sizeof(char) * 64);
	if (chaine == NULL) {
		throw "erreur d'allocation";
	}

	fgets(chaine, 64, pfFichier);

	return chaine;
}


void CParseur::PARLirefichier()
{
	//Ouverture du fichier
	errno_t err = fopen_s(&pfFichier, pcFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw "pas de fichier à ce chemin";
	}

	const char* chiffres = "-1234567890";
	const char* espace = " ";
	const char* separators = "\0\n";
	size_t longueur;
	size_t longueur2;

	//Lecture et interpretation de la premiere ligne (type de la matrice)
	const char* ligneMatrice = PARLireLigne();
	
	longueur = strcspn(ligneMatrice, "=");
	longueur2 = strcspn(ligneMatrice + longueur, separators);
	char typeMatrice[20];
	strncpy_s(typeMatrice, ligneMatrice + longueur + 1, 20);
	cout << "Type = " << typeMatrice;

	//Lecture et interpretation de la seconde ligne (nombre de lignes)
	
	const char* ligneLigne = PARLireLigne();
	longueur = strcspn(ligneLigne, chiffres);
	unsigned int uiNbLignes = atoi(ligneLigne + longueur);
	cout << "nbLignes = " << uiNbLignes << "\n";

	//Lecture et interpretation de la troisieme ligne (nombre de colonnes)
	const char* ligneColonne = PARLireLigne();
	longueur = strcspn(ligneColonne, chiffres);
	unsigned int uiNbColonnes = atoi(ligneColonne + longueur);
	cout << "nbColonnes = " << uiNbColonnes << "\n";

	//Cration de la matrice
	CMatricePlus<int> maMatrice(uiNbLignes, uiNbColonnes);

	//Saute la ligne "Matrice=[
	PARLireLigne();

	//Lecture et interpretation des nblignes prochaines lignes (elements de la matrice)
	for (int i = 0; i < uiNbLignes; i++) {
		const char* ligne = PARLireLigne();
		longueur = 0;
		for (int j = 0; j < uiNbColonnes; j++) {
			longueur += strcspn(ligne + longueur, chiffres);
			int iElement = atoi(ligne + longueur);
			maMatrice[i][j] = iElement;
			longueur += strcspn(ligne + longueur, espace);
		}
	}
	
	maMatrice.MABAfficherMatrice();
	
}

/*
template<class MType>
inline CMatricePlus<MType> CParseur::PARLirefichier()
{
	//Ouverture du fichier
	FILE* fichier = fopen(PARLireChemin(), "r");

	//Si pas de fichier -> Erreur
	if (fichier == NULL) {
		throw "pas de fichier à ce chemin";
	}

	char* chaine = (char*)malloc(sizeof(char) * 32);
	cout << fgets(chaine, 32, fichier);



	
}
*/