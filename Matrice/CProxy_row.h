/**
 * @file CProxy_row.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CProxy_row
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

#include <utility>
#include "CException.h"

#define Index_non_compris 105

// class enabling [][] overload to access matrix elements
template <class MType>
class CProxy_row {
	using PROReference = decltype(std::declval<MType>()[0]);

private:
	MType& pePROTableau;
	unsigned int uiPROLigneIndex;
	unsigned int uiPROColonnes;

public:
	
	CProxy_row(MType& peTableau, unsigned int uiLigneIndex, unsigned int uiColonnes)
		: pePROTableau(peTableau), uiPROLigneIndex(uiLigneIndex), uiPROColonnes(uiColonnes) {};

	PROReference operator[](unsigned int uiColonneIndex) {
		if (uiColonneIndex > uiPROColonnes) {
			throw CException(Index_non_compris, "Exception : Index colonne non compris dans la matrice");
		}
		return pePROTableau[uiPROLigneIndex * uiPROColonnes + uiColonneIndex];
	}
};
