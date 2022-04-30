#pragma once

#include <utility>
#include "CException.h"

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
			throw CException(1, "Exception : Index colonne non compris dans la matrice");
		}
		return pePROTableau[uiPROLigneIndex * uiPROColonnes + uiColonneIndex];
	}
};
