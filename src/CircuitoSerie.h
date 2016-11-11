/*
 * CircuitoSerie.h
 *
 *  Risoluzione del circuito in serie
 */

#ifndef CIRCUITOSERIE_H_
#define CIRCUITOSERIE_H_

#include <vector>

#include "Circuito.h"
#include "Complex.h"
#include "Componente.h"

using std::vector;

class CircuitoSerie: public Circuito
{
private:
	Complex Impedenza, Corrente;
	double sfasamento, potenziale;

public:
	//Costruttore con vettore di elementi serie
	CircuitoSerie( vector<Componente*>, double );

	//Metodi GET e di calcolo
	void calcolaImpedenzaCorrente( vector<Componente*> );

	Complex getImpedenza() const;
	Complex getCorrente() const;
	double getSfasamento() const;
	double getPotenziale() const;
};

#endif /* CIRCUITOSERIE_H_ */
