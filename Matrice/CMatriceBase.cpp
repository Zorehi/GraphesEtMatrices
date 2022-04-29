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
}

template <class MType>
void CMatriceBase<MType>::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	CListe<MType>* LISNewListe = new CListe<MType>(uiParamNbLignes * uiMABNbColonnes);
	if (uiParamNbLignes > uiMABNbLignes) {
		for (unsigned int uiBoucleLigne = uiMABNbLignes; uiBoucleLigne < uiParamNbLignes; uiBoucleLigne++)
		{
			for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMABNbColonnes; uiBoucleColonne++)
			{
				(*LISNewListe)[uiBoucleLigne * uiMABNbColonnes + uiBoucleColonne] = MType();
			}
		}
	}
	else {
		uiMABNbLignes = uiParamNbLignes;
	}

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMABNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMABNbColonnes; uiBoucleColonne++)
		{
			(*LISNewListe)[uiBoucleLigne * uiMABNbColonnes + uiBoucleColonne] = (*pLISMATListe)[uiBoucleLigne * uiMABNbColonnes + uiBoucleColonne];
		}
	}
	uiMABNbLignes = uiParamNbLignes;
	delete pLISMATListe;
	pLISMATListe = LISNewListe;
}

template <class MType>
void CMatriceBase<MType>::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	/*
	CListe<MType>* LISNewListe = new CListe<MType>(uiMABNbLignes * uiParamNbColonnes);
	if (uiParamNbColonnes > uiMABNbColonnes) {
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMABNbLignes; uiBoucleLigne++)
		{
			for (unsigned int uiBoucleColonne = uiMABNbColonnes; uiBoucleColonne < uiParamNbColonnes; uiBoucleColonne++)
			{
				(*LISNewListe)[uiBoucleLigne * uiParamNbColonnes + uiBoucleColonne] = MType();
			}
		}
	}
	else {
		uiMABNbColonnes = uiParamNbColonnes;
	}

	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMABNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMABNbColonnes; uiBoucleColonne++)
		{
			(*LISNewListe)[uiBoucleLigne * uiParamNbColonnes + uiBoucleColonne] = (*pLISMATListe)[uiBoucleLigne * uiMABNbColonnes + uiBoucleColonne];
		}
	}
	uiMABNbColonnes = uiParamNbColonnes;
	delete pLISMATListe;
	pLISMATListe = LISNewListe;
	*/
	CMatriceBase<MType> MABMatrice(uiMABNbLignes, uiParamNbColonnes);
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMABNbLignes; uiBoucleLigne++)
	{
		for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMABNbColonnes; uiBoucleColonne++)
		{
			MABMatrice[uiBoucleLigne][uiBoucleColonne] = (*this)[uiBoucleLigne][uiBoucleColonne];
		}
	}
	*this = MABMatrice;
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
CMatriceBase<MType>& CMatriceBase<MType>::operator=(CMatriceBase& MABParam)
{
	uiMABNbColonnes = MABParam.MABLireNbColonnes();
	uiMABNbLignes = MABParam.MABLireNbLignes();
	delete pLISMATListe;
	pLISMATListe = new CListe<MType>(*MABParam.pLISMATListe);
	return *this;
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
