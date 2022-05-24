/**
 * @file CMatriceBase.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CMatriceBase
 * CMatriceBase permet de gerer une Matrice de n'importe quel MType
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
#include <string.h>
#include <iostream>
#include <math.h>

#include "CListe.h"
#include "CProxy_row.h"
#include "CException.h"

#define Matrice_Vide 100
#define Index_non_compris 105

using namespace std;

template <class MType>
class CMatriceBase {
	using MATPROProxy = CProxy_row<CListe<MType>>;

	protected :
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;
		CListe<MType> * pLISMATListe;


	public :
		/**
		 * @brief Constructeur par defaut : Creer un objet MatriceBase de type <MType>
		 * 
		 */
		CMatriceBase();

		/**
		 * @brief Constructeur de confort : Creer une matrice avec les dimensions donnees
		 * 
		 * @param uiParamNbLignes Nombre de lignes souhaitees
		 * @param uiParamNbColonnes Nombre de colonnes souhaitees
		 */
		CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);

		/**
		 * @brief Constructeur de recopie : Creer un duplicata d'une Matrice deja cree
		 *
		 * @param MABParam Matrice a dupliquer
		 */
		CMatriceBase(CMatriceBase<MType>& MABParam);

		/**
		 * @brief Destructeur : Libere la memoire alloue pour l'objet MatriceBase
		 * 
		 */
		~CMatriceBase();

		

		/**
		 * @brief Setter pour le nombre de lignes de MatriceBase
		 * 
		 * @param uiParamNbLignes Nouveau nombre de lignes souhaitees pour MatriceBase
		 */
		void MABModifierNbLignes(unsigned int uiParamNbLignes);

		/**
		 * @brief Setter pour le nombre de colonnes de MatriceBase
		 * 
		 * @param uiParamNbColonnes Nouveau nombre de colonnes souhaitees pour MatriceBase
		 */
		void MABModifierNbColonnes(unsigned int uiParamNbColonnes);

		/**
		 * @brief Getter pour le nombre de lignes de MatriceBase
		 * 
		 * @return unsigned int, le nombre de lignes de MatriceBase
		 */
		unsigned int MABLireNbLignes()const;

		/**
		 * @brief Getter pour le nombre de colonnes de MatriceBase
		 * 
		 * @return unsigned int, le nombre de colonnes de MatriceBase
		 */
		unsigned int MABLireNbColonnes()const;

		/**
		 * @brief Surcharge de l'operateur d'indice du tableau, cette surcharge permet
		 * l'appel de deux operateurs d'indice ex : Matrice[1][1] ce qui permet de choisir 
		 * respectivement la ligne et la colonne
		 * 
		 * @param uiLignes Numéro de la ligne choisi
		 * @return l'objet MATPROProxy 
		 */
		MATPROProxy operator[](unsigned int uiLignes) {
			if (uiLignes > uiMABNbLignes) {
				throw CException(105, "Exception : Index ligne non compris dans la matrice");
			}
			return MATPROProxy(*pLISMATListe, uiLignes, uiMABNbColonnes);
		}

		/**
		 * @brief Surcharge de l'operateur d'affectation, recopie la matrice MABParam dans la matrice appelante
		 * 
		 * @param MABParam Matrice a recopier
		 * @return CMatriceBase<MType>& Reference de la matrice recopiee
		 */
		CMatriceBase<MType>& operator=(const CMatriceBase<MType>& MABParam);

		/**
		 * @brief Affiche la matrice dans le shell
		 * 
		 */
		void MABAfficherMatrice();

		//double MAPCalcDet();
};


#include "CMatriceBase.cpp"