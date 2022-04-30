#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "CMatricePlus.h"

class CParseur
{
	private:
		char* pcFichier;

	public:
		CParseur();
		CParseur(char* pcCheminFichier);

		template <class MType>
		CMatricePlus<MType> PARLirefichier();

};
