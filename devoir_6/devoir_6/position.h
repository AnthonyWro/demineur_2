#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position
{
    int lign;  // Ligne de la position
    int coln;  // Colonne de la position

public:
    // Constructeurs
    Position();  
    Position(int, int);

    // Getters
    int ligne() const;
    int colonne() const;

    // Surcharge des opérateurs
    friend std::ostream& operator<<(std::ostream&, const Position&);
    friend std::istream& operator>>(std::istream&, Position&);
};

#endif /* POSITION_H */
