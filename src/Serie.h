/*
 * Serie.h
 *
 *  Raggruppa elementi in serie tra loro
 *  e sostituisce le loro impedenze con
 *  un'unica impedenza totale.
 */

#ifndef SERIE_H_
#define SERIE_H_

#include "Complex.h"
#include "Componente.h"

using std::string;
#include <vector>
using std::vector;

enum Tipologia { RESISTENZA = 1, CONDENSATORE = 2, INDUTTANZA = 3, resistenza = 1, condensatore = 2, induttanza = 3, R = 1, r = 1, C = 2, c = 2, L = 3, l = 3 };

class Serie: public Componente
{
private:
	vector<Componente*> elementi;
	Complex Impedenza;

	//Metodo di inizializzazione
	void init( vector<double>, Tipologia&, double& );

public:
	//Costruttore con i valori della serie di elementi (valori, tipo, frequenza)
	Serie( vector<double>, Tipologia, double );
	~Serie();

	//Metodi GET
	Complex getImpedenza() const;
	string getNome() const;

	//Gestione vettore
	int size() const;
	vector<Componente*>::const_iterator begin() const;
	vector<Componente*>::const_iterator end() const;
};

#endif /* SERIE_H_ */
