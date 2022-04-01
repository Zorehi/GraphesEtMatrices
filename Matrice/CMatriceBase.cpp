#include "CMatriceBase.h"

CMatriceBase::CMatriceBase()
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = 0;
	uiMABNbColonnes = 0;
}

CMatriceBase::CMatriceBase(CMatriceBase& MATParam)
{
	MABModifierTypeMatrice(MATParam.MABLireTypeMatrice());
	uiMABNbLignes = MATParam.uiMABNbLignes;
	uiMABNbColonnes = MATParam.uiMABNbColonnes;
}

CMatriceBase::CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes)
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = uiParamNbLignes;
	uiMABNbColonnes = uiParamNbColonnes;
}

CMatriceBase::~CMatriceBase()
{
	if (pcTypeMatrice) {
		free(pcTypeMatrice);
	}
}

void CMatriceBase::MABModifierTypeMatrice(const char* pcParamTypeMatrice)
{
	if (pcTypeMatrice) {
		free(pcTypeMatrice);
	}

	pcTypeMatrice = (char*)malloc(sizeof(char) * strlen(pcParamTypeMatrice)+1);
	if (!pcTypeMatrice) {
		//erreur memoire
	}
	else {
		strcpy_s(pcTypeMatrice, strlen(pcParamTypeMatrice)+1, pcParamTypeMatrice);
	}
}

void CMatriceBase::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	uiMABNbLignes = uiParamNbLignes;
}

void CMatriceBase::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	uiMABNbColonnes = uiParamNbColonnes;
}

char* CMatriceBase::MABLireTypeMatrice()
{
	return pcTypeMatrice;
}

unsigned int CMatriceBase::MABLireNbLignes()
{
	return uiMABNbLignes;
}

unsigned int CMatriceBase::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

