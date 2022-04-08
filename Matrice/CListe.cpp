#include "CListe.h"

template <typename ELEMENT>
CListe<ELEMENT>::CListe()
{
	peLISTableau = NULL;
	uiLISTaille = 0;
}

template <typename ELEMENT>
CListe<ELEMENT>::CListe(unsigned int uiTaille)
{
	peLISTableau = (ELEMENT*)malloc(uiTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation mémoire impossible";
	}
	uiLISTaille = uiTaille;
}

template <typename ELEMENT>
CListe<ELEMENT>::CListe(CListe &LISParam)
{
	uiLISTaille = LISParam.LISLireTaille();
	peLISTableau = (ELEMENT*)malloc(uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation mémoire impossible";
	}
	strcpy_s(peLISTableau, uiLISTaille * sizeof(ELEMENT), LISParam.peLISTableau);
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