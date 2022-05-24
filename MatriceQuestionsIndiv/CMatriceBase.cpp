/**
 * @file CMatriceBase.cpp
 * @author LJ BV JM
 * @brief Contient les definitions des methodes de la classe CMatriceBase
 * CMatriceBase permet de gerer une Matrice de n'importe quel MType
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CMatriceBase.h"

using std::cout;

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
CMatriceBase<MType>::CMatriceBase(const CMatriceBase<MType>& MABParam)
{
	uiMABNbLignes = MABParam.MABLireNbLignes();
	uiMABNbColonnes = MABParam.MABLireNbColonnes();
	pLISMATListe = new CListe<MType>(*(MABParam.pLISMATListe));
}

template <class MType>
CMatriceBase<MType>::~CMatriceBase()
{
	delete pLISMATListe;
}

template <class MType>
void CMatriceBase<MType>::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	CMatriceBase<MType> MABMatrice(uiParamNbLignes, uiMABNbColonnes);
	for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiParamNbLignes; uiBoucleLigne++)
	{
		if (uiBoucleLigne < uiMABNbLignes) {
			for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMABNbColonnes; uiBoucleColonne++)
			{
				MABMatrice[uiBoucleLigne][uiBoucleColonne] = (*this)[uiBoucleLigne][uiBoucleColonne];
			}
		}
	}
	*this = MABMatrice;
}

template <class MType>
void CMatriceBase<MType>::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	CMatriceBase<MType> MABMatrice(uiMABNbLignes, uiParamNbColonnes);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiParamNbColonnes; uiBoucleColonne++)
	{
		if (uiBoucleColonne < uiMABNbColonnes) {
			for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMABNbLignes; uiBoucleLigne++)
			{
				MABMatrice[uiBoucleLigne][uiBoucleColonne] = (*this)[uiBoucleLigne][uiBoucleColonne];
			}
		}
	}
	*this = MABMatrice;
}

template <class MType>
unsigned int CMatriceBase<MType>::MABLireNbLignes()const
{
	return uiMABNbLignes;
}

template <class MType>
unsigned int CMatriceBase<MType>::MABLireNbColonnes()const
{
	return uiMABNbColonnes;
}

template <class MType>
CMatriceBase<MType>& CMatriceBase<MType>::operator=(const CMatriceBase<MType>& MABParam)
{
	uiMABNbColonnes = MABParam.MABLireNbColonnes();
	uiMABNbLignes = MABParam.MABLireNbLignes();
	delete pLISMATListe;
	pLISMATListe = new CListe<MType>(*MABParam.pLISMATListe);
	return *this;
}

template <class MType>
void CMatriceBase<MType>::MABAfficherMatrice()const {
	if ((uiMABNbLignes == 0) && (uiMABNbColonnes == 0)) {
		throw CException(100, "Exception : la matrice est vide");
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


