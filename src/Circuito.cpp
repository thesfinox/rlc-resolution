/*
 * Circuito.cpp
 *
 *  Implementazione della classe astratta
 *  circuito (possono essere sia in serie
 *  sia in parallelo)
 */

#include "Circuito.h"

#include <fstream>
#include <iostream>

#include "Complex.h"

using std::cout;
using std::endl;
using std::ofstream;

Complex Circuito::getImpedenza() const
{
	Complex q(0.0, 0.0);
	return q;
}

Complex Circuito::getCorrente() const
{
	Complex q(0.0, 0.0);
	return q;
}

double Circuito::getSfasamento() const
{
	return 0.0;
}

double Circuito::getPotenziale() const
{
	return 0.0;
}

void Circuito::stampaCircuito() const
{
	cout<<"\n////////////////////////////////////////////"<<endl;
	cout<<"   Risoluzione del circuito RLC"<<endl;
	cout<<"////////////////////////////////////////////"<<endl<<endl;

	cout<<"Impedenza: "<<endl;
	cout<<"Re(Z) = "<<this->getImpedenza().getParteReale()<<" \u2126"<<endl;
	cout<<"Im(Z) = "<<this->getImpedenza().getParteImmaginaria()<<" \u2126"<<endl;
	cout<<"   Z  = "<<this->getImpedenza().getModulo()<<" \u2126"<<endl<<endl;

	cout<<"Corrente: "<<endl;
	cout<<"Re(I) = "<<this->getCorrente().getParteReale()<<" A"<<endl;
	cout<<"Im(I) = "<<this->getCorrente().getParteImmaginaria()<<" A"<<endl;
	cout<<"   I  = "<<this->getCorrente().getModulo()<<" A"<<endl<<endl;

	cout<<"Sfasamento = "<<this->getSfasamento()<<" rad"<<endl<<endl;
}

bool Circuito::stampaFile( char* nomefile ) const
{
	ofstream output(nomefile);
	if(!output)
	{
		cout<<"\n///////////////////////////////////"<<endl<<endl;
		cout<<"\a   Errore nell'apertura del file"<<endl<<endl;
		cout<<"///////////////////////////////////"<<endl<<endl<<endl;

		return 1;
	}

	output<<"/////////////////////////////////////////////"<<endl;
	output<<"   Risoluzione del circuito RLC"<<endl;
	output<<"////////////////////////////////////////////"<<endl<<endl;

	output<<"Impedenza: "<<endl;
	output<<"Re(Z) = "<<this->getImpedenza().getParteReale()<<" \u2126"<<endl;
	output<<"Im(Z) = "<<this->getImpedenza().getParteImmaginaria()<<" \u2126"<<endl;
	output<<"   Z  = "<<this->getImpedenza().getModulo()<<" \u2126"<<endl<<endl;

	output<<"Corrente: "<<endl;
	output<<"Re(I) = "<<this->getCorrente().getParteReale()<<" A"<<endl;
	output<<"Im(I) = "<<this->getCorrente().getParteImmaginaria()<<" A"<<endl;
	output<<"   I  = "<<this->getCorrente().getModulo()<<" A"<<endl<<endl;

	output<<"Sfasamento = "<<this->getSfasamento()<<" rad"<<endl<<endl;

	output.close();

	return 0;
}
