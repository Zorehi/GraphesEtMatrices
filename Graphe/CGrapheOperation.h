/**
 * @file CGrapheOperation.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CGrapheOperation
 * CGrapheOperation permet de faire des operations sur un Graphe
 * 
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "CGraphe.h"
#include "CArc.h"
#include "CSommet.h"

class CGrapheOperation
{
	public:
		/**
		 * @brief Methode static pour inverser un Graphe
		 * 
		 * @param GRAArg Graphe a inverser
		 * @return CGraphe Graphe inverser
		 */
		static CGraphe GROInverserArc(const CGraphe& GRAArg);

		/**
		 * @brief Methode static pour creer un Graphe non oriente
		 *
		 * @param GRAArgOriente Graphe orient�
		 * @return GRAArgOriente Graphe non orient�
		 */
		static CGraphe GROCreeNonOriente(const CGraphe& GRAArgOriente);
};

