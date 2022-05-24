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
CMatriceBase<MType>::CMatriceBase(CMatriceBase<MType>& MABParam)
{
	uiMABNbLignes = MABParam.MABLireNbLignes();
	uiMABNbColonnes = MABParam.MABLireNbColonnes();
	pLISMATListe = new CListe<MType>(*(MABParam.pLISMATListe));
}

template <class MType>
CMatriceBase<MType>::CMatriceBase(CMatriceBase<MType>& MABParam, unsigned int uiLigne)
{
	
	uiMABNbLignes = MABParam.MABLireNbLignes() - 1;
	uiMABNbColonnes = MABParam.MABLireNbColonnes() - 1;
	unsigned int uiTailleListe = uiMABNbLignes * uiMABNbColonnes;
	pLISMATListe = new CListe<MType>(uiTailleListe);

	
	unsigned int nbElementPlace = 0;
	for (unsigned int uiBoucleI = 0; uiBoucleI < MABParam.MABLireNbLignes(); uiBoucleI++) {
		for (unsigned int uiBoucleJ = 1; uiBoucleJ < MABParam.MABLireNbColonnes(); uiBoucleJ++) {
			
			if(uiBoucleI != uiLigne){
				
				(*this)[nbElementPlace/uiMABNbColonnes][nbElementPlace % uiMABNbColonnes] = MABParam[uiBoucleI][uiBoucleJ];
				//pLISMATListe[nbElementPlace] = MABParam[uiBoucleI][uiBoucleJ];
				nbElementPlace++;
				
			}
			
		}
	}
	
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
void CMatriceBase<MType>::MABAfficherMatrice() {
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

template<class MType>
double CMatriceBase<MType>::MAPCalcDet()
{
	//Si la matrice n'est pas carree
	if (MABLireNbColonnes() != MABLireNbLignes()) {
		throw CException(160, "Exception : La matrice n'est pas carree");
	}
	double det = 0;
	if (MABLireNbLignes() == 2) {
		det += ((*this)[0][0]) * ((*this)[1][1]) - ((*this)[1][0]) * ((*this)[0][1]);
		
	}
	else {
		for (int iBoucle = 0; iBoucle < MABLireNbLignes(); iBoucle++) {
			CMatriceBase newMat;
			newMat = CMatriceBase((*this), iBoucle);
			det += pow(-1, iBoucle)*(*this)[iBoucle][0]*newMat.MAPCalcDet();
		}
	}

	return det;
}


