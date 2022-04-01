#include "CMDouble.h"

CMDouble::CMDouble() : CMatriceBase() {
	pdMDOValeurs = NULL;
}

CMDouble::CMDouble(unsigned int iParamNbLignes, unsigned int iParamNbColonnes, double* iParamValeurs) : CMatriceBase(iParamNbLignes, iParamNbColonnes, "double") {
	unsigned int uiNbValeurs = iParamNbLignes * iParamNbColonnes;
	//Faire un test pour savoir si la taille correspond au nombre de valeurs transmises

	pdMDOValeurs = (double*)malloc(sizeof(double) * uiNbValeurs);
	if (pdMDOValeurs == NULL) {
		throw "Pas assez d'espace mémoire";
	}

	int i;
	for (i = 0; i < uiNbValeurs; i++) {
		pdMDOValeurs[i] = iParamValeurs[i];
	}
}

CMDouble::CMDouble(CMDouble& MDOParam) : CMatriceBase(MDOParam) {
	unsigned int uiNbValeurs = MDOParam.MABLireNbColonnes() * MDOParam.MABLireNbLignes();

	pdMDOValeurs = (double*)malloc(sizeof(double) * uiNbValeurs);
	if (pdMDOValeurs == NULL) {
		throw "Pas assez d'espace mémoire";
	}

	int i, j, k;
	k = 0;
	for (i = 0; i < MDOParam.MABLireNbLignes(); i++) {
		for (j = 0; j < MDOParam.MABLireNbColonnes(); j++) {
			pdMDOValeurs[k] = MDOParam.MDOLireElement(i, j);
			k++;
		}
	}
}

CMDouble::~CMDouble() {
	free(pdMDOValeurs);
}

double CMDouble::MDOLireElement(unsigned int iParamLigne, unsigned int iParamColonne) {
	return pdMDOValeurs[iParamLigne * MABLireNbColonnes() + iParamColonne];
}

void CMDouble::MDOModifierElement(unsigned int iParamLigne, unsigned int iParamColonne, double iParamValeur) {
	pdMDOValeurs[iParamLigne * MABLireNbColonnes() + iParamColonne] = iParamValeur;
}

void CMDouble::MDOAfficherMatrice() {

}