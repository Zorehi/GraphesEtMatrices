/**
 * @file CGraphe.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CGraphe
 * CGraphe permet de creer et gerer un graphe contenant
 * des sommets relie par des arcs
 *
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <stdio.h>

#include "CSommet.h"
#include "CListe.h"
#include "CArc.h"

#define GrapheOriente 0
#define GrapheNonOriente 1

class CGraphe
{
private:
	CListe<CSommet*> LISGRASommet;
	unsigned int uiGRAType;

public:
	/**
	 * @brief Constructeur par defaut : Creer un objet Graphe
	 *
	 */
	CGraphe();

	/**
	 * @brief Constructeur de confort : Creer un objet Graphe avec son type en parametre
	 * 
	 * @param uiType 
	*/
	CGraphe(unsigned int uiType);
	
	/**
	 * @brief Constructeur de recopie : Creer un duplicata d'un Graphe deja cree
	 *
	 * @param GRAParam Graphe a dupliquer
	 */
	CGraphe(const CGraphe& GRAParam);

	/**
	 * @brief Destructeur : Libere la memoire alloue pour l'objet Graphe
	 *
	 */
	~CGraphe();

	/**
	 * @brief Getter pour la liste de sommet du Graphe
	 * 
	 * @return const CListe<CSommet*>& objet CListe contenant les pointeur sur les objets sommets
	 */
	const CListe<CSommet*>& GRALireSommet()const;

	/**
	 * @brief Getter pour le type du Graphe
	 * 
	 * @return le type du Graphe
	*/
	const unsigned int GRALireType()const;

	/**
	 * @brief Methode pour ajouter un sommet au graphe
	 * 
	 * @param pSommet Pointeur sur l'objet sommet à ajouter
	 */
	void GRAAjouterSommet(CSommet* pSommet);

	/**
	 * @brief Methode pour ajouter un sommet au graphe
	 *
	 * @param pSommet Pointeur sur l'objet sommet à ajouter
	 */
	void GRAAjouterSommet(int iNumSommet);

	/**
	 * @brief Modifie le numero du Sommet
	 * 
	 * @param pSommet Pointeur du Sommet a modifier
	 * @param iNewNum Nouveau numero du Sommet
	*/
	void GRAModifierSommet(CSommet* pSommet, int iNewNum);

	/**
	 * @brief Modifie le numero du Sommet et donc le numero de destination des Arcs qui y arrivent
	 *
	 * @param iOldNum Numero du Sommet a modifier
	 * @param iNewNum Nouveau numero du Sommet
	*/
	void GRAModifierSommet(int iOldNum, int iNewNum);

	/**
	 * @brief Supprime le Sommet et les Arcs qui y arrivent et qui y partent
	 * 
	 * @param pSommet Pointeur vers le Sommet a supprimer
	*/
	void GRASupprimerSommet(CSommet* pSommet);

	/**
	 * @brief Supprime le Sommet et les Arcs qui y arrivent et qui y partent
	 * 
	 * @param iNumSommet Numero du Sommet a supprimer
	*/
	void GRASupprimerSommet(int iNumSommet);

	/**
	 * @brief Ajoute un arc 
	 * 
	 * @param iDebut Numero du Sommet partant
	 * @param iDestination Numero du Sommet de destination
	*/
	void GRAAjouterArc(int iDebut, int iDestination);

	/**
	 * @brief Modifie l'Arc en changeant son Sommet de destination
	 * 
	 * @param pArc Pointeur sur l'Arc a modifier
	 * @param iNewDestination Numero du nouveau Sommet de destination de l'Arc
	*/
	void GRAModifierArc(CArc* pArc, int iNewDestination);

	/**
	 * @brief Modifie l'Arc en changeant son Sommet de destination
	 * 
	 * @param iProvenance Numero du Sommet partant de l'Arc 
	 * @param iDestination Numero du Sommet de destination de l'Arc
	 * @param iNewDestination Nouveau numero du Sommet de destination de l'Arc
	*/
	void GRAModifierArc(int iProvenance, int iDestination, int iNewDestination);
	
	/**
	 * @brief Supprime un Arc
	 * 
	 * @param pArc Pointeur sur l'arc a enlever
	*/
	void GRASupprimerArc(CArc* pArc);

	/**
	 * @brief Supprime un Arc
	 * 
	 * @param iProvenance Numero du Sommet partant
	 * @param iDestination Numero du Sommet de destination
	*/
	void GRASupprimerArc(int iProvenance, int iDestination);

	/**
	 * @brief Methode pour afficher le graphe sur le shell
	 * 
	 */
	void GRAAfficherGraphe()const;

	/**
	 * @brief Surcharge de l'operateur d'assignation
	 * 
	 * @param GRAParam Graphe a copier
	 * @return CGraphe& Graphe retourne
	 */
	CGraphe& operator=(const CGraphe& GRAParam);
};