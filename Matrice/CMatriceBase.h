#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CListe.h"
#include "CProxy_row.h"
#include "iostream"
#include "fstream"
using namespace std;

template <typename ELEMENT>
class CMatriceBase {
	using MATPROProxy = CProxy_row<CListe<ELEMENT>>;

	private :
		char* pcTypeMatrice;
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;
		CListe<ELEMENT> * pLISMATListe;


	public :
		CMatriceBase();
		CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		~CMatriceBase();

		
		void MABModifierTypeMatrice(const char* pcParamTypeMatrice);
		void MABModifierNbLignes(unsigned int uiParamNbLignes);
		void MABModifierNbColonnes(unsigned int uiParamNbColonnes);
		
		char* MABLireTypeMatrice();
		unsigned int MABLireNbLignes();
		unsigned int MABLireNbColonnes();
		//ELEMENT& operator[](unsigned int uiLignes);
		MATPROProxy operator[](unsigned int uiLignes) {
			return MATPROProxy(*pLISMATListe, uiLignes, uiMABNbColonnes);
		}
		void MABAfficherMatrice();
		void operator<<();
};



template <typename ELEMENT>
CMatriceBase<ELEMENT>::CMatriceBase()
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = 0;
	uiMABNbColonnes = 0;
	pLISMATListe = new CListe<ELEMENT>();
}

template <typename ELEMENT>
CMatriceBase<ELEMENT>::CMatriceBase(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes)
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = uiParamNbLignes;
	uiMABNbColonnes = uiParamNbColonnes;
	unsigned int uiTailleListe = uiParamNbLignes * uiParamNbColonnes;
	pLISMATListe = new CListe<ELEMENT>(uiTailleListe);
}

template <typename ELEMENT>
CMatriceBase<ELEMENT>::~CMatriceBase()
{
	if (pcTypeMatrice) {
		free(pcTypeMatrice);
	}
}

template <typename ELEMENT>
void CMatriceBase<ELEMENT>::MABModifierTypeMatrice(const char* pcParamTypeMatrice)
{
	if (pcTypeMatrice) {
		free(pcTypeMatrice);
	}

	pcTypeMatrice = (char*)malloc(sizeof(char) * strlen(pcParamTypeMatrice) + 1);
	if (!pcTypeMatrice) {
		//erreur memoire
		throw "Pas assez d'espace mémoire";
	}
	else {
		strcpy_s(pcTypeMatrice, strlen(pcParamTypeMatrice) + 1, pcParamTypeMatrice);
	}
}

template <typename ELEMENT>
void CMatriceBase<ELEMENT>::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	uiMABNbLignes = uiParamNbLignes;
}

template <typename ELEMENT>
void CMatriceBase<ELEMENT>::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	uiMABNbColonnes = uiParamNbColonnes;
}

template <typename ELEMENT>
char* CMatriceBase<ELEMENT>::MABLireTypeMatrice()
{
	return pcTypeMatrice;
}

template <typename ELEMENT>
unsigned int CMatriceBase<ELEMENT>::MABLireNbLignes()
{
	return uiMABNbLignes;
}

template <typename ELEMENT>
unsigned int CMatriceBase<ELEMENT>::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

template <typename ELEMENT>
void CMatriceBase<ELEMENT>::MABAfficherMatrice() {
	if ((uiMABNbLignes != 0) && (uiMABNbColonnes != 0)) {
		for (unsigned int uiligne = 0; uiligne < uiMABNbLignes; uiligne++) {
			for (unsigned int uicolonne = 0; uicolonne < uiMABNbColonnes; uicolonne++) {
				if (uicolonne == uiMABNbColonnes - 1) {
					cout << pLISMATListe[uiligne * uiMABNbColonnes + uicolonne] <<"\n";
				}
				else {
					cout << pLISMATListe[uiligne * uiMABNbColonnes + uicolonne] << "\t";
				}
			}
		}
	}
	//ICI AJOUTER EXCEPTION OU ERREUR DANS LE ELSE
}

//template <typename ELEMENT>
//ELEMENT& CMatriceBase<ELEMENT>::operator[](unsigned int uiLignes) {
//	return (*pLISMATListe)[uiLignes];
//}
