#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

template <typename ELEMENT>
class CListe
{

private:
	ELEMENT *peLISTableau;
	unsigned int uiLISTaille;

public:
	CListe();
	CListe(unsigned int uiTaille);
	CListe(CListe &LISParam);
	~CListe();

	const unsigned int LISLireTaille();
	ELEMENT* LISLireIndex(unsigned int uiIndex);
	ELEMENT& operator[](unsigned int uiIndex);
};



template <typename ELEMENT>
CListe<ELEMENT>::CListe()
{
	peLISTableau = NULL;
	uiLISTaille = 0;
}

template <typename ELEMENT>
CListe<ELEMENT>::CListe(unsigned int uiTaille)
{
	uiLISTaille = uiTaille;
	peLISTableau = (ELEMENT*)malloc(uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation mémoire impossible";
	}
	for (int i = 0; i < uiLISTaille; i++) {
		peLISTableau[i] = ELEMENT();
	}
}

template <typename ELEMENT>
CListe<ELEMENT>::CListe(CListe& LISParam)
{
	uiLISTaille = LISParam.LISLireTaille();
	peLISTableau = (ELEMENT*)malloc(uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation mémoire impossible";
	}
	for (int i = 0; i < uiLISTaille; i++) {
		peLISTableau[i] = LISParam[i];
	}
}

template <typename ELEMENT>
CListe<ELEMENT>::~CListe()
{
	if (peLISTableau) {
		free(peLISTableau);
	}
}

template <typename ELEMENT>
const unsigned int CListe<ELEMENT>::LISLireTaille() {
	return uiLISTaille;
}

template <typename ELEMENT>
ELEMENT& CListe<ELEMENT>::operator[](unsigned int uiIndex) {
	if (uiIndex > uiLISTaille) {
		throw "Index trop grand";
	}
	return peLISTableau[uiIndex];
}

template <typename ELEMENT>
ELEMENT* CListe<ELEMENT>::LISLireIndex(unsigned int uiIndex) {
	if (uiIndex > uiLISTaille) {
		throw "Index trop grand";
	}
	return &(peLISTableau[uiIndex]);
}

