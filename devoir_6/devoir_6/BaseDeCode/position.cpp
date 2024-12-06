//
//  position.cpp
//

// description : fonction utilitaire qui permet de lire et valider si c'est bien un entier qui est lu
// param[ES] : flux d'entree sur lequel on lit l'entier
// param[S] : entier lu
// pre : le flux est existant et ouvert (diff. de NULL)
// post : lit une valeur dans le flux jusqu'à ce qu'elle soit un entier

#include"carte.h"
#include"position.h"
#include<iostream>
#include<cassert>

void lireValiderEntier(istream& es_entree, int &s_entier)
{
    assert(es_entree);
    
    while (!(es_entree >> s_entier))
    {
        // Afficher un message d'erreur et redemander le numero de ligne
        cout << "Erreur! Vous devez entrer une nombre entier! " << endl << "Entrez la ligne : ";
        // Vider le tampon de lecture
        es_entree.clear();
        // Ignorer tous les caracteres deja entres
        es_entree.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    assert(es_entree);
}


Position::Position(int x, int y)
{
    coln = y;
    lign = x;
}
Position::Position()
{
    coln = 0;
    lign = 0;
}




int Position::ligne()
{
    return lign;
}
int Position::colonne()
{
    return coln;
}

 Position Position::set(int x, int y)
{
    lign = lign + x;
    coln = coln + y;
} 
 
