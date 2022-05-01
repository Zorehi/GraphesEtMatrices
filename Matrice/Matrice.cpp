// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"



int main(int iArgc, char * ppcArgv[])
{
	if (iArgc > 1) {
		CListe<CMatricePlus<double>> LISListeMatrices(iArgc - 1);
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

		// Multiplication des matrices par un constante
		cout << "Résultat des multiplication des matrice par " << dC << " :" << "\n";
		for (iBoucleI = 0; iBoucleI < iArgc - 1; iBoucleI++)
		{
			MAPResultat = LISListeMatrices[iBoucleI] * dC;
			MAPResultat.MABAfficherMatrice();
		}

	}
	else {
		cout << "Veuillez donner le nom d'un fichier lors de l'appel du programme" << "\n";
		return 0;
	}
}