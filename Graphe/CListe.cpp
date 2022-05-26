/**
 * @file CListe.cpp
 * @author LJ BV JM
 * @brief Contient les definitions des methodes de la classe CListe
 * CListe permet de gerer une Liste de n'importe quel MType
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CListe.h"

template <class MType>
CListe<MType>::CListe()
{
	uiLISTaille = 0;
	pMLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
}

template <class MType>
CListe<MType>::CListe(unsigned int uiTaille)
{
	uiLISTaille = uiTaille;
	pMLISTableau = (MType*)malloc(uiTaille * sizeof(MType));
	if (!pMLISTableau) {
		throw CException(110, "Exception : Allocation memoire impossible");
	}
}

template <class MType>
CListe<MType>::CListe(const CListe& LISParam)
{
	uiLISTaille = LISParam.uiLISTaille;
	pMLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
	if (!pMLISTableau) {
		throw CException(110, "Exception : Allocation memoire impossible");
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		pMLISTableau[uiBoucle] = LISParam[uiBoucle];
	}
}

template <class MType>
CListe<MType>::~CListe()
{
	if (pMLISTableau) {
		free(pMLISTableau);
	}
}

template <class MType>
unsigned int CListe<MType>::LISLireTaille()const
{
	return uiLISTaille;
}

template <class MType>
void CListe<MType>::LISModifierTaille(unsigned int uiTaille)
{
	uiLISTaille = uiTaille;
	if (pMLISTableau) {
		if (uiLISTaille == 0) {
			free(pMLISTableau);
			pMLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
		}
		else {
			pMLISTableau = (MType*)realloc(pMLISTableau, uiTaille * sizeof(MType));
		}
	}
	else {
		pMLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));
	}
	
	if (!pMLISTableau) {
		throw CException(120, "Exception : Erreur lors de la modification de la taille");
	}
}

template <class MType>
void CListe<MType>::LISSupprimerElement(unsigned int uiIndice)
{
	if (uiIndice > uiLISTaille) {
		throw CException(130, "Exception : Index non compris dans la liste");
	}
	for (unsigned int iBoucle = uiIndice; iBoucle < uiLISTaille - 1; iBoucle++)
	{
		pMLISTableau[iBoucle] = pMLISTableau[iBoucle + 1];
	}
	LISModifierTaille(uiLISTaille - 1);
}

template <class MType>
MType& CListe<MType>::operator[](unsigned int uiIndex)
{
	if (uiIndex > uiLISTaille) {
		throw CException(130, "Exception : Index non compris dans la liste");
	}
	return pMLISTableau[uiIndex];
}

template <class MType>
const MType& CListe<MType>::operator[](unsigned int uiIndex)const
{
	if (uiIndex > uiLISTaille) {
		throw CException(130, "Exception : Index non compris dans la liste");
	}
	return pMLISTableau[uiIndex];
}

template <class MType>
CListe<MType>& CListe<MType>::operator=(const CListe<MType>& LISParam)
{
	uiLISTaille = LISParam.uiLISTaille;
	free(pMLISTableau);
	pMLISTableau = (MType*)malloc(uiLISTaille * sizeof(MType));

	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++)
	{
		pMLISTableau[uiBoucle] = LISParam[uiBoucle];
	}

	return *this;
}