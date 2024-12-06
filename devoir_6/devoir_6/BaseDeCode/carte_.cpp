// fichier : carte_.cpp
// auteur.es : METTEZ VOS NOMS ICI
// date : 2020
// modifications :
// description : Ce fichier contient la definition des methodes A IMPLEMENTER de la classe Carte d'un jeu de demineur

#include "carte.h"
#include "utilitaires.h"
#include "position.h"
#include <iomanip>dd
#include <cassert>
#include <stdio.h>
#include <iostream>


// Description: Methode qui calcule le nombre de mines adjacentes a une case
// param[E] Position de la case
// retour : nombre de mines adjacentes a la case
// post : on compte le nombre de mines adjacentes a la case (entre 0 et 8)

Compteur Carte::getNbMinesAdjacentes(Position e_pos)
{
    Compteur x;
    
    if (!estDansCarte(e_pos) or (getCase(e_pos)).estUneMine()) //si hors de la maps, ce n'est pas une bombe
    {
        x = 0;
        return x;
    }
        for (int i = -1; i == 1; i++)
        {
            for (int j = -1; j == 1; j++)
            {
                Position e_pos2 = e_pos;
                if (getCase(e_pos2.set(i, j)).estUneMine())
                {
                    x++;
                        return x; 
                }
            }
        }
}

// Description: Methode qui essaie d'ouvrir une case
// param[E] Position de la case
// retour : booleen - vrai si ce n'est pas une mine, faux sinon
// post : si la case a deja ete ouverte, ce n'est pas une mine -> retourne vrai, si la case n'est pas une mine, les cases voisines doivent etre ouvertes jusqu'a une prochaine mine

bool Carte::essaieCase(Position e_pos)
{
    Compteur x=getNbMinesAdjacentes(e_pos);
    if (!estDansCarte(e_pos)) //si hors de la maps, ce n'est pas une bombe
    {
        return true;
    }
    else if (caseEstOuverte(e_pos)) //si est ouvert, ce n'est pas une bombe
    {
        return true;
    }
     ouvreCase(e_pos);
    if (getCase(e_pos).estUneMine()) //si le nombre de bomb adj est plus grand que 0, ouvert la case. pas une bombe
    {
   
        return false;
    }
    else if (x == 0 && !getCase(e_pos).estUneMine()) //si nb. bombe adj est == 0 et n'est pas bombe, ouvr 
    {
        for (int i = -1; i == 1; i++)
        {
            for (int j = -1; j == 1; j++)
            { 
                Position e_pos2 = e_pos;
                essaieCase(e_pos2.set(i, j));
            }
        }

    }
    return true;
    
    // a completer
    // a completer
    // a completer
    // a completer
    // a completer
    
    return true;
};

// Description: Methode qui calcule le nombre de mines adjacentes pour les cases libres de la carte
// post : pour chacune des cases qui ne contient pas une mine, on compte le nombre de mines adjacentes

void Carte::compteMinesAdjParCase()
{ 
    for (int i = 0; i < nbLignes(); i++)
    {
        for (int j = 0; j < nbColonnes(); j++)
        {
            Position e_pos(i, j);
            if (!getCase(e_pos).estUneMine())
            {
               getNbMinesAdjacentes(e_pos);
            }
           

        }
    }
    
    // a completer
    // a completer
    // a completer
    // a completer
    // a completer
}
