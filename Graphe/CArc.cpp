/**
 * @file CArc.cpp
 * @author LJ BV JM
 * @brief Contient la declaration des methodes de la classe CArc
 * CArc permet de creer et gerer un arc reliant des sommets
 * 
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CArc.h"

CArc::CArc(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}

int CArc::ARCLireDestination()const
{
	return iARCDestination;
}

void CArc::ARCModifierDestination(int iNumeroSommet)
{
	iARCDestination = iNumeroSommet;
}