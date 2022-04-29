#include "CListe.h"
#include "CException.h"

#define Alloc_Mem_Impossible 110
#define Error_Realloc 120
#define Index_Out_Of_Range 130

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
		CException EXCObjet;
		EXCObjet.EXCModifierval(Alloc_Mem_Impossible);
		EXCObjet.EXCModifiermsg("Exception : Allocation mémoire impossible");
		throw(EXCObjet);
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
		CException EXCObjet;
		EXCObjet.EXCModifierval(Alloc_Mem_Impossible);
		EXCObjet.EXCModifiermsg("Exception : Allocation mémoire impossible");
		throw(EXCObjet);
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
		CException EXCObjet;
		EXCObjet.EXCModifierval(Error_Realloc);
		EXCObjet.EXCModifiermsg("Exception : Erreur lors de la modification de la taille");
		throw(EXCObjet);
	}
}

template <typename ELEMENT>
ELEMENT& CListe<ELEMENT>::operator[](unsigned int uiIndex) {
	if (uiIndex > uiLISTaille) {
		CException EXCObjet;
		EXCObjet.EXCModifierval(Index_Out_Of_Range);
		EXCObjet.EXCModifiermsg("Exception : Index non compris dans la liste");
		throw(EXCObjet);

	}
	return peLISTableau[uiIndex];
}