#include "CListe.h"


template <class MType>
CListe<MType>::CListe()
{
	peLISTableau = NULL;
	uiLISTaille = 0;
}

template <class MType>
CListe<MType>::CListe(unsigned int uiTaille)
{
	uiLISTaille = uiTaille;
	peLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
	if (!peLISTableau) {
		CException EXCObjet;
		EXCObjet.EXCModifierVal(Alloc_Mem_Impossible);
		EXCObjet.EXCModifierMsg("Exception : Allocation mémoire impossible");
		throw(EXCObjet);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		peLISTableau[uiBoucle] = (MType) MType();
	}
}

template <class MType>
CListe<MType>::CListe(CListe& LISParam)
{
	uiLISTaille = LISParam.LISLireTaille();
	peLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
	if (!peLISTableau) {
		CException EXCObjet;
		EXCObjet.EXCModifierVal(Alloc_Mem_Impossible);
		EXCObjet.EXCModifierMsg("Exception : Allocation mémoire impossible");
		throw(EXCObjet);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		peLISTableau[uiBoucle] = LISParam[uiBoucle];
	}
}

template <class MType>
CListe<MType>::~CListe()
{
	if (peLISTableau) {
		free(peLISTableau);
	}
}

template <class MType>
unsigned int CListe<MType>::LISLireTaille() {
	return uiLISTaille;
}

template <class MType>
void CListe<MType>::LISModifierTaille(unsigned int uiTaille) {
	uiLISTaille = uiTaille;
	peLISTableau = realloc(peLISTableau, uiLISTaille * sizeof(MType));
	if (!peLISTableau) {
		CException EXCObjet;
		EXCObjet.EXCModifierVal(Error_Realloc);
		EXCObjet.EXCModifierMsg("Exception : Erreur lors de la modification de la taille");
		throw(EXCObjet);
	}
}

template <class MType>
MType& CListe<MType>::operator[](unsigned int uiIndex) {
	if (uiIndex > uiLISTaille) {
		CException EXCObjet;
		EXCObjet.EXCModifierVal(Index_Out_Of_Range);
		EXCObjet.EXCModifierMsg("Exception : Index non compris dans la liste");
		throw(EXCObjet);
	}
	return peLISTableau[uiIndex];
}

template <class MType>
CListe<MType>& CListe<MType>::operator=(CListe<MType>& LISParam) {
	uiLISTaille = LISParam.LISLireTaille();
	free(peLISTableau);
	peLISTableau = (MType *) malloc(uiLISTaille * sizeof(MType));

	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++)
	{
		peLISTableau[uiBoucle] = LISParam[uiBoucle];
	}

	return *this;
}