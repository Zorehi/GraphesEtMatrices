#include "CParseur.h"


char* CParseur::PARLireLigne(FILE* pFILFichier)
{
	//Si pas de fichier -> Erreur
	if (pFILFichier == NULL) {
		throw CException(160, "Exception : Absence de fichier à ce chemin");
	}

	char* pcChaine = (char*)malloc(sizeof(char) * 64);
	if (pcChaine == NULL) {
		throw CException(170, "Exception : Erreur d'allocation");
	}

	fgets(pcChaine, 64, pFILFichier);

	if (strcmp(pcChaine, "\n\0") == 0) {
		char* pcChaine2 = PARLireLigne(pFILFichier);
		free(pcChaine);
		errno_t err = strcpy_s(pcChaine, 64,  pcChaine2);
		if (err != 0) {
			throw CException(170, "Exception : Erreur lors d'une copie d'une chaine de caractere");
		}
		if (pcChaine2) {
			free(pcChaine2);
		}
	}

	return pcChaine;
}


CMatricePlus<double>& CParseur::PARLirefichier(const char * pcNomFichier)
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

	//Je considere size_t comme un unsigned int pour le nommage de la variable, à voir avec le prof
	size_t uiLongueur;
	size_t uiLongueur2;

	//Lecture et interpretation de la premiere ligne (type de la matrice)
	char* pcLigneMatrice = PARLireLigne(pFILFichier);
	
	uiLongueur = strcspn(pcLigneMatrice, "=") + 1; //Cerche le "=" de la ligne TypeMatrice= et garde l'index du charactere suivant
	uiLongueur += strspn(pcLigneMatrice + uiLongueur, pcEspace); //Garde l'index du premier non espace apres le "="
	uiLongueur2 = strcspn(pcLigneMatrice + uiLongueur, pcSeparateurs) - 1; //Trouve l'index du premier charactere signifiant la fin du type (pcSeparators)
	char pcTypeMatrice[20];
	strncpy_s(pcTypeMatrice, pcLigneMatrice + uiLongueur, uiLongueur2); //Copie le type de la matrice dans pcTypeMatrice
	pcTypeMatrice[uiLongueur2] = '\0'; //Ajoute le caractere de fin de chaine à pcTypeMatrice

	if (pcLigneMatrice) {
		free(pcLigneMatrice);
	}

	//Erreur si le type de la matrice du fichier n'est pas double
	if (strcmp(pcTypeMatrice, "double") != 0) {
		throw CException(190, "Exception : Mauvais type de matrice renseigne dans le fichier");
	}
	//cout << "Type = " << pcTypeMatrice << "\n"; //(debug) Affiche le type de la matrice

	//Lecture et interpretation de la seconde ligne (nombre de lignes)

	char* pcLigneLigne = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneLigne, pcChiffres);
	unsigned int uiNbLignes = atoi(pcLigneLigne + uiLongueur);

	if (pcLigneLigne) {
		free(pcLigneLigne);
	}
	//cout << "nbLignes = " << uiNbLignes << "\n"; //(debug) Affiche le nombre de ligne de la matrice

	//Lecture et interpretation de la troisieme ligne (nombre de colonnes)
	char* pcLigneColonne = PARLireLigne(pFILFichier);
	uiLongueur = strcspn(pcLigneColonne, pcChiffres);
	unsigned int uiNbColonnes = atoi(pcLigneColonne + uiLongueur);

	if (pcLigneColonne) {
		free(pcLigneColonne);
	}
	//cout << "nbColonnes = " << uiNbColonnes << "\n"; //(debug) Affiche le nombre de colonnes de la matrice

	//Creation de la matrice
	CMatricePlus<double>* MAPMatrice = new CMatricePlus<double>(uiNbLignes, uiNbColonnes);

	//Saute la ligne "Matrice=[
	char* pcChaine = PARLireLigne(pFILFichier);
	if (pcChaine) {
		free(pcChaine);
	}

	//Lecture et interpretation des nblignes prochaines lignes (elements de la matrice)
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiNbLignes; uiBoucleI++) {
		char* pcLigne = PARLireLigne(pFILFichier);
		uiLongueur = 0;
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbColonnes; uiBoucleJ++) {
			uiLongueur += strcspn(pcLigne + uiLongueur, pcChiffres);
			double iElement = atof(pcLigne + uiLongueur);
			(*MAPMatrice)[uiBoucleI][uiBoucleJ] = iElement;
			uiLongueur += strcspn(pcLigne + uiLongueur, pcEspace);
		}
		if (pcLigne) {
			free(pcLigne);
		}
	}

	_fcloseall();

	return *MAPMatrice;
}

