// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
//#include "CMInt.h"
//#include "CMDouble.h"
#include "CMatricePlus.h"



int main() {
    CMatricePlus<int> Matrice(3, 3);

    Matrice[0][0] = 1;
    Matrice[0][1] = 2;
    Matrice[0][2] = 3;
    Matrice[1][0] = 4;
    Matrice[1][1] = 5;
    Matrice[1][2] = 6;
    Matrice[2][0] = 7;
    Matrice[2][1] = 8;
    Matrice[2][2] = 9;
    Matrice.MABAfficherMatrice();
    Matrice.MAPTranspose().MABAfficherMatrice();

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