/*
 * Induttanza.cpp
 *
 *  Implementazione della classe per
 *  componente induttivo
 */

#include "Induttanza.h"

#include <string>

Induttanza::Induttanza() : Impedenza(0.0, 0.0)
{
	setFrequenza(0.0);
}

Induttanza::Induttanza( double Induttanza, double Frequenza ) : Impedenza(0.0, 2.0*PI*Frequenza*Induttanza)
{
	setFrequenza( Frequenza );
}

void Induttanza::setInduttanza( double Induttanza )
{
	Complex w(0.0, 2.0*PI*this->getFrequenza()*Induttanza);
	this->Impedenza = w;
}

void Induttanza::setFrequenza( double Frequenza )
{
	this->frequenza = Frequenza;
}

Complex Induttanza::getImpedenza() const
{
	return Impedenza;
}

double Induttanza::getFrequenza() const
{
	return frequenza;
}

string Induttanza::getNome() const
{
	return "Induttanza";
}
