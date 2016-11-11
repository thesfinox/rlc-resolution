/*
 * Induttanza.h
 *
 *  Classe per la gestione di un componente di tipo
 *  induttivo all'interno del circuito.
 */

#ifndef INDUTTANZA_H_
#define INDUTTANZA_H_

#include "Complex.h"
#include "Componente.h"

using std::string;

class Induttanza: public Componente
{
private:
	Complex Impedenza;
	double frequenza;

public:
	//Costruttore vuoto e con il valore della resistenza
	Induttanza();
	Induttanza( double, double );

	//Metodo SET per la resistenza
	void setInduttanza( double ); //valore
	void setFrequenza( double ); //frequenza operativa

	//Funzioni GET
	Complex getImpedenza() const;
	double getFrequenza() const;
	string getNome() const;
};

#endif /* INDUTTANZA_H_ */
