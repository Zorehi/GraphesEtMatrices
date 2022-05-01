#include "CMatricePlus.h"

template <class MType>
CMatricePlus<MType>::CMatricePlus() : CMatriceBase<MType>()
{
}

template <class MType>
CMatricePlus<MType>::CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes) : CMatriceBase<MType>(uiParamNbLignes, uiParamNbColonnes)
{
}
/*
template <class MType>
CMatricePlus<MType>::CMatricePlus(CMatricePlus<MType>& MAPParam) : CMatriceBase<MType>(MAPParam)
{
}
*/
template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator*(double dFacteur)
{
	
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation du nombres de lignes et de colonnes dans la matrice
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une matrice<double> etant le resultat de la multiplication de chaque membre par dFacteur
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiNbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (double)(*this)[uiBoucle][ujBoucle] * dFacteur;
		}
	}
	return *MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> operator*(double dFacteur, CMatricePlus<MType>& MAPProduit)
{
	return MAPProduit * dFacteur;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator*(CMatricePlus<MType>& MAPProduit)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPProduit.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPProduit.MABLireNbColonnes();

	//Si le nombre de colonnes de la premiere matrice est different du nombre de ligne de la deuxieme matrice -> erreur
	if (uiMAP1NbColonnes != uiMAP2NbLignes) {
		//Erreur
		throw "Les matrices ne sont pas compatible";
	}

	//Creation d'une matrice<double> etant le resultat de la multiplication de la matrice par la matrice MAPProduit
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiMAP1NbLignes, uiMAP2NbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMAP1NbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiMAP2NbColonnes; ujBoucle++) {
			double iValeurElement = 0;
			for (unsigned int unBoucle = 0; unBoucle < uiMAP1NbColonnes; unBoucle++) {
				iValeurElement += (*this)[uiBoucle][unBoucle] * MAPProduit[unBoucle][ujBoucle];
			}

			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = iValeurElement;
		}
	}

	return *MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator/(double dDiviseur)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation du nombres de lignes et de colonnes dans la matrice
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une matrice<double> etant le resultat de la division de chaque membre par dDiviseur
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiNbLignes, uiNbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiNbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (double)(*this)[uiBoucle][ujBoucle] / dDiviseur;
		}
	}

	return *MAPMatriceRetour;
}

template<class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator+(double dValeurAddition)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de l'addition de dValeurAddition a chaque membre de la matrice
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMAP1NbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiMAP1NbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (double)(*this)[uiBoucle][ujBoucle] + dValeurAddition;
		}
	}

	return *MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator+(CMatricePlus<MType>& MAPParam)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPParam.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPParam.MABLireNbColonnes();


	//Compare si bien le meme nombre de lignes et de colonnes
	if (uiMAP1NbLignes != uiMAP2NbLignes) {
		//Erreur
		throw "Pas le même nombre de lignes";
	}
	if (uiMAP1NbColonnes != uiMAP2NbColonnes) {
		//Erreur
		throw "Pas le même nombre de colonnes";
	}

	//Creation d'une nouvelle matrice<double> etant le resultat de l'addition membre a membre des deux matrices
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMAP1NbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiMAP1NbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (double)(*this)[uiBoucle][ujBoucle] + MAPParam[uiBoucle][ujBoucle];
		}
	}

	return *MAPMatriceRetour;
}

template<class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator-(double dValeurSoustraction)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de la soustraction de dValeurSoustraction a chaque membre de la matrice
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMAP1NbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiMAP1NbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (double)(*this)[uiBoucle][ujBoucle] + dValeurSoustraction;
		}
	}

	return *MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::operator-(CMatricePlus<MType>& MAPParam)
{
	//Si on ne peut pas faire de multiplication sur ce type de matrice
	if (typeid(MType).name() != typeid(double).name() && typeid(MType).name() != typeid(int).name() && typeid(MType).name() != typeid(float).name()) {
		throw "pas le droit de faire cette operation sur ce type de matrice";
		//erreur
	}

	//Recuperation des nombres de lignes et de colonnes des deux matrices
	unsigned int uiMAP1NbLignes = this->MABLireNbLignes();
	unsigned int uiMAP1NbColonnes = this->MABLireNbColonnes();

	unsigned int uiMAP2NbLignes = MAPParam.MABLireNbLignes();
	unsigned int uiMAP2NbColonnes = MAPParam.MABLireNbColonnes();


	if (uiMAP1NbLignes != uiMAP2NbLignes) {
		//Erreur
		throw "Pas le même nombre de lignes";
	}
	if (uiMAP1NbColonnes != uiMAP2NbColonnes) {
		//Erreur
		throw "Pas le même nombre de colonnes";
	}

	//Creation d'une nouvelle matrice<double> etant le resultat de la soustraction membre a membre des deux matrices
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiMAP1NbLignes, uiMAP1NbColonnes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiMAP1NbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiMAP1NbColonnes; ujBoucle++) {
			(*MAPMatriceRetour)[uiBoucle][ujBoucle] = (*this)[uiBoucle][ujBoucle] - MAPParam[uiBoucle][ujBoucle];
		}
	}

	return *MAPMatriceRetour;
}

template <class MType>
CMatricePlus<MType>& CMatricePlus<MType>::operator=(CMatricePlus<MType>& MAPParam)
{
	unsigned int uiNbLignes = MAPParam.MABLireNbLignes();
	unsigned int uiNbColonnes = MAPParam.MABLireNbColonnes();
	this->MABModifierNbColonnes(uiNbColonnes);
	this->MABModifierNbLignes(uiNbLignes);
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++) {
		for (unsigned int ujBoucle = 0; ujBoucle < uiNbColonnes; ujBoucle++) {
			(*this)[uiBoucle][ujBoucle] = MAPParam[uiBoucle][ujBoucle];
		}
	}

}

template <class MType>
CMatricePlus<MType> CMatricePlus<MType>::MAPTranspose()
{
	//Recuperation des nombres de lignes et de colonnes de la matrice appelante
	unsigned int uiNbLignes = this->MABLireNbLignes();
	unsigned int uiNbColonnes = this->MABLireNbColonnes();

	//Creation d'une nouvelle matrice<double> etant le resultat de la transposee de la matrice appelante
	CMatricePlus<double>* MAPMatriceRetour = new CMatricePlus<double>(uiNbColonnes, uiNbLignes);
	for (unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++) {
		for (unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++) {
			(*MAPMatriceRetour)[uiBoucleC][uiBoucleL] = (*this)[uiBoucleL][uiBoucleC];
		}
	}

	return *MAPMatriceRetour;
}