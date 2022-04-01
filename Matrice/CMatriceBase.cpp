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

CMatriceBase::CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes)
{
	uiMABNbLignes = uiParamNbLignes;
	uiMABNbColonnes = uiParamNbColonnes;
}

CMatriceBase::~CMatriceBase()
{
}

void CMatriceBase::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	uiMABNbLignes = uiParamNbLignes;
}

void CMatriceBase::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	uiMABNbColonnes = uiParamNbColonnes;
}

unsigned int CMatriceBase::MABLireNbLignes()
{
	return uiMABNbLignes;
}

unsigned int CMatriceBase::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

