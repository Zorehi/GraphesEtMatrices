// Matrice.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CMATInt.h"


int main()
{
    //Creer une matrice d'entier 3x3 de 0
    CMATInt* MatriceIntTest = new CMATInt(3, 3);

    MatriceIntTest->MINTModifierElement(2, 2, 1);

    printf("Matrice 3x3 de 0 : (A)\n");
    MatriceIntTest->MINTAfficherMatrice();
    printf("\n");

    
    int piListeTest[6] = {1,2,3,4,5,6};
    //Creer une matrice d'entier 3x2 a partir de la liste piListeTest
    CMATInt* MatriceIntTest2 = new CMATInt(3, 2, piListeTest);
    MatriceIntTest2->MINTModifierElement(2, 1, 1);

    printf("Matrice 3x2 creer a partir d'une liste : (B)\n");
    MatriceIntTest2->MINTAfficherMatrice();
    printf("\n");


    //Transpose la matrice MatriceIntTest2
    CMATInt* MatriceIntTest2Transposee = MatriceIntTest2->MINTTranspose();

    printf("Transposee de la matrice Matrice 3x2 creer a partir d'une liste : (C)\n");
    MatriceIntTest2Transposee->MINTAfficherMatrice();
    printf("\n");


    //Multiplie la Matrice MatriceIntTest2 par 5
    CMATInt* MatriceIntTest2Multiplie = MatriceIntTest2->MINTMultiplierConstante(5);

    printf("(B)*5 : (D)\n");
    MatriceIntTest2Multiplie->MINTAfficherMatrice();
    printf("\n");

    //Divise la Matrice MatriceIntTest2 par 5
    CMATInt* MatriceIntTest2Divise = MatriceIntTest2->MINTDiviserConstante(5);

    printf("(B)/5 : (E)\n");
    MatriceIntTest2Divise->MINTAfficherMatrice();
    printf("\n");


    //Additionne les matrices MatriceIntTest2 et MatriceIntTest2Multiplie
    CMATInt* MatriceIntTestAjoutMatrice = MatriceIntTest2->MINTAdditionnerMatrice(MatriceIntTest2Multiplie);

    printf("(B) + (D) : (F)\n");
    MatriceIntTestAjoutMatrice->MINTAfficherMatrice();
    printf("\n");


    //Soustrait la matrice MatriceIntTest2Multiplie à la MatriceIntTest2
    CMATInt* MatriceIntTestSoustMatrice = MatriceIntTest2->MINTSoustraireMatrice(MatriceIntTest2Multiplie);

    printf("(B) - (D) : (G)\n");
    MatriceIntTestSoustMatrice->MINTAfficherMatrice();
    printf("\n");


    //Multiplie les matrices MatriceIntTest2 et MatriceIntTest2Transposee
    CMATInt* MatriceIntTestMutiplieMatrice = MatriceIntTest2->MINTMultiplierMatrice(MatriceIntTest2Transposee);

    printf("(B) * (C) : (H)\n");
    MatriceIntTestMutiplieMatrice->MINTAfficherMatrice();
    printf("\n");

}