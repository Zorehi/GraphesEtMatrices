#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CMatrice.h"

template <typename ELEMENT>
class CMatricePlus : public CMatrice<ELEMENT> {
	public :
		CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		CMatricePlus<ELEMENT> operator*(double ELM2param);
		CMatricePlus<ELEMENT> operator*(CMatricePlus<ELEMENT>& MAP2);
		CMatricePlus<ELEMENT> operator/(double ELM2param);
		CMatricePlus<ELEMENT> operator+(CMatricePlus<ELEMENT>& MAP2);
		CMatricePlus<ELEMENT> operator-(CMatricePlus<ELEMENT>& MAP2);
		CMatricePlus<ELEMENT> MAPTranspose();
		CMatricePlus<ELEMENT> MAPParser(char* pcFile);

};

template <typename ELEMENT>
CMatricePlus<ELEMENT>::CMatricePlus(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes) : CMatrice<ELEMENT>(uiParamNbLignes, uiParamNbColonnes)
{

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator*(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator*(CMatricePlus<ELEMENT>& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator/(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator+(CMatricePlus<ELEMENT>& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator-(CMatricePlus<ELEMENT>& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPTranspose() {

	unsigned int NbLignes = this->MABLireNbLignes();
	unsigned int NbColonnes = this->MABLireNbColonnes();

	CMatricePlus<ELEMENT> MatriceTransposee(NbColonnes, NbLignes);

	for (unsigned int uiBoucleL = 0; uiBoucleL < NbLignes; uiBoucleL++) {
		for (unsigned int uiBoucleC = 0; uiBoucleC < NbColonnes; uiBoucleC++) {

			//MatriceTransposee[uiBoucleC][uiBoucleL] = (*pLISMATListe)[uiBoucleL * NbColonnes + uiBoucleC];
			//MatriceTransposee[uiBoucleC][uiBoucleL] = this->MABLireElement(uiBoucleL, uiBoucleC);
			MatriceTransposee[uiBoucleC][uiBoucleL] = (*this)[uiBoucleL][uiBoucleC];
		}
	}

	return MatriceTransposee;
}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPParser(char* pcFile) {

}
