/**
 * @file CMatricePlus.cpp
 * @author LJ BV JM
 * @brief Contient les definitions des methodes de la classe CMatricePlus
 * CMatricePlus herite de CMatriceBase et lui rajoute les operations +, -, *, / et la transposee
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CMatricePlus.h"

template <class MType>
CMatricePlus<MType>::CMatricePlus() : CMatriceBase<MType>()
{
}

template <class MType>
CMatricePlus<MType>::CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes) : CMatriceBase<MType>(uiParamNbLignes, uiParamNbColonnes)
{
}

template <class MType>
CMatricePlus<MType>::CMatricePlus(const CMatriceBase<MType>& MABParam, unsigned int uiLigne)
{

	(*this).uiMABNbLignes = MABParam.MABLireNbLignes() - 1;
	(*this).uiMABNbColonnes = MABParam.MABLireNbColonnes() - 1;
	unsigned int uiTailleListe = (*this).uiMABNbLignes * (*this).uiMABNbColonnes;
	(*this).pLISMATListe = new CListe<MType>(uiTailleListe);

	unsigned int nbElementPlace = 0;
	for (unsigned int uiBoucleI = 0; uiBoucleI < MABParam.MABLireNbLignes(); uiBoucleI++) {
		for (unsigned int uiBoucleJ = 1; uiBoucleJ < MABParam.MABLireNbColonnes(); uiBoucleJ++) {

			if (uiBoucleI != uiLigne) {

				(*this)[nbElementPlace / (*this).uiMABNbColonnes][nbElementPlace % (*this).uiMABNbColonnes] = MABParam[uiBoucleI][uiBoucleJ];
				//pLISMATListe[nbElementPlace] = MABParam[uiBoucleI][uiBoucleJ];
				nbElementPlace++;

			}

		}
	}
}


template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator*(double dFacteur)const
{
	
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation du nombres de lignes et de colonnes dans la matrice
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une matrice<double> etant le resultat de la multiplication de chaque membre par dFacteur
	CMatricePlus<double> MAPMatriceRetour(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiNbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (double)(*this)[uiBoucleI][uiBoucleJ] * dFacteur;
		}
	}
	return MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> operator*(double dFacteur, const CMatricePlus<MType>& MAPProduit)
{
	return MAPProduit * dFacteur;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator*(const CMatricePlus<MType>& MAPProduit)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPProduit.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPProduit.MABLireNbColonnes();

	//Si le nombre de colonnes de la premiere matrice est different du nombre de ligne de la deuxieme matrice -> erreur
	if (uiMAP1NbColonnes != uiMAP2NbLignes) {
		throw CException(150, "Exception : Les matrices ne sont pas compatibles entre elles");
	}

	//Creation d'une matrice<double> etant le resultat de la multiplication de la matrice par la matrice MAPProduit
	CMatricePlus<double> MAPMatriceRetour(uiMAP1NbLignes, uiMAP2NbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMAP1NbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMAP2NbColonnes; uiBoucleJ++) {
			double iValeurElement = 0;
			for (unsigned int uiBoucleN = 0; uiBoucleN < uiMAP1NbColonnes; uiBoucleN++) {
				iValeurElement += (*this)[uiBoucleI][uiBoucleN] * MAPProduit[uiBoucleN][uiBoucleJ];
			}

			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = iValeurElement;
		}
	}

	return MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator/(double dDiviseur)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation du nombres de lignes et de colonnes dans la matrice
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une matrice<double> etant le resultat de la division de chaque membre par dDiviseur
	CMatricePlus<double> MAPMatriceRetour(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiNbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiNbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (double)(*this)[uiBoucleI][uiBoucleJ] / dDiviseur;
		}
	}

	return MAPMatriceRetour;
}

template<class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator+(double dValeurAddition)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de l'addition de dValeurAddition a chaque membre de la matrice
	CMatricePlus<double> MAPMatriceRetour(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMAP1NbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMAP1NbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (double)(*this)[uiBoucleI][uiBoucleJ] + dValeurAddition;
		}
	}

	return MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator+(const CMatricePlus<MType>& MAPParam)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPParam.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPParam.MABLireNbColonnes();


	//Compare si bien le meme nombre de lignes et de colonnes
	if (uiMAP1NbLignes != uiMAP2NbLignes) {
		throw CException(150, "Exception : Les matrices ne sont pas compatibles entre elles (nombre de ligne different)");
	}
	if (uiMAP1NbColonnes != uiMAP2NbColonnes) {
		throw CException(150, "Exception : Les matrices ne sont pas compatibles entre elles (nombre de colonnes different)");
	}

	//Creation d'une nouvelle matrice<double> etant le resultat de l'addition membre a membre des deux matrices
	CMatricePlus<double> MAPMatriceRetour(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMAP1NbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMAP1NbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (double)(*this)[uiBoucleI][uiBoucleJ] + MAPParam[uiBoucleI][uiBoucleJ];
		}
	}

	return MAPMatriceRetour;
}

template<class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator-(double dValeurSoustraction)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de la soustraction de dValeurSoustraction a chaque membre de la matrice
	CMatricePlus<double> MAPMatriceRetour(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMAP1NbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMAP1NbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (double)(*this)[uiBoucleI][uiBoucleJ] + dValeurSoustraction;
		}
	}
	return MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator-(const CMatricePlus<MType>& MAPParam)const
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPParam.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPParam.MABLireNbColonnes();


	if (uiMAP1NbLignes != uiMAP2NbLignes) {
		throw CException(150, "Exception : Les matrices ne sont pas compatibles entre elles (nombre de ligne different)");
	}
	if (uiMAP1NbColonnes != uiMAP2NbColonnes) {
		throw CException(150, "Exception : Les matrices ne sont pas compatibles entre elles (nombre de colonnes different)");
	}

	//Creation d'une nouvelle matrice<double> etant le resultat de la soustraction membre a membre des deux matrices
	CMatricePlus<double> MAPMatriceRetour(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucleI = 0; uiBoucleI < uiMAP1NbLignes; uiBoucleI++) {
		for (unsigned int uiBoucleJ = 0; uiBoucleJ < uiMAP1NbColonnes; uiBoucleJ++) {
			MAPMatriceRetour[uiBoucleI][uiBoucleJ] = (*this)[uiBoucleI][uiBoucleJ] - MAPParam[uiBoucleI][uiBoucleJ];
		}
	}

	return MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::MAPTranspose()const
{
	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de la transposee de la matrice appelante
	CMatricePlus<double> MAPMatriceRetour(uiNbColonnes, uiNbLignes);
	for (unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++) {
		for (unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++) {
			MAPMatriceRetour[uiBoucleC][uiBoucleL] = (*this)[uiBoucleL][uiBoucleC];
		}
	}

	return MAPMatriceRetour;
}

template<class MType>
double CMatricePlus<MType>::MAPCalcDet()const
{
	//Si la matrice n'est pas carree
	if ((*this).MABLireNbColonnes() != (*this).MABLireNbLignes()) {
		throw CException(160, "Exception : La matrice n'est pas carree");
	}

	//Si on ne peut pas calculer le determinant sur ce type de matrice
	if (typeid(MType) != typeid(double) && typeid(MType) != typeid(int) && typeid(MType) != typeid(float)) {
		throw CException(140, "Exception : Impossible de faire cette operation sur ce type de matrice");
	}

	double det = 0;
	if ((*this).MABLireNbLignes() == 2) {
		det += ((*this)[0][0]) * ((*this)[1][1]) - ((*this)[1][0]) * ((*this)[0][1]);

	}
	else {
		for (unsigned int uiBoucle = 0; uiBoucle < (*this).MABLireNbLignes(); uiBoucle++) {
			CMatricePlus newMat;
			newMat = CMatricePlus((*this), uiBoucle);
			det += pow(-1, uiBoucle)*(*this)[uiBoucle][0]*newMat.MAPCalcDet();
		}
	}

	return det;
}

