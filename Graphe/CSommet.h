#pragma once

#include "CArc.h"
#include "CListe.h"
#include "CException.h"

class CSommet
{
private:
	int iSOMNumero;
	CListe<CArc*>* pLISSOMArrivant;
	CListe<CArc*>* pLISSOMPartant;
public:
	CSommet();
	CSommet(int iNumero);
	CSommet(const CSommet& SOMArg);
	~CSommet();

	int SOMLireNumero()const;
	void SOMModifierNumero(int iNumero);
	CListe<CArc*>& SOMLireArrivant();
	const CListe<CArc*>& SOMLireArrivant()const;
	CListe<CArc*>& SOMLirePartant();
	const CListe<CArc*>& SOMLirePartant()const;
	void SOMAjouterArrivant(CArc* pArcArrivant);
	void SOMAjouterPartant(CArc* pArcPartant);
	void SOMSupprimerArrivant(CArc* pArcArrivant);
	void SOMSupprimerPartant(CArc* pArcPartant);

};


