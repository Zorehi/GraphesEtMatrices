#include "CMatriceBase.h"
/*
* 
*/


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
	if ((uiMABNbLignes != 0) && (uiMABNbColonnes != 0)) {
		for (unsigned int uiligne = 0; uiligne < uiMABNbLignes; uiligne++) {
			for (unsigned int uicolonne = 0; uicolonne < uiMABNbColonnes; uicolonne++) {
				if (uicolonne == uiMABNbColonnes - 1) {
					cout << (*this)[uiligne][uicolonne] << "\n";
				}
				else {
					//cout << MABLireElement(uiligne, uicolonne) << "\t";
					cout << (*this)[uiligne][uicolonne] << "\t";
				}
			}
		}
	}
	//ICI AJOUTER EXCEPTION OU ERREUR DANS LE ELSE OUI
}
