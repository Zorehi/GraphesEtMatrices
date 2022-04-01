#include "CMDouble.h"

CMDouble::CMDouble() : CMatriceBase() {
	pdMDOValeurs = NULL;
}

CMDouble::CMDouble(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes) : CMatriceBase(uiParamNbLignes, uiParamNbColonnes)
{
	//Creer et alloue la matrice en memoire
	pdMDOValeurs = (double*)malloc(((size_t)uiParamNbLignes * (size_t)uiParamNbColonnes) * sizeof(int));

	// Mets 0 pour chaque element de la matrice
	unsigned int IndiceMax = uiParamNbLignes * uiParamNbColonnes;
	for (unsigned int indice = 0; indice < IndiceMax; indice++) {
		pdMDOValeurs[indice] = 0;
	}
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

void CMDouble::MDOAfficherMatrice()
{
	unsigned int nbLignes = MABLireNbLignes();
	unsigned int nbColonnes = MABLireNbColonnes();

	for (unsigned int ligne = 0; ligne < nbLignes; ligne++) {
		for (unsigned int colonne = 0; colonne < nbColonnes; colonne++) {
			printf("%lf\t", MDOLireElement(ligne, colonne));
		}
		printf("\n");
	}

}

CMDouble* CMDouble::MDOTranspose()
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMDouble* MatriceTransposee = new CMDouble(NbColonnes, NbLignes);

	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			MatriceTransposee->MDOModifierElement(j, i, MDOLireElement(i, j));
		}
	}

	return MatriceTransposee;
}

CMDouble* CMDouble::MDOMultiplierConstante(double iParamValeur)
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMDouble* NouvelleMatrice = new CMDouble(NbLignes, NbColonnes);


	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			NouvelleMatrice->MDOModifierElement(i, j, MDOLireElement(i, j) * iParamValeur);
		}
	}



	return NouvelleMatrice;
}

CMDouble* CMDouble::MDODiviserConstante(double iParamValeur)
{
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMDouble* NouvelleMatrice = new CMDouble(NbLignes, NbColonnes);


	for (unsigned int i = 0; i < NbLignes; i++) {
		for (unsigned int j = 0; j < NbColonnes; j++) {
			NouvelleMatrice->MDOModifierElement(i, j, (MDOLireElement(i, j) / iParamValeur));
		}
	}



	return NouvelleMatrice;
}

CMDouble* CMDouble::MDOAdditionnerMatrice(CMDouble* MDOParam)
{
	unsigned int Mat1NbLignes = MABLireNbLignes();
	unsigned int Mat1NbColonnes = MABLireNbColonnes();

	unsigned int Mat2NbLignes = MDOParam->MABLireNbLignes();
	unsigned int Mat2NbColonnes = MDOParam->MABLireNbColonnes();


	if (Mat1NbLignes != Mat2NbLignes) {
		//Erreur
		return nullptr;
	}
	if (Mat1NbColonnes != Mat2NbColonnes) {
		//Erreur
		return nullptr;
	}

	CMDouble* NouvelleMatrice = new CMDouble(Mat1NbLignes, Mat1NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat1NbColonnes; j++) {
			NouvelleMatrice->MDOModifierElement(i, j, MDOLireElement(i, j) + MDOParam->MDOLireElement(i, j));
		}
	}

	return NouvelleMatrice;
}

CMDouble* CMDouble::MDOSoustraireMatrice(CMDouble* MINTParam)
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

	CMDouble* NouvelleMatrice = new CMDouble(Mat1NbLignes, Mat1NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat1NbColonnes; j++) {
			NouvelleMatrice->MDOModifierElement(i, j, MDOLireElement(i, j) - MINTParam->MDOLireElement(i, j));
		}
	}

	return NouvelleMatrice;
}

CMDouble* CMDouble::MDOMultiplierMatrice(CMDouble* MDOParam)
{
	unsigned int Mat1NbLignes = MABLireNbLignes();
	unsigned int Mat1NbColonnes = MABLireNbColonnes();

	unsigned int Mat2NbLignes = MDOParam->MABLireNbLignes();
	unsigned int Mat2NbColonnes = MDOParam->MABLireNbColonnes();

	//Si le nombre de colonnes de la premiere matrice est different du nombre de ligne de la deuxieme matrice -> erreur
	if (Mat1NbColonnes != Mat2NbLignes) {
		//Erreur
		throw "Les matrices ne sont pas compatible";
	}

	CMDouble* NouvelleMatrice = new CMDouble(Mat1NbLignes, Mat2NbColonnes);

	for (unsigned int i = 0; i < Mat1NbLignes; i++) {
		for (unsigned int j = 0; j < Mat2NbColonnes; j++) {
			int iValeurElement = 0;
			for (unsigned int n = 0; n < Mat1NbColonnes; n++) {
				iValeurElement += MDOLireElement(i, n) * MDOParam->MDOLireElement(n, j);
			}

			NouvelleMatrice->MDOModifierElement(i, j, iValeurElement);
		}
	}

	return NouvelleMatrice;
}
