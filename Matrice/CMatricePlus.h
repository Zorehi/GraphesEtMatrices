#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatriceBase.h"

template <typename ELEMENT>
class CMatricePlus : public CMatriceBase<ELEMENT> {
	public :
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
		 * @return CMatricePlus<ELEMENT> Matrice resultat de la multiplication
		 */
		CMatricePlus<ELEMENT> operator*(double dFacteur);

		/**
		 * @brief Surcharge de l'operateur *, pour la multiplication entre deux matrices
		 * 
		 * @param MAPProduit Matrice a multiplier avec la matrice appelante
		 * @return CMatricePlus<ELEMENT> Matrice resultat de la multiplication
		 */
		CMatricePlus<ELEMENT> operator*(CMatricePlus<ELEMENT>& MAPProduit);

		/**
		 * @brief Surcharge de l'operateur /, pour la division de la matrice par un nombre
		 * 
		 * @param dDiviseur Diviseur
		 * @return CMatricePlus<ELEMENT> Matrice resultat de la division
		 */
		CMatricePlus<ELEMENT> operator/(double dDiviseur);

		/**
		 * @brief Surcharge de l'operateur +, pour l'addition de deux matrices
		 * 
		 * @param MAPParam Matrice a additionner avec la matrice appelante
		 * @return CMatricePlus<ELEMENT> Matrice resultat de l'addition
		 */
		CMatricePlus<ELEMENT> operator+(CMatricePlus<ELEMENT>& MAPParam);

		/**
		 * @brief Surcharge de l'operateur -, pour la soustraction de deux matrices
		 * 
		 * @param MAPParam Matrice a soustraire a la matrice appelante
		 * @return CMatricePlus<ELEMENT> Matrice resultat de la soustraction
		 */
		CMatricePlus<ELEMENT> operator-(CMatricePlus<ELEMENT>& MAPParam);

		/**
		 * @brief Effectue la transposee de la matrice
		 * 
		 * @return CMatricePlus<ELEMENT> Matrice resultat de la transposee
		 */
		CMatricePlus<ELEMENT> MAPTranspose();
		CMatricePlus<ELEMENT> MAPParser(char* pcFile);
};

#include "CMatricePlus.cpp"