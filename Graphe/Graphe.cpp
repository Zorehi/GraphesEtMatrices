/**
 * @file Graphe.cpp
 * @author LJ BV JM
 * @brief Contient la fonction main du programme
 *
 *
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "CException.h"
#include "CGraphe.h"
#include "CAnalyseurLexical.h"
#include "CAnalyseurSyntaxique.h"
#include "CGrapheOperation.h"

using namespace std;

int main(int iArgc, char* ppcArgv[])
{
	if (iArgc > 1) {
		CGraphe monGraphe;
		CGraphe newGraphe;

		// Lecture du fichier passe en parametre, creation du graphe, et affichage de ce graphe
		try
		{
			monGraphe = CAnalyseurSyntaxique::ANSAnalyserFichier(ppcArgv[1]);

			cout << "Graphe du fichier" << " :\n";
			monGraphe.GRAAfficherGraphe();
			cout << "\n";
		}
		catch (CException& EXCException)
		{
			cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
			cout << EXCException.EXCLireMsg() << "\n\n";
		}

		/*
		// Creation d'un nouveau graphe en inversant tout les arc du premier graphe, et affichage de ce graphe
		try
		{
			newGraphe = CGrapheOperation::GROInverserArc(monGraphe);

			cout << "Graphe avec arc inverses" << " =\n";
			newGraphe.GRAAfficherGraphe();
			cout << "\n";
		}
		catch (CException& EXCException)
		{
			cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
			cout << EXCException.EXCLireMsg() << "\n\n";
		}
		*/	
	}
}