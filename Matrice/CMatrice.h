#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CListe.h"
#include "CProxy_row.h"
#include "iostream"

template <typename ELEMENT>
class CMatrice {
	using MATPROProxy = CProxy_row<CListe<ELEMENT>>;

	private :
		char* pcTypeMatrice;
		unsigned int uiMABNbLignes;
		unsigned int uiMABNbColonnes;
		CListe<ELEMENT> * pLISMATListe;


	public :
		CMatrice();
		CMatrice(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes);
		~CMatrice();

		
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
		ELEMENT MABLireElement(unsigned int uiLignes, unsigned int uiColonnes);
		void MABAfficherMatrice();
};



template <typename ELEMENT>
CMatrice<ELEMENT>::CMatrice()
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = 0;
	uiMABNbColonnes = 0;
	pLISMATListe = new CListe<ELEMENT>();
}

template <typename ELEMENT>
CMatrice<ELEMENT>::CMatrice(unsigned int uiParamNbLignes, unsigned int uiParamNbColonnes)
{
	pcTypeMatrice = NULL;
	uiMABNbLignes = uiParamNbLignes;
	uiMABNbColonnes = uiParamNbColonnes;
	unsigned int uiTailleListe = uiParamNbLignes * uiParamNbColonnes;
	pLISMATListe = new CListe<ELEMENT>(uiTailleListe);
}

template <typename ELEMENT>
CMatrice<ELEMENT>::~CMatrice()
{
	if (pcTypeMatrice) {
		free(pcTypeMatrice);
	}
}

template <typename ELEMENT>
void CMatrice<ELEMENT>::MABModifierTypeMatrice(const char* pcParamTypeMatrice)
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
void CMatrice<ELEMENT>::MABModifierNbLignes(unsigned int uiParamNbLignes)
{
	uiMABNbLignes = uiParamNbLignes;
}

template <typename ELEMENT>
void CMatrice<ELEMENT>::MABModifierNbColonnes(unsigned int uiParamNbColonnes)
{
	uiMABNbColonnes = uiParamNbColonnes;
}

template <typename ELEMENT>
char* CMatrice<ELEMENT>::MABLireTypeMatrice()
{
	return pcTypeMatrice;
}

template <typename ELEMENT>
unsigned int CMatrice<ELEMENT>::MABLireNbLignes()
{
	return uiMABNbLignes;
}

template <typename ELEMENT>
unsigned int CMatrice<ELEMENT>::MABLireNbColonnes()
{
	return uiMABNbColonnes;
}

template <typename ELEMENT>
ELEMENT CMatrice<ELEMENT>::MABLireElement(unsigned int uiLignes, unsigned int uiColonnes)
{
	if (uiLignes > uiMABNbLignes || uiColonnes > uiMABNbColonnes) {
		throw "coucou";
	}
	return (*pLISMATListe[uiLignes * uiMABNbColonnes + uiColonnes]);
}

template <typename ELEMENT>
void CMatrice<ELEMENT>::MABAfficherMatrice() {
	if ((uiMABNbLignes != 0) && (uiMABNbColonnes != 0)) {
		for (unsigned int uiligne = 0; uiligne < uiMABNbLignes; uiligne++) {
			for (unsigned int uicolonne = 0; uicolonne < uiMABNbColonnes; uicolonne++) {
				if (uicolonne == uiMABNbColonnes - 1) {
					cout << MABLireElement(uiligne, uicolonne) <<"\n";
				}
				else {
					cout << MABLireElement(uiligne, uicolonne) << "\t";
				}
			}
		}
	}
	//ICI AJOUTER EXCEPTION OU ERREUR DANS LE ELSE OUI
}
