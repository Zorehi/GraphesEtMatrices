/**
 * @file CSommet.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CSommet
 * CSommet permet de gerer un sommet d'un graphe
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

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
	/**
	 * @brief Constructeur par defaut : Creer un objet Sommet
	 *
	 */
	CSommet();

	/**
	 * @brief Constructeur de confort : Creer un Sommet avec le numero donne
	 * 
	 * @param iNumero Numero du sommet
	 */
	CSommet(int iNumero);

	/**
	 * @brief Constructeur de recopie : Creer un duplicata d'un Sommet deja cree
	 *
	 * @param SOMArg Sommet a dupliquer
	 */
	CSommet(const CSommet& SOMArg);

	/**
	 * @brief Destructeur : Libere la memoire alloue pour l'objet Sommet
	 *
	 */
	~CSommet();


	/**
	 * @brief Getter pour le numero du sommet
	 * 
	 * @return int Numero du sommet
	 */
	int SOMLireNumero()const;

	/**
	 * @brief Setter pour le numero du sommet
	 * 
	 * @param iNumero Nouveau numero du sommet
	 */
	void SOMModifierNumero(int iNumero);

	/**
	 * @brief Getter pour la liste des Arcs arrivant
	 * 
	 * @return const CListe<CArc*>& Objet CListe contenant les pointeurs vers les arcs arrivant
	 */
	const CListe<CArc*>& SOMLireArrivant()const;

	/**
	 * @brief Getter pour la liste des Arcs arrivant
	 *
	 * @return const CListe<CArc*>& Objet CListe contenant les pointeurs vers les arcs arrivant
	 */
	CListe<CArc*>& SOMLireArrivant();

	/**
	 * @brief Getter pour la liste des Arcs partant
	 * 
	 * @return CListe<CArc*>& Objet CListe contenant les pointeurs vers les arcs partant
	*/
	CListe<CArc*>& SOMLirePartant();

	/**
	 * @brief Getter pour la liste des Arcs partant en lecture uniquement
	 * 
	 * @return const CListe<CArc*>& Objet CListe contenant les pointeurs vers les arcs partant
	 */
	const CListe<CArc*>& SOMLirePartant()const;

	/**
	 * @brief Methode pour ajouter un Arc arrivant
	 * 
	 * @param pArcArrivant Arc à ajouter
	 */
	void SOMAjouterArrivant(CArc* pArcArrivant);

	/**
	 * @brief Methode pour ajouter un Arc partant
	 * 
	 * @param pArcPartant Arc à ajouter
	 */
	void SOMAjouterPartant(CArc* pArcPartant);
	
	/**
	 * @brief Methode pour supprimer un Arc arrivant
	 * 
	 * @param pArcArrivant Arc a supprimer
	 */
	void SOMSupprimerArrivant(CArc* pArcArrivant);

	/**
	 * @brief Methode pour supprimer un Arc partant
	 * 
	 * @param pArcPartant Arc a supprimer
	 */
	void SOMSupprimerPartant(CArc* pArcPartant);

	/**
	 * @brief 
	 * @param SOMArg 
	 * @return 
	*/
	CSommet& operator=(const CSommet& SOMArg);

};