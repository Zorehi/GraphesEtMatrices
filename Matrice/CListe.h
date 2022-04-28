#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

template <typename ELEMENT>
class CListe {

private:
	ELEMENT *peLISTableau;
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
	 * @return ELEMENT& Reference de l'element souhaite
	 */
	ELEMENT& operator[](unsigned int uiIndex);
};

#include "CListe.cpp"