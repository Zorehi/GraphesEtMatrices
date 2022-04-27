#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "CListe.h"
#include "CMatrice.h"

template <typename ELEMENT>
class CMatricePlus : public CMatriceBase {
	public :
		CMatricePlus &operator*(double ELM2param);
		CMatricePlus &operator*(CMatricePlus& MAP2);
		CMatricePlus &operator/(double ELM2param);
		CMatricePlus &operator+(CMatricePlus& MAP2);
		CMatricePlus &operator-(CMatricePlus& MAP2);
		CMatricePlus MAPTranspose();
		CMatricePlus MAPParser(char* pcFile);

};

template <typename ELEMENT>
CMatricePlus<ELEMENT> &CMatricePlus<ELEMENT>::operator*(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> &CMatricePlus<ELEMENT>::operator*(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT>& CMatricePlus<ELEMENT>::operator/(double ELM2param) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT>& CMatricePlus<ELEMENT>::operator+(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT>& CMatricePlus<ELEMENT>::operator-(CMatricePlus& MAP2) {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPTranspose() {

}

template <typename ELEMENT>
CMatricePlus<ELEMENT> CMatricePlus<ELEMENT>::MAPParser(char* pcFile) {

}
