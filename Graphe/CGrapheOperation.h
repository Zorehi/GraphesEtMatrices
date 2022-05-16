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
};

