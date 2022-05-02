// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CMatricePlus.h"
#include "CParseur.h"
#include "CMatriceBase.h"

using namespace std;


int main(int iArgc, char * ppcArgv[])
{
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

    CMatricePlus<double> MatATransposee = Matrice.MAPTranspose();
    printf("\nMatF = transpose(MatA)\n");    
    MatATransposee.MABAfficherMatrice();



    //Test du parseur
    CParseur* parseur = new CParseur("test_parseur1.txt");
    try {
        CMatricePlus<double> matriceFichier = parseur->PARLirefichier();
        matriceFichier.MABAfficherMatrice();
    }
    catch (CException& EXCException) {
        cout << EXCException.EXCLireMsg();
    }
    

    /*
    CMatricePlus<int> Matrice2(3, 3);

    Matrice[0][0] = 1;
    Matrice[0][1] = 2;
    Matrice[0][2] = 3;
    Matrice[1][0] = 4;
    Matrice[1][1] = 5;
    Matrice[1][2] = 6;
    Matrice[2][0] = 7;
    Matrice[2][1] = 8;
    Matrice[2][2] = 9;

    printf("\nMatA = \n");
    Matrice.MABAfficherMatrice();

    CMatricePlus<double> MatTestMulCons = Matrice2 * 5;
    printf("\nMatB = MatA * 5.0\n");
    MatTestMulCons.MABAfficherMatrice();

    CMatricePlus<double> MatTestDivCons = Matrice2 / 5;
    printf("\nMatC = MatA / 5.0\n");
    MatTestDivCons.MABAfficherMatrice();

    CMatricePlus<double> MatTestAPlusB = Matrice2 + MatTestMulCons;
    printf("\nMatD = MatA / MatB\n");
    MatTestAPlusB.MABAfficherMatrice();

    CMatricePlus<double> MatTestAMultB = Matrice * MatTestMulCons;
    printf("\nMatE = MatA / MatB\n");
    MatTestAMultB.MABAfficherMatrice();

    CMatricePlus<double> MatATransposee = Matrice.MAPTranspose();
    printf("\nMatF = transpose(MatA)\n");
    MatATransposee.MABAfficherMatrice();
    */
}


/*
int test()
{
    //Creer une matrice d'entier 3x3 de 0
    CMInt* MatriceIntTest = new CMInt(3, 3);

    MatriceIntTest->MINTModifierElement(2, 2, 1);

    printf("Matrice 3x3 de 0 : (A)\n");
    MatriceIntTest->MINTAfficherMatrice();
    printf("\n");

    
    int piListeTest[6] = {1,2,3,4,5,6};
    //Creer une matrice d'entier 3x2 a partir de la liste piListeTest
    CMInt* MatriceIntTest2 = new CMInt(3, 2, piListeTest);
    MatriceIntTest2->MINTModifierElement(2, 1, 1);

    printf("Matrice 3x2 creer a partir d'une liste : (B)\n");
    MatriceIntTest2->MINTAfficherMatrice();
    printf("\n");


    //Transpose la matrice MatriceIntTest2
    CMInt* MatriceIntTest2Transposee = MatriceIntTest2->MINTTranspose();

    printf("Transposee de la matrice Matrice 3x2 creer a partir d'une liste : (C)\n");
    MatriceIntTest2Transposee->MINTAfficherMatrice();
    printf("\n");


    //Multiplie la Matrice MatriceIntTest2 par 5
    CMInt* MatriceIntTest2Multiplie = MatriceIntTest2->MINTMultiplierConstante(5);

    printf("(B)*5 : (D)\n");
    MatriceIntTest2Multiplie->MINTAfficherMatrice();
    printf("\n");

    //Divise la Matrice MatriceIntTest2 par 5
    CMInt* MatriceIntTest2Divise = MatriceIntTest2->MINTDiviserConstante(5);

    printf("(B)/5 : (E)\n");
    MatriceIntTest2Divise->MINTAfficherMatrice();
    printf("\n");


    //Additionne les matrices MatriceIntTest2 et MatriceIntTest2Multiplie
    CMInt* MatriceIntTestAjoutMatrice = MatriceIntTest2->MINTAdditionnerMatrice(MatriceIntTest2Multiplie);

    printf("(B) + (D) : (F)\n");
    MatriceIntTestAjoutMatrice->MINTAfficherMatrice();
    printf("\n");


    //Soustrait la matrice MatriceIntTest2Multiplie à la MatriceIntTest2
    CMInt* MatriceIntTestSoustMatrice = MatriceIntTest2->MINTSoustraireMatrice(MatriceIntTest2Multiplie);

    printf("(B) - (D) : (G)\n");
    MatriceIntTestSoustMatrice->MINTAfficherMatrice();
    printf("\n");


    //Multiplie les matrices MatriceIntTest2 et MatriceIntTest2Transposee
    CMInt* MatriceIntTestMutiplieMatrice = MatriceIntTest2->MINTMultiplierMatrice(MatriceIntTest2Transposee);

    printf("(B) * (C) : (H)\n");
    MatriceIntTestMutiplieMatrice->MINTAfficherMatrice();
    printf("\n");


    ///////////////////////////////////////////// Parti Double

    //Creer une matrice d'entier 3x3 de 0
    CMDouble* MatriceDoubleTest = new CMDouble(3, 3);

    MatriceDoubleTest->MDOModifierElement(2, 2, 1);

    printf("Matrice 3x3 de 0 : (A)\n");
    MatriceDoubleTest->MDOAfficherMatrice();
    printf("\n");


    double pdListeTest[6] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
    //Creer une matrice d'entier 3x2 a partir de la liste piListeTest
    CMDouble* MatriceDoubleTest2 = new CMDouble(3, 2, pdListeTest);
    MatriceDoubleTest2->MDOModifierElement(2, 1, 1);

    printf("Matrice 3x2 creer a partir d'une liste : (B)\n");
    MatriceDoubleTest2->MDOAfficherMatrice();
    printf("\n");


    //Transpose la matrice MatriceDoubleTest2
    CMDouble* MatriceDoubleTest2Transposee = MatriceDoubleTest2->MDOTranspose();

    printf("Transposee de la matrice Matrice 3x2 creer a partir d'une liste : (C)\n");
    MatriceDoubleTest2Transposee->MDOAfficherMatrice();
    printf("\n");


    //Multiplie la Matrice MatriceDoubleTest2 par 5
    CMDouble* MatriceDoubleTest2Multiplie = MatriceDoubleTest2->MDOMultiplierConstante(5);

    printf("(B)*5 : (D)\n");
    MatriceDoubleTest2Multiplie->MDOAfficherMatrice();
    printf("\n");

    //Divise la Matrice MatriceDoubleTest2 par 5
    CMDouble* MatriceDoubleTest2Divise = MatriceDoubleTest2->MDODiviserConstante(5);

    printf("(B)/5 : (E)\n");
    MatriceDoubleTest2Divise->MDOAfficherMatrice();
    printf("\n");


    //Additionne les matrices MatriceDoubleTest2 et MatriceDoubleTest2Multiplie
    CMDouble* MatriceDoubleTestAjoutMatrice = MatriceDoubleTest2->MDOAdditionnerMatrice(MatriceDoubleTest2Multiplie);

    printf("(B) + (D) : (F)\n");
    MatriceDoubleTestAjoutMatrice->MDOAfficherMatrice();
    printf("\n");


    //Soustrait la matrice MatriceDoubleTest2Multiplie à la MatriceDoubleTest2
    CMDouble* MatriceDoubleTestSoustMatrice = MatriceDoubleTest2->MDOSoustraireMatrice(MatriceDoubleTest2Multiplie);

    printf("(B) - (D) : (G)\n");
    MatriceDoubleTestSoustMatrice->MDOAfficherMatrice();
    printf("\n");


    //Multiplie les matrices MatriceDoubleTest2 et MatriceDoubleTest2Transposee
    CMDouble* MatriceDoubleTestMutiplieMatrice = MatriceDoubleTest2->MDOMultiplierMatrice(MatriceDoubleTest2Transposee);

    printf("(B) * (C) : (H)\n");
    MatriceDoubleTestMutiplieMatrice->MDOAfficherMatrice();
    printf("\n");

    system("pause");

    return 0;

}

*/
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
			cout << "Ils faut donner plus de 1 fichier lors du lancement du programme !";
		}
	}
	else {
		cout << "Veuillez donner le nom d'un fichier lors de l'appel du programme" << "\n";
		return 0;
	}
}