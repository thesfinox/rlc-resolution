/*
 * Condensatore.cpp
 *
 *  Implementazione della classe per
 *  componente capacitivo
 */

#include "Condensatore.h"

#include <string>

Condensatore::Condensatore() : Impedenza(0.0, 0.0)
{
	setFrequenza(0.0);
}

Condensatore::Condensatore( double Capacita, double Frequenza ) : Impedenza(0.0, -1.0/(2.0*PI*Frequenza*Capacita))
{
	setFrequenza( Frequenza );
}

void Condensatore::setCondensatore( double Capacita )
{
	Complex w(0.0, -1.0/(2.0*PI*this->getFrequenza()*Capacita));
	this->Impedenza = w;
}

void Condensatore::setFrequenza( double Frequenza )
{
	this->frequenza = Frequenza;
}

Complex Condensatore::getImpedenza() const
{
	return Impedenza;
}

double Condensatore::getFrequenza() const
{
	return frequenza;
}

string Condensatore::getNome() const
{
	return "Condensatore";
}
