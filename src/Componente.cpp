/*
 * Componente.cpp
 *
 *  Implementazione della classe astratta
 *  dei componenti
 */

#include "Componente.h"

#include <iostream>

using std::cout;
using std::endl;

Complex Componente::getImpedenza() const
{
	Complex w( 0.0, 0.0 );
	return w;
}

void Componente::stampaComponente() const
{
	cout<<"Re(Z) = "<<this->getImpedenza().getParteReale()<<" \u2126"<<endl;
	cout<<"Im(Z) = "<<this->getImpedenza().getParteImmaginaria()<<" \u2126"<<endl;
	cout<<"   Z  = "<<this->getImpedenza().getModulo()<<" \u2126"<<endl;
}
