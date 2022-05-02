#include "CParseur.h"


const char* CParseur::PARLireLigne(FILE* pFILFichier)
{
	//Si pas de fichier -> Erreur
	if (pFILFichier == NULL) {
		throw "pas de fichier à ce chemin";
	}

	char* pcChaine = (char*)malloc(sizeof(char) * 64);
	if (pcChaine == NULL) {
		throw "erreur d'allocation";
	}

	fgets(pcChaine, 64, pFILFichier);

	return pcChaine;
}


CMatricePlus<double>& CParseur::PARLirefichier(const char * pcFichier)
{
	//Ouverture du fichier
	FILE* pFILFichier;
	errno_t err = fopen_s(&pFILFichier, pcFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw CException(1, "Erreur lors de l'ouverture du fichier");
	}

	const char* pcChiffres = "-1234567890";
	const char* pcEspace = " ";
	const char* pcSeparateurs = "\0\n\r";

	//Je considere size_t comme un unsigned int pour le nommage de la variable, à voir avec le prof
	size_t uiLongueur;
	size_t uiLongueur2;

	//Lecture et interpretation de la premiere ligne (type de la matrice)
	const char* pcLigneMatrice = PARLireLigne(pFILFichier);
	
	uiLongueur = strcspn(pcLigneMatrice, "=");
	uiLongueur2 = strcspn(pcLigneMatrice + uiLongueur + 1, pcSeparateurs) - 1;
	char pcTypeMatrice[20];
	strncpy_s(pcTypeMatrice, pcLigneMatrice + uiLongueur + 1, uiLongueur2);
	pcTypeMatrice[uiLongueur2] = '\0';

	//Erreur si le type de la matrice du fichier n'est pas double
	if (strcmp(pcTypeMatrice, "double") != 0) {
		throw CException(0, "Mauvais type de matrice renseigne dans le fichier");
	}
	cout << "Type = " << pcTypeMatrice << "\n"; //(debug) Affiche le type de la matrice

	//Lecture et interpretation de la seconde ligne (nombre de lignes)

	const char* pcLigneLigne = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneLigne, pcChiffres);
	unsigned int uiNbLignes = atoi(pcLigneLigne + uiLongueur);
	cout << "nbLignes = " << uiNbLignes << "\n"; //(debug) Affiche le nombre de ligne de la matrice

	//Lecture et interpretation de la troisieme ligne (nombre de colonnes)
	const char* pcLigneColonne = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneColonne, pcChiffres);
	unsigned int uiNbColonnes = atoi(pcLigneColonne + uiLongueur);
	cout << "nbColonnes = " << uiNbColonnes << "\n"; //(debug) Affiche le nombre de colonnes de la matrice

	//Creation de la matrice
	CMatricePlus<double>* MAPMatrice = new CMatricePlus<double>(uiNbLignes, uiNbColonnes);

	//Saute la ligne "Matrice=[
	PARLireLigne(pFILFichier);

	//Lecture et interpretation des nblignes prochaines lignes (elements de la matrice)
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiNbLignes; uiBoucleI++) {
		const char* pcLigne = PARLireLigne(pFILFichier);
		uiLongueur = 0;
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbColonnes; uiBoucleJ++) {
			uiLongueur += strcspn(pcLigne + uiLongueur, pcChiffres);
			double iElement = atof(pcLigne + uiLongueur);
			(*MAPMatrice)[uiBoucleI][uiBoucleJ] = iElement;
			uiLongueur += strcspn(pcLigne + uiLongueur, pcEspace);
		}
	}

	return *MAPMatrice;
}

