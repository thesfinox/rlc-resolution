/*
 * Complex.h
 *
 *  La classe esegue operazioni con numeri complessi
 *  visti come coppie ordinate di numeri reali su
 *  uno spazio vettoriale a due dimensioni su R (campo
 *  reale).
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex
{
private:
	//Data Member
	double ParteReale, ParteImmaginaria;

public:
	//Costruttore (parte reale e parte immaginaria come argomenti)
	Complex();
	Complex( double , double );

	//Operazioni con numeri complessi
	Complex somma( Complex& );
	Complex inverso();
	Complex coniugato();
	Complex moltiplicazione( double& );
	Complex moltiplicazione( Complex& );

	//Overload degli operatori
	friend Complex operator+( const Complex&, const Complex& );
	friend Complex operator*( const Complex&, const Complex& );
	friend Complex operator*( const double&, const Complex& );

	//Metodi SET
	void setParteReale( double );
	void setParteImmaginaria( double );

	//Metodi GET
	double getParteReale() const;
	double getParteImmaginaria() const;
	double getModulo() const;
};

#endif /* COMPLEX_H_ */
