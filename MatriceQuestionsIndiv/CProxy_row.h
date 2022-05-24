/**
 * @file CProxy_row.h
 * @author LJ BV JM
 * @brief Contient la declaration et la definition de la classe CProxy_row
 * CProxy_row permet d'activer la surcharge de [][] pour acceder 
 * aux elements d'une matrice
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "CException.h"

#define Index_non_compris 105

template <class MType>
class CProxy_row {
	using PROReference = decltype(std::declval<MType>()[0]);
	using const_PROReference = decltype(std::declval<MType const>()[0]);

private:
	MType& pePROTableau;
	unsigned int uiPROLigneIndex;
	unsigned int uiPROColonnes;

public:
	/**
	 * @brief Constructeur de confort : Creer un objet Proxy_row avec les elements donnees
	 * 
	 * @param peTableau La reference du tableau qui contient les valeurs de la matrice
	 * @param uiLigneIndex L'index de la ligne
	 * @param uiColonnes Le nombre de colonnes de la matrice
	 */
	CProxy_row(MType& peTableau, unsigned int uiLigneIndex, unsigned int uiColonnes)
		: pePROTableau(peTableau), uiPROLigneIndex(uiLigneIndex), uiPROColonnes(uiColonnes) {};

	/**
	 * @brief Surcharge de l'operateur d'indice du tableau
	 * 
	 * @param uiColonneIndex L'index de la colonne
	 * @return PROReference L'element de la matrice correspondant a la ligne et la colonne
	 */
	const_PROReference operator[](unsigned int uiColonneIndex)const {
		if (uiColonneIndex > uiPROColonnes) {
			throw CException(Index_non_compris, "Exception : Index colonne non compris dans la matrice");
		}
		return pePROTableau[uiPROLigneIndex * uiPROColonnes + uiColonneIndex];
	}

	/**
	 * @brief Surcharge de l'operateur d'indice du tableau
	 *
	 * @param uiColonneIndex L'index de la colonne
	 * @return PROReference L'element de la matrice correspondant a la ligne et la colonne
	 */
	PROReference operator[](unsigned int uiColonneIndex) {
		if (uiColonneIndex > uiPROColonnes) {
			throw CException(Index_non_compris, "Exception : Index colonne non compris dans la matrice");
		}
		return pePROTableau[uiPROLigneIndex * uiPROColonnes + uiColonneIndex];
	}
};
