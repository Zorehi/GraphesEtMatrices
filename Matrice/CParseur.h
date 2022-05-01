#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "CMatricePlus.h"

class CParseur
{
	private:
		char* pcFichier;
		FILE* pfFichier;

	public:
		CParseur();
		CParseur(const char* pcCheminFichier);

		char* PARLireChemin();
		const char* PARLireLigne();

		void PARLirefichier();

		/*
		template <class MType>
		CMatricePlus<MType> PARLirefichier();

		*/

};
