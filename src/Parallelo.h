/*
 * Parallelo.h
 *
 *  La classe raggruppa in un unico elemento
 *  più oggetti di tipo serie.
 */

#ifndef PARALLELO_H_
#define PARALLELO_H_

#include "Complex.h"
#include "Componente.h"

using std::string;
#include <vector>
using std::vector;

class Parallelo: public Componente
{
private:
	Complex Impedenza;

	//metodo di inizializzazione
	void init( vector<Componente*> );

public:
	//Costruttore con gli elementi da mettere in parallelo
	Parallelo( vector<Componente*> );

	//Metodi GET
	Complex getImpedenza() const;
	string getNome() const;
};

#endif /* PARALLELO_H_ */
