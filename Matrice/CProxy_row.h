#pragma once

#include <utility>

// class enabling [][] overload to access matrix elements
template <class ELEMENT>
class CProxy_row {
	using PROReference = decltype(std::declval<ELEMENT>()[0]);

private:
	ELEMENT& pePROTableau;
	unsigned int uiPROLigneIndex;
	unsigned int uiPROColonnes;

public:
	CProxy_row(ELEMENT& peTableau, unsigned int uiLigneIndex, unsigned int uiColonnes)
		: pePROTableau(peTableau), uiPROLigneIndex(uiLigneIndex), uiPROColonnes(uiColonnes) {};

	PROReference operator[](unsigned int uiColonneIndex) {
		return pePROTableau[uiPROLigneIndex * uiPROColonnes + uiColonneIndex];
	}
};
