#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatriceBase.h"

template <class MType>
class CMatricePlus : public CMatriceBase<MType> {
public:
	/**
	 * @brief Constructeur de confort : Creer une matrice avec les dimensions donnees
	 *
	 * @param uiParamNbLignes Nombre de lignes souhaitees
	 * @param uiParamNbColonnes Nombre de colonnes souhaitees
	 */
	CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);



	/**
	 * @brief Surcharge de l'operateur *, pour la multiplication entre la matrice et un nombre
	 *
	 * @param dFacteur Facteur de la multiplication
	 * @return CMatricePlus<MType> Matrice resultat de la multiplication
	 */
	CMatricePlus<MType> operator*(double dFacteur);

	/**
	 * @brief Surcharge de l'operateur *, pour la multiplication entre deux matrices
	 *
	 * @param MAPProduit Matrice a multiplier avec la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de la multiplication
	 */
	CMatricePlus<MType> operator*(CMatricePlus<MType>& MAPProduit);

	/**
	 * @brief Surcharge de l'operateur /, pour la division de la matrice par un nombre
	 *
	 * @param dDiviseur Diviseur
	 * @return CMatricePlus<MType> Matrice resultat de la division
	 */
	CMatricePlus<MType> operator/(double dDiviseur);

	/**
	 * @brief Surcharge de l'operateur +, pour l'addition d'une constante a une matrice
	 *
	 * @param dValeurAddition Valeur(double) a ajouter a chaque membre de la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator+(double dValeurAddition);

	/**
	 * @brief Surcharge de l'operateur +, pour l'addition de deux matrices
	 *
	 * @param MAPParam Matrice a additionner avec la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator+(CMatricePlus<MType>& MAPParam);

	/**
	 * @brief Surcharge de l'operateur -, pour la soustraction d'une constante a une matrice
	 *
	 * @param dValeurSoustraction Valeur(double) a soustraire a chaque membre de la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de l'addition
	 */
	CMatricePlus<MType> operator-(double dValeurSoustraction);

	/**
	 * @brief Surcharge de l'operateur -, pour la soustraction de deux matrices
	 *
	 * @param MAPParam Matrice a soustraire a la matrice appelante
	 * @return CMatricePlus<MType> Matrice resultat de la soustraction
	 */
	CMatricePlus<MType> operator-(CMatricePlus<MType>& MAPParam);

	/**
	 * @brief Effectue la transposee de la matrice
	 *
	 * @return CMatricePlus<MType> Matrice resultat de la transposee
	 */
	CMatricePlus<MType> MAPTranspose();
};

#include "CMatricePlus.cpp"