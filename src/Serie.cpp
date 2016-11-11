/*
 * Serie.cpp
 *
 *  Implementazione della classe per
 *  il calcolo delle impedenze in serie.
 */

#include "Serie.h"

#include <iostream>
#include <iterator>

#include "Condensatore.h"
#include "Induttanza.h"
#include "Resistenza.h"

using std::string;
#include <vector>
using std::vector;

Serie::Serie( vector<double> valori, Tipologia tipo, double frequenza ) : Impedenza(0.0, 0.0)
{
	init(valori,tipo,frequenza);
}

Serie::~Serie()
{
	vector<Componente*>::const_iterator iter;
	for(iter = elementi.begin(); iter != elementi.end(); iter++)
		delete (*iter);
}

void Serie::init( vector<double> valori, Tipologia& tipo, double& frequenza )
{
	vector<double>::iterator iter;

	switch(tipo)
	{
		case 1:
		{
			for(iter = valori.begin(); iter != valori.end(); iter++)
				 elementi.push_back( new Resistenza( (*iter) ) );
			break;
		}

		case 2:
		{
			for(iter = valori.begin(); iter != valori.end(); iter++)
				elementi.push_back( new Condensatore( (*iter), frequenza ) );
			break;
		}

		case 3:
		{
			for(iter = valori.begin(); iter != valori.end(); iter++)
				elementi.push_back( new Induttanza( (*iter), frequenza ) );
			break;
		}

		default:
		{
			std::cout<<"\n\aErrore nella tipologia di elemento: inserire il tipo corretto"<<std::endl;
			break;
		}
	}

	vector<Componente*>::const_iterator span;
	for(span = elementi.begin(); span != elementi.end(); span++)
		Impedenza = Impedenza + (*span)->getImpedenza();
}

Complex Serie::getImpedenza() const
{
	return Impedenza;
}

string Serie::getNome() const
{
	return "Serie di elementi";
}

int Serie::size() const
{
	return elementi.size();
}

vector<Componente*>::const_iterator Serie::begin() const
{
	return elementi.begin();
}

vector<Componente*>::const_iterator Serie::end() const
{
	return elementi.end();
}
