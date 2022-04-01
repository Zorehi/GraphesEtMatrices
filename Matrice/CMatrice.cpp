#include "CMatrice.h"

CMatrice::CMatrice()
{
	CMATiNbLignes = 0;
	CMATiNbColonnes = 0;
}

CMatrice::CMatrice(CMatrice& MATParam)
{
	CMATiNbLignes = MATParam.CMATiNbLignes;
	CMATiNbColonnes = MATParam.CMATiNbColonnes;

}

CMatrice::CMatrice(int iParamNbLignes, int iParamNbColonnes) 
{
	CMATiNbLignes = iParamNbLignes;
	CMATiNbColonnes = iParamNbColonnes;
}

CMatrice::~CMatrice()
{
}



void CMatrice::CMATModifierNbLignes(int iParamNbLignes)
{
	CMATiNbLignes = iParamNbLignes;
}

void CMatrice::CMATModifierNbColonnes(int iParamNbColonnes)
{
	CMATiNbColonnes = iParamNbColonnes;
}

int CMatrice::CMATGetNbLignes()
{
	return CMATiNbLignes;
}

int CMatrice::CMATGetNbColonnes()
{
	return CMATiNbColonnes;
}

