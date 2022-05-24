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

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"
#include "CException.h"

int main(int iArgc, char * ppcArgv[])
{
	if (iArgc == 1) {
		CMatriceBase<double> MABMatrice;
		CMatriceBase<double> MABMatrice2;
		MABMatrice = CMatriceBase<double>(3, 3);
		MABMatrice[0][0] = 0;
		MABMatrice[0][1] = 1;
		MABMatrice[0][2] = 2;
		MABMatrice[1][0] = 3;
		MABMatrice[1][1] = 4;
		MABMatrice[1][2] = 5;
		MABMatrice[2][0] = 6;
		MABMatrice[2][1] = 7;
		MABMatrice[2][2] = 8;

		MABMatrice.MABAfficherMatrice();
		
		MABMatrice2 = CMatriceBase<double>(MABMatrice, 1);

		MABMatrice2.MABAfficherMatrice();

	}

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
				cout << "\n";

				iNbReelMatrice += 1;
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}
		}

		cout << "Veuillez saisir une valeur de C : ";
		cin >> dC;
		cout << "\n";

		// Multiplication des matrices par une constante
		cout << "Resultat de la multiplication des matrices par " << dC << " :\n";
		for (iBoucleI = 0; iBoucleI < iNbReelMatrice; iBoucleI++)
		{
			try
			{
				MAPResultat = LISListeMatrices[iBoucleI] * dC;

				//Affichage
				cCharactere = 'A' + iBoucleI;
				cout << cCharactere << " * " << dC << " =\n";
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}

			cout << "\n";
		}

		// Division des matrices par une constante
		cout << "Resultat de la division des matrices par " << dC << " :\n";
		for (iBoucleI = 0; iBoucleI < iNbReelMatrice; iBoucleI++)
		{
			try
			{
				MAPResultat = LISListeMatrices[iBoucleI] / dC;

				//Affichage
				cCharactere = 'A' + iBoucleI;
				cout << cCharactere << " / " << dC << " =\n";
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}
			
			cout << "\n";
		}
		
		// Si le nombre de matrice est egale a 1 la suite des operations ne sert a rien
		if (iNbReelMatrice > 1) {
			// Addition de toutes les matrices
			cout << "Resultat de l'addition de toutes les matrices :\n";
			CMatricePlus<double> MAPResultatAddition(LISListeMatrices[0]);

			try
			{
				for (iBoucleI = 1; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					MAPResultatAddition = MAPResultatAddition + LISListeMatrices[iBoucleI];
				}

				//Affichage
				for (iBoucleI = 0; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					if (iBoucleI == 0) {
						cCharactere = 'A';
						cout << cCharactere;
					}
					else {
						cCharactere = 'A' + iBoucleI;
						cout << " + " << cCharactere;
					}
				}
				cout << " =\n";

				MAPResultatAddition.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}

			// Operation (M1-M2+M3-M4+...)
			cout << "Resultat de l'operation suivante (M1-M2+M3-M4+M5-M6+...) :\n";
			CMatricePlus<double> MAPResultatOperation(LISListeMatrices[0]);
			try
			{
				for (iBoucleI = 1; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					if (iBoucleI % 2 == 0) {
						MAPResultatOperation = MAPResultatOperation + LISListeMatrices[iBoucleI];
					}
					else {
						MAPResultatOperation = MAPResultatOperation - LISListeMatrices[iBoucleI];
					}
				}

				//Affichage
				for (iBoucleI = 0; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					if (iBoucleI == 0) {
						cCharactere = 'A';
						cout << cCharactere;
					}
					else {
						cCharactere = 'A' + iBoucleI;
						if (iBoucleI % 2 == 0) {
							cout << " + " << cCharactere;
						}
						else {
							cout << " - " << cCharactere;
						}
					}
				}
				cout << " =\n";

				MAPResultatOperation.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}

			// Multiplication des matrices entre elles
			cout << "Resultat de la multiplication des matrices entre elles :\n";
			CMatricePlus<double> MAPResultatProduit(LISListeMatrices[0]);
			try
			{
				for (iBoucleI = 1; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					MAPResultatProduit = MAPResultatProduit * LISListeMatrices[iBoucleI];
				}

				//Affichage
				for (iBoucleI = 0; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					if (iBoucleI == 0) {
						cCharactere = 'A';
						cout << cCharactere;
					}
					else {
						cCharactere = 'A' + iBoucleI;
						cout << " * " << cCharactere;
					}
				}
				cout << " =\n";

				MAPResultatProduit.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n\n";
			}
		}
		else {
			cout << "Pour realiser les operations telles que : \n\t- La somme de toutes les matrices\n\t- La multplication de toutes les matrices entre elles\n";
			cout << "Il faut donner plus de 1 fichier lors du lancement du programme !";
		}
	}
	else {
		cout << "Veuillez donner le nom d'un fichier lors de l'appel du programme" << "\n";
	}

	return 0;
}