/*
 * CircuitoParallelo.h
 *
 *  Risoluzione di circuiti
 *  in parallelo
 */

#ifndef CIRCUITOPARALLELO_H_
#define CIRCUITOPARALLELO_H_

#include <vector>

#include "Circuito.h"
#include "Complex.h"
#include "Componente.h"

using std::vector;

class CircuitoParallelo: public Circuito
{
private:
	Complex Impedenza, Corrente;
	double sfasamento, potenziale;

public:
	//Costruttore con vettore di elementi serie
	CircuitoParallelo( vector<Componente*>, double );

	//Metodi GET e di calcolo
	void calcolaImpedenzaCorrente( vector<Componente*> );

	Complex getImpedenza() const;
	Complex getCorrente() const;
	double getSfasamento() const;
	double getPotenziale() const;
};

#endif /* CIRCUITOPARALLELO_H_ */
