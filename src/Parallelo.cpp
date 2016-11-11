/*
 * Parallelo.cpp
 *
 *  Implementazione della classe
 *  per elementi in parallelo
 */

#include "Parallelo.h"

#include <iterator>
#include <string>

using std::vector;

Parallelo::Parallelo( vector<Componente*> elementi ) : Impedenza(0.0, 0.0)
{
	init(elementi);
}

void Parallelo::init( vector<Componente*> elementi )
{
	Complex buffer(0.0, 0.0);

	vector<Componente*>::const_iterator iter;
	for(iter = elementi.begin(); iter != elementi.end(); iter++)
		buffer = buffer + (*iter)->getImpedenza().inverso();

	Impedenza = buffer.inverso();
}

Complex Parallelo::getImpedenza() const
{
	return Impedenza;
}

string Parallelo::getNome() const
{
	return "Parallelo di elementi";
}
