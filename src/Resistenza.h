/*
 * Resistenza.h
 *
 *  Classe per la gestione di un componente di tipo
 *  resistivo all'interno del circuito.
 */

#ifndef RESISTENZA_H_
#define RESISTENZA_H_

#include "Complex.h"
#include "Componente.h"

using std::string;

class Resistenza: public Componente
{
private:
	Complex Impedenza;

public:
	//Costruttore vuoto e con il valore della resistenza
	Resistenza();
	Resistenza( double );

	//Metodo SET per la resistenza
	void setResistenza( double );

	//Funzioni GET
	Complex getImpedenza() const;
	string getNome() const;
};

#endif /* RESISTENZA_H_ */
