/**
 * @file CArc.h
 * @author LJ BV JM
 * @brief Contient la declaration de la classe CArc
 * CArc permet de creer et gerer un arc reliant des sommets
 * 
 * @version 0.1
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

class CArc
{
private:
	int iARCDestination;

public:
	/**
	 * @brief Constructeur par defaut : Creer un objet CArc
	 *
	 */
	CArc(int iNumeroSommet);


	/**
	 * @brief Getter pour le sommet de destination
	 * 
	 * @return int Numero du sommet de destination
	 */
	int ARCLireDestination()const;

	/**
	 * @brief Setter pour le sommet de destination
	 * 
	 * @param iNumeroSommet Numero du sommet de destination
	 */
	void ARCModifierDestination(int iNumeroSommet);
};

