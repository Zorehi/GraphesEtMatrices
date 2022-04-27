#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CListe.h"
#include "CMatrice.h"

template <typename ELEMENT>
class CMatricePlus : public CMatriceBase {
	public :
		CMatricePlus operator*(double ELM2param);
		CMatricePlus operator*(CMatricePlus& MAP2);
		CMatricePlus operator/(double ELM2param);
		CMatricePlus operator+(CMatricePlus& MAP2);
		CMatricePlus operator-(CMatricePlus& MAP2);
		CMatricePlus MAPTranspose();
		CMatricePlus MAPParser(char* pcFile);

};

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator*(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator*(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator/(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator+(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::operator-(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPTranspose() {
	unsigned int NbLignes = MABLireNbLignes();
	unsigned int NbColonnes = MABLireNbColonnes();

	CMatrice<ELEMENT> MatriceTransposee = new CMatrice<ELEMENT>(NbColonnes, NbLignes);

	for (unsigned int uiBoucleL = 0; uiBoucleL < NbLignes; uiBoucleL++) {
		for (unsigned int uiBoucleC = 0; uiBoucleC < NbColonnes; uiBoucleC++) {

			MatriceTransposee[uiBoucleC][uiBoucleL] = this[uiBoucleL][uiBoucleC];
		}
	}

	return MatriceTransposee;
}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPParser(char* pcFile) {

}
