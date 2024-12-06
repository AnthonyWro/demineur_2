//
//  position.h
//
#include<iostream>
#include<cassert>

#ifndef POSITION_H
#define POSITION_H


class Position
{
	int lign, coln;

public:
		Position(); 
		Position(int, int);

		int ligne();
		int colonne();

		Position set(int,int);
		
		

		void lireValiderEntier(istream& es_entree, int& s_entier);
};
#endif /* Position_h */
