/*
 * UIManager.h
 *
 *  Generazione e gestione dell'interfaccia
 *  testuale utente.
 */

#ifndef UIMANAGER_H_
#define UIMANAGER_H_

#include <string>
#include <vector>

#include "Componente.h"

using std::vector;

class UIManager
{
private:
	double potenziale, frequenza;
	vector<Componente*> serie, paralleli, temp_serie, temp_paralleli;
	vector<double> valori;

	//Member functions (l'utente non deve poter
	//modificare nulla, ma solo avviare il processo)
	void setPotenziale( double& );
	void setFrequenza( double& );

	void SezioneQ(); //Chiede quale sezione si vuole implementare (R/L/C)
	void CircuitoQ(); //Chiede quale tipo di circuito si vuole implementare (serie/parallelo)

	//Inserimento dati
	void Resistenze();
	void Condensatori();
	void Induttanze();

	//Gestione inserimento
	void NonValido() const; //qualora venisse inserita una scelta non valida
	void ComponenteInserito( Componente* ) const; //mostra il componente inserito
	double moltiplicatore( double&, char ) const; //per le unita di misura

	//Gestione input
	char ControlloCarattere(string) const;
	double ControlloNumero(string) const;

public:
	//Costruttore per l'inizializzazione degli oggetti
	UIManager();
	UIManager( double, double ); //con potenziale e frequenza
	~UIManager();

	//Metodo per dare il via all'immissione dei dati
	void start();
};

#endif /* UIMANAGER_H_ */
