/**
 * @file CAnalyseurLexical.cpp
 * @author LJ BV JM
 * @brief Contient la definition des methodes de la classe CAnalyseurLexical
 * CAnalyseurLexical permet de segmenter le fichier texte en une ligne de mots
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CAnalyseurLexical.h"

CListe<char*> CAnalyseurLexical::ANLAnalyserFichier(const char* pcNomFichier)
{
	//Ouverture du fichier
	FILE* pFILFichier;
	errno_t err = fopen_s(&pFILFichier, pcNomFichier, "r");

	//Si erreur pendant l'ouvreture du fichier
	if (err != 0) {
		throw CException(180, "Exception : Erreur lors de l'ouverture du fichier");
	}

	CListe<char*> LISCorrespondance(0);

	char* pcChaine = ANLLireProchaineLigne(pFILFichier);
	//Tant que l'on est pas arrive a la fin du fichier on analyse chaque ligne les unes apres les autres
	while (pcChaine[0] != '\0') {
		
		ANLExtraireInfoLigne(pcChaine, LISCorrespondance);
		//cout << pcChaine;

		free(pcChaine);
		pcChaine = ANLLireProchaineLigne(pFILFichier);
	}
	free(pcChaine);

	/*
	//(debug) affiche les mots recuperes
	for (unsigned int uiBoucle = 0; uiBoucle < LISCorrespondance.LISLireTaille(); uiBoucle++) {
		cout << LISCorrespondance[uiBoucle] << endl;
	}
	*/
	
	return LISCorrespondance;
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

void CAnalyseurLexical::ANLExtraireInfoLigne(const char* pcLigne, CListe<char*>& LISCorrespondance)
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
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbElement; uiBoucle++) {
		//Enleve les espaces au debut qui pourrait etre avant le mot
		pcEnCours += strspn(pcEnCours, " ");
			
		//Trouve l'indice du prochain "=, \r\n"
		size_t uiIndex = strcspn(pcEnCours, "=, \r\n");
		char* pcMot = (char*)malloc((uiIndex+1) * sizeof(char));
		//Verification de l'allocation
		if (pcMot == NULL) {
			throw CException(170, "Erreur d'allocation");
		}

		strncpy_s(pcMot, (uiIndex + 1), pcEnCours, uiIndex);
		pcMot[uiIndex] = '\0';
		//cout << "Mot : " << pcMot << endl;

		//Ajout du mot a la liste des mots
		LISCorrespondance.LISModifierTaille(LISCorrespondance.LISLireTaille() + 1);
		LISCorrespondance[LISCorrespondance.LISLireTaille() - 1] = pcMot;

		pcEnCours += uiIndex + 1;
	}
}
