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
#include "CListe.h"

int main(int iArgc, char* ppcArgv[])
{
    CListe<CException*> * d = new CListe<CException*>(10);
    delete (*d)[1];
    CException * objet = new CException(1, "coucou");
    (*d)[1] = objet;
    std::cout << (*d)[1]->EXCLireMsg();
    delete objet;
    delete d;
}