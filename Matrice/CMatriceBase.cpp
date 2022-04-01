#include "CMatriceBase.h"

CMatriceBase::CMatriceBase()
{
	uiMABNbLignes = 0;
	uiMABNbColonnes = 0;
}

CMatriceBase::CMatriceBase(CMatriceBase& MATParam)
{
	uiMABNbLignes = MATParam.uiMABNbLignes;
	uiMABNbColonnes = MATParam.uiMABNbColonnes;
}

CMatriceBase::CMatriceBase(unsigned int iParamNbLignes, unsigned int iParamNbColonnes)
{
	uiMABNbLignes = iParamNbLignes;
	uiMABNbColonnes = iParamNbColonnes;
}

CMatriceBase::~CMatriceBase()
{
}



void CMatriceBase::MABModifierNbLignes(unsigned int iParamNbLignes)
{
	uiMABNbLignes = iParamNbLignes;
}

void CMatriceBase::MABModifierNbColonnes(unsigned int iParamNbColonnes)
{
	uiMABNbColonnes = iParamNbColonnes;
}

unsigned int CMatriceBase::MABLireNbLignes()
{
	return uiMABNbLignes;
}

unsigned int CMatriceBase::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

