#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CException.h"

#define Alloc_Mem_Impossible 110
#define Error_Realloc 120
#define Index_Out_Of_Range 130

template <class MType>
class CListe {

private:
	MType *peLISTableau;
	unsigned int uiLISTaille;

public:
	/**
	 * @brief Constructeur par defaut : Creer un objet Liste de type <MType>
	 * 
	 */
	CListe();

	/**
	 * @brief Constructeur de confort : Creer une liste avec les dimensions donnees
	 * 
	 * @param uiTaille Taille de la liste souhaite
	 */
	CListe(unsigned int uiTaille);

	/**
	 * @brief Constructeur de recopie : Creer un duplicata d'une Liste deja cree
	 * 
	 * @param LISParam Liste a dupliquer
	 */
	CListe(CListe &LISParam);

	/**
	 * @brief Destructeur : libere la memoire alloue pour l'objet Liste
	 * 
	 */
	~CListe();



	/**
	 * @brief Getter pour la taille de la liste
	 * 
	 * @return unsigned int, la taille de la liste actuelle
	 */
	unsigned int LISLireTaille();

	/**
	 * @brief Setter pour la taille de la liste
	 * 
	 * @param uiTaille Nouvelle taile souhaite de la liste 
	 */
	void LISModifierTaille(unsigned int uiTaille);

	/**
	 * @brief Surcharge de l'operateur d'indice du tableau
	 * 
	 * @param uiIndex Indice du l'element souhaite dans la liste
	 * @return MType& Reference de l'element souhaite
	 */
	MType& operator[](unsigned int uiIndex);

	CListe<MType>& operator=(CListe<MType>& LISParam);
};

#include "CListe.cpp"