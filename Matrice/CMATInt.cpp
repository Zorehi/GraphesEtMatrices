#include "CMATInt.h"
#include <math.h>



CMATInt::CMATInt() : CMatriceBase()
{
	piMINTValeurs = NULL;
	
}

CMATInt::CMATInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes) : CMatriceBase(uiParamNbLignes, uiParamNbColonnes)
{
	//Si un matrice existe déjà -> liberer la memoire
	if (piMINTValeurs) {
		free(piMINTValeurs);
	}

	//Creer et alloue la matrice en memoire
	piMINTValeurs = (int*)malloc(((size_t)uiParamNbLignes * (size_t)uiParamNbColonnes) * sizeof(int));

	// Mets 0 pour chaque element de la matrice
	unsigned int IndiceMax = uiParamNbLignes * uiParamNbColonnes;
	for (unsigned int indice = 0; indice < IndiceMax; indice++) {
		piMINTValeurs[indice] = 0;
	}
}

CMATInt::CMATInt(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes, int* piParamListe) : CMatriceBase(uiParamNbLignes, uiParamNbColonnes)
{
	//Si un matrice existe déjà -> liberer la memoire
	if (piMINTValeurs) {
		free(piMINTValeurs);
	}

	//Creer et alloue la matrice en memoire
	piMINTValeurs = (int*)malloc(((size_t)uiParamNbLignes * (size_t)uiParamNbColonnes) * sizeof(int));

	// Recopie les valeurs de piParamListe dans piMINTValeurs
	unsigned int IndiceMax = uiParamNbLignes * uiParamNbColonnes;
	for (unsigned int indice = 0; indice < IndiceMax; indice++) {
		if (piParamListe[indice]) {
			piMINTValeurs[indice] = piParamListe[indice];
		}
	}
}

CMATInt::CMATInt(CMATInt& MINTParam)
{
	if (piMINTValeurs) {
		free(piMINTValeurs);
	}

	MABModifierNbLignes(MINTParam.MABLireNbLignes());
	MABModifierNbColonnes(MINTParam.MABLireNbColonnes());
	piMINTValeurs = (int*)malloc(sizeof(int) * ((size_t)MINTParam.MABLireNbLignes() * (size_t)MINTParam.MABLireNbColonnes()));
}

CMATInt::~CMATInt()
{
	if (piMINTValeurs) {
		free(piMINTValeurs);
	}
}

int CMATInt::MINTLireElement(unsigned int uiParamLigne, unsigned int uiParamColonne)
{
	if (piMINTValeurs) {
		return piMINTValeurs[uiParamLigne * MABLireNbColonnes() + uiParamColonne];
	}
	else {
		return -1; //Execption error
	}
}

void CMATInt::MINTModifierElement(unsigned int uiParamLigne, unsigned int uiParamColonne, int iParamValeur)
{
	if (piMINTValeurs) {
		piMINTValeurs[uiParamLigne * MABLireNbColonnes() + uiParamColonne] = iParamValeur;
	}
	else {
		//Execption error
	}
}

void CMATInt::MINTAfficherMatrice()
{
	unsigned int nbLignes = MABLireNbLignes();
	unsigned int nbColonnes = MABLireNbColonnes();

	for (unsigned int ligne = 0; ligne < nbLignes; ligne++) {
		for (unsigned int colonne = 0; colonne < nbColonnes; colonne++) {
			printf("%d\t", MINTLireElement(ligne, colonne));
		}
		printf("\n");
	}

}

CMATInt* CMATInt::MINTTranspose()
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMATInt* MatriceTransposee = new CMATInt(NbColonnes, NbLignes);

	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			MatriceTransposee->MINTModifierElement(j, i, MINTLireElement(i, j));
		}
	}

	return MatriceTransposee;
}

CMATInt* CMATInt::MINTMultiplierConstante(int iParamValeur)
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMATInt* NouvelleMatrice = new CMATInt(NbLignes, NbColonnes);


	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			NouvelleMatrice->MINTModifierElement(i, j, MINTLireElement(i, j)*iParamValeur);
		}
	}



	return NouvelleMatrice;
}

CMATInt* CMATInt::MINTDiviserConstante(int iParamValeur)
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMATInt* NouvelleMatrice = new CMATInt(NbLignes, NbColonnes);


	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			NouvelleMatrice->MINTModifierElement(i, j, floor(MINTLireElement(i, j) / iParamValeur));
		}
	}



	return NouvelleMatrice;
}

CMATInt* CMATInt::MINTAdditionnerMatrice(CMATInt* MINTParam)
{
	unsigned int Mat1NbLignes = MABLireNbLignes();
	unsigned int Mat1NbColonnes = MABLireNbColonnes();

	unsigned int Mat2NbLignes = MINTParam->MABLireNbLignes();
	unsigned int Mat2NbColonnes = MINTParam->MABLireNbColonnes();


	if (Mat1NbLignes != Mat2NbLignes) {
		//Erreur
		return nullptr;
	}
	if (Mat1NbColonnes != Mat2NbColonnes) {
		//Erreur
		return nullptr;
	}

	CMATInt* NouvelleMatrice = new CMATInt(Mat1NbLignes, Mat1NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat1NbColonnes; j++) {
			NouvelleMatrice->MINTModifierElement(i, j, MINTLireElement(i, j) + MINTParam->MINTLireElement(i, j));
		}
	}

	return NouvelleMatrice;
}

CMATInt* CMATInt::MINTSoustraireMatrice(CMATInt* MINTParam)
{
	unsigned int Mat1NbLignes = MABLireNbLignes();
	unsigned int Mat1NbColonnes = MABLireNbColonnes();

	unsigned int Mat2NbLignes = MINTParam->MABLireNbLignes();
	unsigned int Mat2NbColonnes = MINTParam->MABLireNbColonnes();


	if (Mat1NbLignes != Mat2NbLignes) {
		//Erreur
		return nullptr;
	}
	if (Mat1NbColonnes != Mat2NbColonnes) {
		//Erreur
		return nullptr;
	}

	CMATInt* NouvelleMatrice = new CMATInt(Mat1NbLignes, Mat1NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat1NbColonnes; j++) {
			NouvelleMatrice->MINTModifierElement(i, j, MINTLireElement(i, j) - MINTParam->MINTLireElement(i, j));
		}
	}

	return NouvelleMatrice;
}

CMATInt* CMATInt::MINTMultiplierMatrice(CMATInt* MINTParam)
{
	unsigned int Mat1NbLignes = MABLireNbLignes();
	unsigned int Mat1NbColonnes = MABLireNbColonnes();

	unsigned int Mat2NbLignes = MINTParam->MABLireNbLignes();
	unsigned int Mat2NbColonnes = MINTParam->MABLireNbColonnes();

	//Si le nombre de colonnes de la premiere matrice est different du nombre de ligne de la deuxieme matrice -> erreur
	if (Mat1NbColonnes != Mat2NbLignes) {
		//Erreur
		return nullptr;
	}

	CMATInt* NouvelleMatrice = new CMATInt(Mat1NbLignes, Mat2NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat2NbColonnes; j++) {
			int iValeurElement = 0;
			for (unsigned int n = 0; n < Mat1NbColonnes; n++) {
				iValeurElement += MINTLireElement(i, n) * MINTParam->MINTLireElement(n, j);
			}

			NouvelleMatrice->MINTModifierElement(i, j, iValeurElement);
		}
	}

	return NouvelleMatrice;
}

