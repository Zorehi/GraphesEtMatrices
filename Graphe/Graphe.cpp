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
#include "CParseur.h"
#include "CAnalyseurLexical.h"
#include "CGraphe.h"

using namespace std;

int main(int iArgc, char* ppcArgv[])
{
	/*
	try
	{
		CGraphe monGraphe = CParseur::PARLirefichier("test_graphe1.txt");
	}
	catch (CException& EXCException)
	{
		cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
		cout << EXCException.EXCLireMsg() << "\n\n";
	}
	*/

	try
	{
		CAnalyseurLexical::ANLAnalyserFichier("test_graphe1.txt");
	}
	catch (CException& EXCException)
	{
		cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
		cout << EXCException.EXCLireMsg() << "\n\n";
	}
    
}