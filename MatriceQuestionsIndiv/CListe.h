/**
 * @file CListe.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CListe
 * CListe permet de gerer une Liste de n'importe quel MType
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
	MType * pMLISTableau;
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
	CListe(const CListe &LISParam);

	/**
	 * @brief Destructeur : Libere la memoire alloue pour l'objet Liste
	 * 
	 */
	~CListe();



	/**
	 * @brief Getter pour la taille de la liste
	 * 
	 * @return unsigned int, la taille de la liste actuelle
	 */
	unsigned int LISLireTaille()const;

	/**
	 * @brief Setter pour la taille de la liste
	 * 
	 * @param uiTaille Nouvelle taile souhaite de la liste 
	 */
	void LISModifierTaille(unsigned int uiTaille);

	/**
	 * @brief Surcharge de l'operateur d'indice du tableau
	 *
	 * @param uiIndex Indice de l'element souhaite dans la liste
	 * @return MType& Reference de l'element souhaite
	 */
	const MType& operator[](unsigned int uiIndex)const;

	/**
	 * @brief Surcharge de l'operateur d'indice du tableau
	 * 
	 * @param uiIndex Indice de l'element souhaite dans la liste
	 * @return MType& Reference de l'element souhaite
	 */
	MType& operator[](unsigned int uiIndex);

	/**
	 * @brief Surcharge de l'operateur d'affectation, recopie LISParam dans la liste appelante
	 * 
	 * @param LISParam Liste a recopier
	 * @return CListe<MType>& Reference de la liste recopiee
	 */
	CListe<MType>& operator=(const CListe<MType>& LISParam);
};

#include "CListe.cpp"