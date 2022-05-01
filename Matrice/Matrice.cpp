// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"

using namespace std;


int main(int iArgc, char * ppcArgv[])
{
	if (iArgc > 1) {
		CListe<CMatricePlus<double>> LISListeMatrices(iArgc - 1);
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
				(LISListeMatrices[iBoucleI] * dC).MABAfficherMatrice();
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
				(LISListeMatrices[iBoucleI] / dC).MABAfficherMatrice();
			}
			catch (CException EXCException)
			{
				cout << "ERREUR : " << EXCException.EXCLireVal() << "\n";
				cout << EXCException.EXCLireMsg() << "\n";
			}
		}

		// Addition de toutes les matrices
		cout << "Résultat de l'addition de toutes les matrices :\n";
		if (iArgc > 2) {
			CMatricePlus<double> MAPResultat(LISListeMatrices[0]);

			for (iBoucleI = 1; iBoucleI < iArgc - 1; iBoucleI++)
			{
				MAPResultat = MAPResultat + LISListeMatrices[iBoucleI];
			}
		}

	}
	else {
		cout << "Veuillez donner le nom d'un fichier lors de l'appel du programme" << "\n";
		return 0;
	}
}