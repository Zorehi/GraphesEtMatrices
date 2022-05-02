// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"

using namespace std;


int main(int iArgc, char * ppcArgv[])
{
	//Test du parseur
	CParseur* parseur = new CParseur("test_parseur1.txt");
	try {
		CMatricePlus<double> matriceFichier = parseur->PARLirefichier();
		matriceFichier.MABAfficherMatrice();
	}
	catch (CException& EXCException) {
		cout << EXCException.EXCLireMsg();
	}

	if (iArgc > 1) {
		// Quand j'utilise notre liste ça ne marche pas je comprend pas  ¯\_(ツ)_/¯ 
		//CListe<CMatricePlus<double>> LISListeMatrices(iArgc - 1);
		CMatricePlus<double> * LISListeMatrices = new CMatricePlus<double>[iArgc - 1];
		CMatricePlus<double> MAPResultat;
		int iBoucleI;
		double dC;

		// Lecture de tous les fichiers et creation des matrices
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			try
			{
				//LISListeMatrices[iBoucleI] = CParseur::PARLirefichier(ppcArgv[iBoucleI + 1]);
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
		}

		cout << "Veuillez saisir une valeur de C : ";
		cin >> dC;
		cout << "\n";

		// Multiplication des matrices par une constante
		cout << "Résultat de la multiplication des matrices par " << dC << " :\n";
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			try
			{
				MAPResultat = LISListeMatrices[iBoucleI] * dC;
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
		}

		// Division des matrices par une constante
		cout << "Résultat de la division des matrices par " << dC << " :\n";
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			try
			{
				MAPResultat = LISListeMatrices[iBoucleI] / dC;
				MAPResultat.MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
		}
		
		if (iArgc > 2) {
			// Addition de toutes les matrices
			cout << "Résultat de l'addition de toutes les matrices :\n";
			CMatricePlus<double> MAPResultatAddition(LISListeMatrices[0]);

			try
			{
				for (iBoucleI = 1; iBoucleI < iArgc - 1; iBoucleI++)
				{
					MAPResultatAddition = MAPResultatAddition + LISListeMatrices[iBoucleI];
				}
				MAPResultatAddition.MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}

			// Operation (M1-M2+M3-M4+...)
			cout << "Résultat de l'opération suivante (M1-M2+M3-M4+M5-M6+...) :\n";
			CMatricePlus<double> MAPResultatOperation(LISListeMatrices[0]);
			try
			{
				for (iBoucleI = 1; iBoucleI < iArgc - 1; iBoucleI++)
				{
					if (iBoucleI % 2 == 0) {
						MAPResultatOperation = MAPResultatOperation - LISListeMatrices[iBoucleI];
					}
					else {
						MAPResultatOperation = MAPResultatOperation + LISListeMatrices[iBoucleI];
					}
				}
				MAPResultatOperation.MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}

			// Multiplication des matrices entre elles
			cout << "Résultat de l'opération suivante (M1-M2+M3-M4+M5-M6+...) :\n";
			CMatricePlus<double> MAPResultatProduit(LISListeMatrices[0]);
			try
			{
				for (iBoucleI = 1; iBoucleI < iArgc - 1; iBoucleI++)
				{
					MAPResultatProduit = MAPResultatProduit * LISListeMatrices[iBoucleI];
				}
				MAPResultatProduit.MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
		}
		else {
			cout << "Pour réaliser les opération telles que : \n\tLa somme de toutes les matrices\n\tLa multplication de toutes les matrices entre elles\n";
			cout << "Il faut donner plus de 1 fichier lors du lancement du programme !";
		}
	}
	else {
		cout << "Veuillez donner le nom d'un fichier lors de l'appel du programme" << "\n";
		return 0;
	}
}