/*
 * CircuitoParallelo.cpp
 *
 *  Implementazione della classe per la risoluzione
 *  di circuiti in parallelo
 */

#include "CircuitoParallelo.h"

#include <iterator>

using std::vector;

CircuitoParallelo::CircuitoParallelo( vector<Componente*> elementi, double potenziale ) : Impedenza(0.0, 0.0), Corrente (0.0, 0.0)
{
	this->sfasamento = 0.0;
	this->potenziale = potenziale;

	calcolaImpedenzaCorrente(elementi);
}

void CircuitoParallelo::calcolaImpedenzaCorrente( vector<Componente*> elementi )
{
	Complex buffer(0.0, 0.0);

	vector<Componente*>::const_iterator iter;
	for(iter = elementi.begin(); iter != elementi.end(); iter++)
		buffer = buffer + (*iter)->getImpedenza().inverso();

	Impedenza = buffer.inverso();
	Corrente = this->getPotenziale()*Impedenza.inverso();

	sfasamento = Corrente.getParteImmaginaria() / Corrente.getParteReale();
}

Complex CircuitoParallelo::getImpedenza() const
{
	return Impedenza;
}

Complex CircuitoParallelo::getCorrente() const
{
	return Corrente;
}

double CircuitoParallelo::getSfasamento() const
{
	return sfasamento;
}

double CircuitoParallelo::getPotenziale() const
{
	return potenziale;
}
