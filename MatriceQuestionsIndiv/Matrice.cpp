/**
 * @file Matrice.cpp
 * @author LJ BV JM
 * @brief Contient la fonction main du programme
 * 
 * 
 * @version 0.1
 * @date 2022-05-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "CMatriceBase.h"
#include "CParseur.h"
#include "CMatricePlus.h"
#include "CException.h"

using namespace std;

int main(int iArgc, char * ppcArgv[])
{
	if (iArgc > 1) {
		CListe<CMatricePlus<double>> LISListeMatrices(iArgc - 1);
		CMatricePlus<double> MAPResultat;
		int iBoucleI;
		int iNbReelMatrice = 0;
		double dC;
		char cCharactere;

		// Lecture de tous les fichiers et creation des matrices
		cout << "Matrices lu dans les fichiers : " << endl;
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			try
			{
				LISListeMatrices[iNbReelMatrice] = CParseur::PARLirefichier(ppcArgv[iBoucleI + 1]);

				//Affichage
				cCharactere = 'A' + iNbReelMatrice;
				cout << "Matrice " << cCharactere << " =\n";
				LISListeMatrices[iNbReelMatrice].MABAfficherMatrice();
				

				cout << "Determinant de la matrice : ";
				cout << LISListeMatrices[iNbReelMatrice].MAPCalcDet();
				cout << "\n";

				iNbReelMatrice += 1;

				
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}
		}

		
	}
	else {
		cout << "Veuillez donner le chemin d'au moins un fichier lors de l'appel du programme" << "\n";
	}

	return 0;
}