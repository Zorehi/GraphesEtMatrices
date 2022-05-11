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

	char* pcChaine = ANLLireProchaineLigne(pFILFichier);
	//Tant que l'on est pas arrive a la fin du fichier on analyse chaque ligne les unes apres les autres
	while (pcChaine[0] != '\0') {
		
		char** ppcTest = ANLExtraireInfoLigne(pcChaine);
		cout << pcChaine;

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

char** CAnalyseurLexical::ANLExtraireInfoLigne(const char* pcLigne)
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

	cout << "nb Element : " << uiNbElement << "\n";


	return nullptr;
}
