/*
 * CircuitoSerie.cpp
 *
 *  Risoluzione del circuito in serie
 */

#include "CircuitoSerie.h"

#include <iterator>

using std::vector;

CircuitoSerie::CircuitoSerie( vector<Componente*> elementi, double potenziale ) : Impedenza(0.0, 0.0), Corrente (0.0, 0.0)
{
	this->sfasamento = 0.0;
	this->potenziale = potenziale;

	calcolaImpedenzaCorrente(elementi);
}

void CircuitoSerie::calcolaImpedenzaCorrente( vector<Componente*> elementi )
{
	vector<Componente*>::const_iterator iter;
	for(iter = elementi.begin(); iter != elementi.end(); iter++)
		Impedenza = Impedenza + (*iter)->getImpedenza();

	Corrente = this->getPotenziale()*Impedenza.inverso();

	sfasamento = Corrente.getParteImmaginaria() / Corrente.getParteReale();
}

Complex CircuitoSerie::getImpedenza() const
{
	return Impedenza;
}

Complex CircuitoSerie::getCorrente() const
{
	return Corrente;
}

double CircuitoSerie::getSfasamento() const
{
	return sfasamento;
}

double CircuitoSerie::getPotenziale() const
{
	return potenziale;
}
