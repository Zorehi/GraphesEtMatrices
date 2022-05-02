#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class CException
{
private:
	int iEXCVal;
	char* pcEXCMsg;
public:
	/**
	 * @brief Constructeur par defaut : Creer un objet Exception
	 * 
	 */
	CException();

	/**
	 * @brief Constructeur de confort : Creer un object Exception avec les parametres donnes
	 * 
	 * @param iNewVal Valeur de l'exception
	 * @param pcNewMsg Message de l'exception
	 */
	CException(int iNewVal, const char* pcNewMsg);

	/**
	 * @brief Destructeur : Libere la memoire alloue pour l'objet Liste
	 * 
	 */
	~CException();



	/**
	 * @brief Getter pour la valeur de l'exception
	 * 
	 * @return int Valeur de l'exception
	 */
	int EXCLireVal();

	/**
	 * @brief Getter pour le message de l'exception
	 * 
	 * @return const char* Message de l'exception
	 */
	const char* EXCLireMsg();

	/**
	 * @brief Setter pour la valeur de l'exception
	 * 
	 * @param iNewVal Nouvelle valeur souhaite de l'exception
	 */
	void EXCModifierVal(int iNewVal);

	/**
	 * @brief Setter pour le message de l'exception
	 * 
	 * @param pcNewMsg Nouveau message souhaite de l'exception
	 */
	void EXCModifierMsg(const char* pcNewMsg);
};

