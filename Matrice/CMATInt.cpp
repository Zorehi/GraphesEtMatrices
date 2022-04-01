#include "CMATInt.h"



CMATInt::CMATInt() : CMatrice()
{
	CMINTppiValeurs = NULL;
	
}

CMATInt::CMATInt(int iParamNbLignes, int iParamNbColonnes) : CMatrice(iParamNbLignes, iParamNbColonnes)
{
	CMINTppiValeurs = new int*[iParamNbLignes];

	for (int i = 0; i < iParamNbLignes; i++) {
		CMINTppiValeurs[i] = new int[iParamNbColonnes];
	}
}



CMATInt::CMATInt(CMATInt& MINTParam)
{

}

CMATInt::~CMATInt()
{
	if (CMINTppiValeurs) {
		free(CMINTppiValeurs);

		/*int nbLignes = CMATGetNbLignes();
		for (int i = 0; i < nbLignes; i++) {
			if (CMINTppiValeurs[i]) {
				free(CMINTppiValeurs[i]);
			}
		}*/
	}
}

int CMATInt::CMINTGetElement(int iParamLigne, int iParamColonne)
{
	if (CMINTppiValeurs) {
		if (CMINTppiValeurs[iParamLigne]) {
			return CMINTppiValeurs[iParamLigne][iParamColonne];
		}
	}
	return 0;
}

void CMATInt::CMINTModifierElement(int iParamLigne, int iParamColonne, int iParamValeur)
{
	if (CMINTppiValeurs) {
		if (CMINTppiValeurs[iParamLigne]) {
			CMINTppiValeurs[iParamLigne][iParamColonne] = iParamValeur;
		}
	}
}

void CMATInt::CMINTAfficherMatrice()
{
	int nbLignes = CMATGetNbLignes();
	int nbColonnes = CMATGetNbColonnes();

	for (int ligne = 0; ligne < nbLignes; ligne++) {
		for (int colonne = 0; colonne < nbColonnes; colonne++) {
			printf("%d ", CMINTGetElement(ligne, colonne));
		}
		printf("\n");
	}

}

