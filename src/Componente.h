/*
 * Componente.h
 *
 *  Classe astratta per la gestione della
 *  componentistica del circuito. Contiene i
 *  metodi virtuali da reimplementare nelle
 *  classi.
 */

#ifndef COMPONENTE_H_
#define COMPONENTE_H_

#include "Complex.h"
#include <string>
using std::string;

const double PI = 3.141592653589793;

class Componente
{

public:
	//Funzioni di tipo virtuale, utilizzabili da più componenti
	virtual Complex getImpedenza() const;
	virtual void stampaComponente() const;
	virtual string getNome() const = 0;
};

#endif /* COMPONENTE_H_ */
