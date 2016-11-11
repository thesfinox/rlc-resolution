/*
 * Resistenza.cpp
 *
 *  Implementazione della classe per
 *  componente resistivo
 */

#include "Resistenza.h"

#include <string>

Resistenza::Resistenza() : Impedenza(0.0, 0.0) {}

Resistenza::Resistenza( double Resistenza ) : Impedenza(Resistenza, 0.0) {}

void Resistenza::setResistenza( double Resistenza )
{
	Complex w( Resistenza, 0.0 );
	this->Impedenza = w;
}

Complex Resistenza::getImpedenza() const
{
	return Impedenza;
}

string Resistenza::getNome() const
{
	return "Resistenza";
}
