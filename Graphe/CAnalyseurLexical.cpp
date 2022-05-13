#include "CAnalyseurLexical.h"

void CAnalyseurLexical::ANLAnalyserFichier(const char* pcNomFichier)
{
	//Ouverture du fichier
	FILE* pFILFichier;
	errno_t err = fopen_s(&pFILFichier, pcNomFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw CException(180, "Exception : Erreur lors de l'ouverture du fichier");
	}

	CListe<char**>* pLISTabCorrespondance = new CListe<char**>(0);

	char* pcChaine = ANLLireProchaineLigne(pFILFichier);
	//Tant que l'on est pas arrive a la fin du fichier on analyse chaque ligne les unes apres les autres
	while (pcChaine[0] != '\0') {
		
		ANLExtraireInfoLigne(pcChaine, *pLISTabCorrespondance);
		//cout << pcChaine;

		free(pcChaine);
		pcChaine = ANLLireProchaineLigne(pFILFichier);
	}
	free(pcChaine);


}

char* CAnalyseurLexical::ANLLireProchaineLigne(FILE* pFILFichier)
{
	//Si pas de fichier -> Erreur
	if (pFILFichier == NULL) {
		throw CException(160, "Exception : Absence de fichier a ce chemin"); ///////!!!!!!! mauvais nom d'execption !!!!!///////
	}
	
	char* pcChaine = (char*)malloc(sizeof(char) * 64);
	
	if (!pcChaine) {
		throw CException(170, "Exception : Erreur d'allocation");
	}

	if (feof(pFILFichier) == 0) {
		fgets(pcChaine, 64, pFILFichier);
	}
	else {
		pcChaine[0] = '\0';
	}

	return pcChaine;

}

void CAnalyseurLexical::ANLExtraireInfoLigne(const char* pcLigne, CListe<char**>& pLISTabCorrespondance)
{
	//Compte le nombre d'elements que l'on va avoir (nombre de "=" dans la ligne + 1)
	unsigned int uiNbElement = 0;
	for (unsigned int uiBoucle = 0; uiBoucle < strlen(pcLigne); uiBoucle++) {
		if (pcLigne[uiBoucle] == '=') {
			uiNbElement++;
		}
	}
	if (uiNbElement == 0) {
		uiNbElement = 1;
	}
	else {
		uiNbElement = uiNbElement * 2;
	}
	char* pcEnCours = (char*)pcLigne;
	//Separe les infos de la ligne
	char** ppcCorrespondanceUnMot = (char**)malloc(2 * sizeof(char*));
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbElement; uiBoucle++) {
		if (uiBoucle % 2 == 0) {
			
			char** ppcCorrespondanceUnMot = (char**)malloc(2 * sizeof(char*));
		}
		
		// Verification de l'allocation
		if (ppcCorrespondanceUnMot == NULL) {
			throw CException(170, "Erreur d'allocation");
		}
		//Enleve les espaces au debut qui pourrait etre avant le mot
		pcEnCours += strspn(pcEnCours, " ");
			
		//Trouve l'indice du prochain "=, \r\n"
		size_t iIndex = strcspn(pcEnCours, "=, \r\n");
		char* pcMot = (char*)malloc((iIndex+1) * sizeof(char));
		//Verification de l'allocation
		if (pcMot == NULL) {
			throw CException(170, "Erreur d'allocation");
		}

		strncpy_s(pcMot, (iIndex + 1), pcEnCours, iIndex);
		pcMot[iIndex] = '\0';
		ppcCorrespondanceUnMot[uiBoucle%2] = pcMot;
		//cout << "Mot : " << pcMot << endl;

		pcEnCours += iIndex + 1;

		if (uiBoucle % 2 != 0) {
			int tailleListe = pLISTabCorrespondance.LISLireTaille() + 1;
			pLISTabCorrespondance.LISModifierTaille(tailleListe);
			pLISTabCorrespondance[tailleListe-1] = ppcCorrespondanceUnMot;
		}
	}

	//(debug) affiche les mots recupere
	for (unsigned int uiBoucle = 0; uiBoucle < pLISTabCorrespondance.LISLireTaille(); uiBoucle++) {
		cout << pLISTabCorrespondance[uiBoucle][0] << " : " << pLISTabCorrespondance[uiBoucle][1] << endl;
	}
}
