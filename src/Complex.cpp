/*
 * Complex.cpp
 *
 *  Implementazione della classe Complex per la
 *  gestione dei numeri complessi.
 */

#include "Complex.h"

#include <cmath>

Complex::Complex()
{
	setParteReale(0.0);
	setParteImmaginaria(0.0);
}

Complex::Complex( double ParteReale, double ParteImmaginaria )
{
	setParteReale(ParteReale);
	setParteImmaginaria(ParteImmaginaria);
}

void Complex::setParteReale( double ParteReale )
{
	this->ParteReale = ParteReale;
}


void Complex::setParteImmaginaria( double ParteImmaginaria )
{
	this->ParteImmaginaria = ParteImmaginaria;
}

double Complex::getParteReale() const
{
	return this->ParteReale;
}

double Complex::getParteImmaginaria() const
{
	return this->ParteImmaginaria;
}

double Complex::getModulo() const
{
	double a = sqrt( this->getParteReale()*this->getParteReale() + this->getParteImmaginaria()*this->getParteImmaginaria() );
	return a;
}

Complex Complex::somma( Complex& z)
{
	Complex w( this->getParteReale() + z.getParteReale(), this->getParteImmaginaria() + z.getParteImmaginaria() );
	return w;
}

Complex Complex::inverso()
{
	Complex w( this->getParteReale() / ( this->getModulo()*this->getModulo() ), -this->getParteImmaginaria() / ( this->getModulo()*this->getModulo() ) );
	return w;
}

Complex Complex::coniugato()
{
	Complex w( this->getParteReale(), -this->getParteImmaginaria() );
	return w;
}

Complex Complex::moltiplicazione( double& x )
{
	Complex w( this->getParteReale() * x, this->getParteImmaginaria() * x );
	return w;
}

Complex Complex::moltiplicazione( Complex& z )
{
	Complex w( this->getParteReale()*z.getParteReale() - this->getParteImmaginaria()*z.getParteImmaginaria(), this->getParteReale()*z.getParteImmaginaria() + this->getParteImmaginaria()*z.getParteReale() );
	return w;
}

Complex operator+( const Complex& w, const Complex& z )
{
	Complex q( w.getParteReale() + z.getParteReale(), w.getParteImmaginaria() + z.getParteImmaginaria() );
	return q;
}

Complex operator*( const double& r, const Complex& z )
{
	Complex w( r*z.getParteReale(), r*z.getParteImmaginaria() );
	return w;
}

Complex operator*( const Complex& w, const Complex& z )
{
	Complex q( w.getParteReale()*z.getParteReale() - w.getParteImmaginaria()*z.getParteImmaginaria(), w.getParteReale()*z.getParteImmaginaria() + w.getParteImmaginaria()*z.getParteReale() );
	return q;
}
