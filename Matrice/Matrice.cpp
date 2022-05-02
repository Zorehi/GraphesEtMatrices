// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"
#include "CException.h"

using namespace std;


int main(int iArgc, char * ppcArgv[])
{
	if (iArgc > 1) {
		//CListe<CMatricePlus<double>> LISListeMatrices(iArgc - 1);
		CMatricePlus<double> * LISListeMatrices = new CMatricePlus<double>[iArgc - 1];
		CMatricePlus<double> MAPResultat;
		int iBoucleI;
		int iNbReelMatrice = 0;
		double dC;

		// Lecture de tous les fichiers et creation des matrices
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			try
			{
				LISListeMatrices[iNbReelMatrice] = CParseur::PARLirefichier(ppcArgv[iBoucleI + 1]);
				LISListeMatrices[iNbReelMatrice].MABAfficherMatrice();
				iNbReelMatrice += 1;
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
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
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
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
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
			
			cout << "\n";
		}
		
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
				MAPResultatAddition.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}

			// Operation (M1-M2+M3-M4+...)
			cout << "Resultat de l'operation suivante (M1-M2+M3-M4+M5-M6+...) :\n";
			CMatricePlus<double> MAPResultatOperation(LISListeMatrices[0]);
			try
			{
				for (iBoucleI = 1; iBoucleI < iNbReelMatrice; iBoucleI++)
				{
					if (iBoucleI % 2 == 0) {
						MAPResultatOperation = MAPResultatOperation - LISListeMatrices[iBoucleI];
					}
					else {
						MAPResultatOperation = MAPResultatOperation + LISListeMatrices[iBoucleI];
					}
				}
				MAPResultatOperation.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
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
				MAPResultatProduit.MABAfficherMatrice();
				cout << "\n";
			}
			catch (CException& EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
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