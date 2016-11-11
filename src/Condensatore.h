/*
 * Condensatore.h
 *
 *  Classe per la gestione di un componente di tipo
 *  capacitivo all'interno del circuito.
 */

#ifndef CONDENSATORE_H_
#define CONDENSATORE_H_

#include "Complex.h"
#include "Componente.h"

using std::string;

class Condensatore: public Componente
{
private:
	Complex Impedenza;
	double frequenza;

public:
	//Costruttore vuoto e con il valore della resistenza
	Condensatore();
	Condensatore( double, double );

	//Metodo SET per la resistenza
	void setCondensatore( double ); //valore
	void setFrequenza( double ); //frequenza operativa

	//Funzioni GET
	Complex getImpedenza() const;
	double getFrequenza() const;
	string getNome() const;
};

#endif /* CONDENSATORE_H_ */
