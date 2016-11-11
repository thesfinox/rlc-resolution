/*
 * Circuito.h
 *
 *  Classe virtuale per la risoluzione dei circuiti
 *  che possono essere sia in serie sia in parallelo.
 */

#ifndef CIRCUITO_H_
#define CIRCUITO_H_

#include <vector>

#include "Componente.h"

using std::vector;

class Circuito
{
public:
	//Metodi virtuali per la risoluzione dei circuiti
	virtual void calcolaImpedenzaCorrente( vector<Componente*> ) = 0;

	virtual Complex getImpedenza() const;
	virtual Complex getCorrente() const;
	virtual double getSfasamento() const;
	virtual double getPotenziale() const;

	//Metodi di stampa
	//Stampa a video o su file
	virtual void stampaCircuito() const;
	virtual bool stampaFile( char* ) const;
};

#endif /* CIRCUITO_H_ */
