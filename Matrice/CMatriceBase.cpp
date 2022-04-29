#include "CMatriceBase.h"
#include "CException.h"
/*
* 
*/
#define Matrice_Vide 100

template <class MType>
CMatriceBase<MType>::CMatriceBase()
{
	uiMABNbLignes = 0;
	uiMABNbColonnes = 0;
	pLISMATListe = new CListe<MType>();
}

template <class MType>
CMatriceBase<MType>::CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes)
{
	uiMABNbLignes = uiParamNbLignes;
	uiMABNbColonnes = uiParamNbColonnes;
	unsigned int uiTailleListe = uiParamNbLignes * uiParamNbColonnes;
	pLISMATListe = new CListe<MType>(uiTailleListe);
}

template <class MType>
CMatriceBase<MType>::~CMatriceBase()
{
	delete pLISMATListe;
}

template <class MType>
void CMatriceBase<MType>::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	uiMABNbLignes = uiParamNbLignes;

}

template <class MType>
void CMatriceBase<MType>::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	uiMABNbColonnes = uiParamNbColonnes;
}

template <class MType>
unsigned int CMatriceBase<MType>::MABLireNbLignes()
{
	return uiMABNbLignes;
}

template <class MType>
unsigned int CMatriceBase<MType>::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

template <class MType>
void CMatriceBase<MType>::MABAfficherMatrice() {
	if ((uiMABNbLignes == 0) && (uiMABNbColonnes == 0)) {
		CException EXCObjet;
		EXCObjet.EXCModifierval(Matrice_Vide);
		EXCObjet.EXCModifiermsg("Exception : la matrice est vide");
		throw(EXCObjet);
	}
	for (unsigned int uiligne = 0; uiligne < uiMABNbLignes; uiligne++) {
		for (unsigned int uicolonne = 0; uicolonne < uiMABNbColonnes; uicolonne++) {
			if (uicolonne == uiMABNbColonnes - 1) {
				cout << (*this)[uiligne][uicolonne] << "\n";
			}
			else {
				cout << (*this)[uiligne][uicolonne] << "\t";
			}
		}
	}
}
