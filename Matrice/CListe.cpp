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
	uiLISTaille = uiTaille;
	peLISTableau = (ELEMENT*)malloc(uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation m�moire impossible";
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		peLISTableau[uiBoucle] = ELEMENT();
	}
}

template <typename ELEMENT>
CListe<ELEMENT>::CListe(CListe& LISParam)
{
	uiLISTaille = LISParam.LISLireTaille();
	peLISTableau = (ELEMENT*)malloc(uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Allocation m�moire impossible";
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		peLISTableau[uiBoucle] = LISParam[uiBoucle];
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
unsigned int CListe<ELEMENT>::LISLireTaille() {
	return uiLISTaille;
}

template <typename ELEMENT>
void CListe<ELEMENT>::LISModifierTaille(unsigned int uiTaille) {
	uiLISTaille = uiTaille;
	peLISTableau = realloc(peLISTableau, uiLISTaille * sizeof(ELEMENT));
	if (!peLISTableau) {
		throw "Impossible d'agrandire";
	}
}

template <typename ELEMENT>
ELEMENT& CListe<ELEMENT>::operator[](unsigned int uiIndex) {
	if (uiIndex > uiLISTaille) {
		throw "Index trop grand";
	}
	return peLISTableau[uiIndex];
}