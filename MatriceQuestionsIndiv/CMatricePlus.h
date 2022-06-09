/**
 * @file CMatricePlus.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CMatricePlus
 * CMatricePlus herite de CMatriceBase et lui rajoute les operations +, -, *, / et la transposee
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "CMatriceBase.h"

#define Type_non_Valide 140
#define Matrices_Incompatibles 150
#define Matrice_non_carre 160

template <class MType>
class CMatricePlus : public CMatriceBase<MType> {
public:
	/**
	 * @brief Constructeur par defaut : Creer un objet MatricePlus de type <MType>
	 *
	 */
	CMatricePlus();

	/**
	 * @brief Constructeur de confort : Creer une matrice avec les dimensions donnees
	 *
	 * @param uiParamNbLignes Nombre de lignes souhaitees
	 * @param uiParamNbColonnes Nombre de colonnes souhaitees
	 */
	CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);

	/**
	 * @brief Constructeur permettant de creer la sous matrice permettant de reasliser le calcul du determinant de la matrice
	 * @param MABParam matrice mere de la sous matrice a creer
	 * @param uiLigne numero de la ligne a ne pas inclure dans la sous matrice
	*/
	CMatricePlus(const CMatriceBase<MType>& MABParam, unsigned int uiLigne);

	/**
	 * @brief Surcharge de l'operateur *, pour la multiplication entre la matrice et un nombre
	 *
	 * @param dFacteur Facteur de la multiplication
	 * @return CMatricePlus<MType> Matrice resultat de la multiplication
	 */
	CMatricePlus<MType> operator*(double dFacteur)const;

	/**
	 * @brief Surcharge de l'operateur *, pour la multiplication entre deux matrices
	 *
	 * @param MAPProduit Matrice a multiplier avec la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de la multiplication
	 */
	CMatricePlus<MType> operator*(const CMatricePlus<MType>& MAPProduit)const;

	/**
	 * @brief Surcharge de l'operateur /, pour la division de la matrice par un nombre
	 *
	 * @param dDiviseur Diviseur
	 * @return CMatricePlus<MType> Matrice resultat de la division
	 */
	CMatricePlus<MType> operator/(double dDiviseur)const;

	/**
	 * @brief Surcharge de l'operateur +, pour l'addition d'une constante a une matrice
	 *
	 * @param dValeurAddition Valeur(double) a ajouter a chaque membre de la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator+(double dValeurAddition)const;

	/**
	 * @brief Surcharge de l'operateur +, pour l'addition de deux matrices
	 *
	 * @param MAPParam Matrice a additionner avec la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator+(const CMatricePlus<MType>& MAPParam)const;

	/**
	 * @brief Surcharge de l'operateur -, pour la soustraction d'une constante a une matrice
	 *
	 * @param dValeurSoustraction Valeur(double) a soustraire a chaque membre de la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator-(double dValeurSoustraction)const;

	/**
	 * @brief Surcharge de l'operateur -, pour la soustraction de deux matrices
	 *
	 * @param MAPParam Matrice a soustraire a la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de la soustraction
	 */
	CMatricePlus<MType> operator-(const CMatricePlus<MType>& MAPParam)const;

	/**
	 * @brief Effectue la transposee de la matrice
	 *
	 * @return CMatricePlus<MType> Matrice resultat de la transposee
	 */
	CMatricePlus<MType> MAPTranspose()const;

	/**
	 * @brief Calcul le determinant de la matrice
	 *
	 * @return double Determinant de la matrice
	 */
	double MAPCalcDet()const;
};

#include "CMatricePlus.cpp"