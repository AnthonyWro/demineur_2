#include "carte.h"
#include "utilitaires.h"

#include <iomanip>
#include <cassert>
#include <stdio.h>

using namespace std;

Compteur Carte::getNbMinesAdjacentes(Position e_pos)
{
    size_t boardWidth = nbColonnes();
    size_t boardHeight = nbLignes();

    int ligne = e_pos.ligne();
    int colonne = e_pos.colonne();

    Case& caseAPosition = m_cases[ligne][colonne];

    // Vérification des 8 directions autour de la position
    if (estDansCarte({ ligne - 1, colonne }) && m_cases[ligne - 1][colonne].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne + 1, colonne }) && m_cases[ligne + 1][colonne].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne, colonne - 1 }) && m_cases[ligne][colonne - 1].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne, colonne + 1 }) && m_cases[ligne][colonne + 1].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne - 1, colonne - 1 }) && m_cases[ligne - 1][colonne - 1].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne + 1, colonne - 1 }) && m_cases[ligne + 1][colonne - 1].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne - 1, colonne + 1 }) && m_cases[ligne - 1][colonne + 1].estUneMine()) ++caseAPosition;
    if (estDansCarte({ ligne + 1, colonne + 1 }) && m_cases[ligne + 1][colonne + 1].estUneMine()) ++caseAPosition;

    return caseAPosition.nbMinesAdj();
}

bool Carte::essaieCase(Position e_pos)
{
    int ligne = e_pos.ligne();
    int colonne = e_pos.colonne();
    Case& caseAPosition = m_cases[ligne][colonne];

    if (caseAPosition.estOuverte()) { return true; }

    if (caseAPosition.estUneMine()) {
        caseAPosition.ouvre();
        return false;
    }

    caseAPosition.ouvre();
    if (caseAPosition.nbMinesAdj() > 0) {
        return true;
    }

    // Ouverture récursive des cases adjacentes
    if (estDansCarte({ ligne - 1, colonne })) essaieCase({ ligne - 1, colonne });
    if (estDansCarte({ ligne + 1, colonne })) essaieCase({ ligne + 1, colonne });
    if (estDansCarte({ ligne, colonne - 1 })) essaieCase({ ligne, colonne - 1 });
    if (estDansCarte({ ligne, colonne + 1 })) essaieCase({ ligne, colonne + 1 });
    if (estDansCarte({ ligne - 1, colonne - 1 })) essaieCase({ ligne - 1, colonne - 1 });
    if (estDansCarte({ ligne + 1, colonne - 1 })) essaieCase({ ligne + 1, colonne - 1 });
    if (estDansCarte({ ligne - 1, colonne + 1 })) essaieCase({ ligne - 1, colonne + 1 });
    if (estDansCarte({ ligne + 1, colonne + 1 })) essaieCase({ ligne + 1, colonne + 1 });

    return true;
}

void Carte::compteMinesAdjParCase(Position e_pos)
{
    for (size_t ligne = 0; ligne < m_cases.size(); ligne++)
    {
        for (size_t colonne = 0; colonne < m_cases[0].size(); colonne++)
        {
            if (!m_cases[ligne][colonne].estUneMine()) {
                getNbMinesAdjacentes(Position{ (int)ligne, (int)colonne });
            }
        }
    }
}
