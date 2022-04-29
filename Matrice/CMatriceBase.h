#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "CListe.h"
#include "CProxy_row.h"

using namespace std;

template <class MType>
class CMatriceBase {
	using MATPROProxy = CProxy_row<CListe<MType>>;

	private :
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
		 * @brief Destructeur : libere la memoire alloue pour l'objet MatriceBase
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
		unsigned int MABLireNbLignes();

		/**
		 * @brief Getter pour le nombre de colonnes de MatriceBase
		 * 
		 * @return unsigned int, le nombre de colonnes de MatriceBase
		 */
		unsigned int MABLireNbColonnes();

		/**
		 * @brief Surcharge de l'operateur d'indice du tableau, cette surcharge permet
		 * l'appel de deux operateurs d'indice ex : Matrice[1][1] ce qui permet de choisir 
		 * respectivement la ligne et la colonne
		 * 
		 * @param uiLignes Numéro de la ligne choisi
		 * @return l'objet MATPROProxy 
		 */
		MATPROProxy operator[](unsigned int uiLignes) {
			return MATPROProxy(*pLISMATListe, uiLignes, uiMABNbColonnes);
		}

		
		CMatriceBase<MType>& operator=(CMatriceBase& MABParam);

		/**
		 * @brief Affiche la matrice dans le shell
		 * 
		 */
		void MABAfficherMatrice();
};


#include "CMatriceBase.cpp"