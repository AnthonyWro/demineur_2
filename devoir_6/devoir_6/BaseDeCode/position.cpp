#include "position.h"

#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

Position::Position() {
    lign = 0;  // Valeur par défaut pour la ligne
    coln = 0;  // Valeur par défaut pour la colonne
}

Position::Position(int ligne, int colonne) {
    lign = ligne;
    coln = colonne;
}

int Position::ligne() const { return lign; }
int Position::colonne() const { return coln; }

ostream& operator<<(ostream& out, const Position& position) {
    out << "(" << position.ligne() << ", " << position.colonne() << ")";
    return out;
}

istream& operator>>(istream& in, Position& position) {
    void lireValiderEntier(istream&, int&);
    cout << "Entrez la ligne (-1 pour quitter): ";
    int ligne;
    lireValiderEntier(in, ligne);

    if (ligne == -1) {
        position = Position(ligne, position.colonne());
        return in;
    }

    cout << "Entrez la colonne: ";
    int colonne;
    lireValiderEntier(in, colonne);

    position = Position(ligne, colonne);

    return in;
}

void lireValiderEntier(istream& es_entree, int& s_entier)
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
