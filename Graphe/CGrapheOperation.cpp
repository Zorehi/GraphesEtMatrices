#include "CGrapheOperation.h"

CGraphe CGrapheOperation::GROInverserArc(CGraphe GRAArg)
{
	CGraphe GrapheNew; //graphnew doit avoir tout les sommets de graag mais vides
	unsigned int uiNombreSommet = GRAArg.GRALireSommet().LISLireTaille();

	for (int iBoucle1 = 0; iBoucle1 < uiNombreSommet; iBoucle1++) { //pour chaque Sommet dans GRAArg
		unsigned int uiNombreArcPartant = GRAArg.GRALireSommet()[iBoucle1]->SOMLirePartant().LISLireTaille();

		for (int iBoucle2 = 0; iBoucle2 < uiNombreArcPartant; iBoucle2++) { // pour chaque arcPartant dans chaque sommet dans GRAArg
			// creation arc qui part de la destination où il arrivait dans GRAArg 
			int DestiNewDepart = GRAArg.GRALireSommet()[iBoucle1]->SOMLirePartant()[iBoucle2]->ARCLireDestination(); // numéro du sommet de l'arc
			CArc CurentArcNew(DestiNewDepart); //Arc ou l'on se situe 

			// et qui arrive au sommet d'ou il part dans GRAArg
			CurentArcNew.ARCModifierDestination(GRAArg.GRALireSommet()[iBoucle1]->SOMLireNumero());

			// ajout de l'arc au sommet d'ou il part 
			GrapheNew.GRALireSommet()[DestiNewDepart]->SOMAjouterPartant(&CurentArcNew);

		}
	}

	return GrapheNew;
}
