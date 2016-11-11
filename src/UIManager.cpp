/*
 * UIManager.cpp
 *
 *  Implementazione della gestione
 *  dell'interfaccia utente
 */

#include "UIManager.h"

#include <stdlib.h>
#include <cmath>
#include <iterator>

#include "CircuitoParallelo.h"
#include "CircuitoSerie.h"
#include "Parallelo.h"
#include "Serie.h"

using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

UIManager::UIManager()
{
	this->potenziale = 0.0;
	this->frequenza = 0.0;
}

UIManager::UIManager(double potenziale, double frequenza)
{
	setPotenziale(potenziale);
	setFrequenza(frequenza);
}

UIManager::~UIManager()
{
	vector<Componente*>::const_iterator iter;
	for(iter = serie.begin(); iter != serie.end(); iter++)
		delete (*iter);
	for(iter = paralleli.begin(); iter != paralleli.begin(); iter++)
		delete (*iter);
	for(iter = temp_serie.begin(); iter != temp_serie.end(); iter++)
		delete (*iter);
	for(iter = temp_paralleli.begin(); iter != temp_paralleli.begin(); iter++)
		delete (*iter);
	valori.clear();
}

void UIManager::start()
{
	cout<<"**********************************************************"<<endl<<endl;
	cout<<"Universit\u00E0 degli Studi di Torino"<<endl;
	cout<<"Corso di Laurea in Fisica"<<endl;
	cout<<"Esame di Tecniche di Calcolo"<<endl;
	cout<<"anno accademico 2014 - 2015"<<endl<<endl;
	cout<<"Autori:"<<endl;
	cout<<"\tAlessandra Cappati"<<endl;
	cout<<"\tRiccardo Caramellino"<<endl;
	cout<<"\tLuca Gambarana"<<endl;
	cout<<"\tRiccardo Finotello"<<endl;
	cout<<"**********************************************************"<<endl<<endl;
	cout<<"Il programma risolve un arbitrario circuito RLC (in serie"<<endl;
	cout<<"o in parallelo e restituisce l'impedenza totale e la corrente"<<endl;
	cout<<"totale in esso circolante, supponendo un'onda sinusoidale"<<endl;
	cout<<"in ingresso."<<endl<<endl;
	cout<<"**********************************************************"<<endl<<endl<<endl;

	if(potenziale == 0.0 && frequenza == 0.0)
	{
		string str_potenziale, str_frequenza;
		double temp_potenziale = 0.0, temp_frequenza = 0.0;

		cout<<"____________________________________________________________________________"<<endl;
		cout<<"Si inseriscano, seguiti da uno SPAZIO e dall'identificativo della"<<endl;
		cout<<"unit\u00E0 di misura, i parametri operativi del circuito:"<<endl<<endl;
		do
		{
			cout<<"\tPotenziale [V]:\t";
			getline(cin,str_potenziale);

			temp_potenziale = ControlloNumero(str_potenziale);

		} while(temp_potenziale == -1.0);

		setPotenziale(temp_potenziale);
		cout<<endl;
		cout<<"\tInserito: "<<temp_potenziale<<" V"<<endl<<endl;
		do
		{
			cout<<"\tFrequenza [Hz]:\t";
			getline(cin,str_frequenza);

			temp_frequenza = ControlloNumero(str_frequenza);

		} while(temp_frequenza == -1.0);

		setFrequenza(temp_frequenza);
		cout<<endl;
		cout<<"\tInserito: "<<temp_frequenza<<" Hz"<<endl<<endl;
		cout<<"____________________________________________________________________________"<<endl;
	}

	SezioneQ();
}

void UIManager::setPotenziale( double& potenziale )
{
	this->potenziale = potenziale;
}

void UIManager::setFrequenza( double& frequenza )
{
	this->frequenza = frequenza;
}

void UIManager::SezioneQ()
{
	string temp_scelta;
	char scelta;

	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Quale sezione si intende implementare?"<<endl;
	cout<<"[Si utilizzi R = resistenze, C = condensatori, L = induttanze, Q = uscita]"<<endl<<endl;
	do
	{
		cout<<"Sezione:\t";
		getline(cin,temp_scelta);

		scelta = ControlloCarattere(temp_scelta);

	} while(scelta == '0');

	cout<<endl;
	cout<<"____________________________________________________________________________"<<endl;

	switch(scelta)
	{
		case 'r': case 'R':
		{
			Resistenze();
			break;
		}

		case 'c': case 'C':
		{
			Condensatori();
			break;
		}

		case 'l': case 'L':
		{
			Induttanze();
			break;
		}

		case 'q': case 'Q':
		{
			CircuitoQ();
			break;
		}

		default:
		{
			NonValido();
			SezioneQ();
			break;
		}
	}
}

void UIManager::Resistenze()
{
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Inserimento della sezione resistiva del circuito."<<endl<<endl;

	string valore_temp;
	double temp_valore = 0.0;
	Serie *s;
	Parallelo *p;

	do
	{
		cout<<"Si inseriscano i valori delle resistenze seguite dall'identificativo"<<endl;
		cout<<"della unit\u00E0 di misura. Dopo l'inserimento del singolo valore"<<endl;
		cout<<"si prema INVIO."<<endl;
		cout<<"[Per terminare l'inserimento si inserisca il valore 0 (zero)]"<<endl<<endl;

		while(true)
		{
			do
			{
				getline(cin,valore_temp);
				temp_valore = ControlloNumero(valore_temp);

			} while(temp_valore == -1.0);

			if(temp_valore == 0.0)
			{
				s = new Serie(valori,RESISTENZA,this->frequenza);
				ComponenteInserito(s);
				temp_serie.push_back(s);
				valori.clear();
				cout<<endl;
				break;
			}
			else if (temp_valore > 0.0)
					valori.push_back(temp_valore);
			else
			{
				NonValido();
				continue;
			}
		}

		string scelta_temp;
		char scelta;

		cout<<"Nuovi elementi in serie connessi in parallelo al precedente?"<<endl;
		cout<<"[S per accettare, un carattere qualsiasi per uscire]"<<endl<<endl;
		do
		{
			cout<<"Scelta:\t";
			getline(cin,scelta_temp);

			scelta = ControlloCarattere(scelta_temp);

		} while(scelta == '0');

		cout<<endl;

		if(scelta == 's' || scelta == 'S')
			continue;
		else
		{
			p = new Parallelo(temp_serie);
			ComponenteInserito(p);
			temp_paralleli.push_back(p);
			cout<<endl;
			break;
		}

	} while(true);

	temp_serie.clear();
	SezioneQ();
}

void UIManager::Condensatori()
{
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Inserimento della sezione capacitiva del circuito."<<endl<<endl;

	string valore_temp;
	double temp_valore = 0.0;
	Serie *s;
	Parallelo *p;

	do
	{
		cout<<"Si inseriscano i valori dei condensatori seguiti dall'identificativo"<<endl;
		cout<<"della unit\u00E0 di misura. Dopo l'inserimento del singolo valore"<<endl;
		cout<<"si prema INVIO."<<endl;
		cout<<"[Per terminare l'inserimento si inserisca il valore 0 (zero)]"<<endl<<endl;

		while(true)
		{
			do
			{
				getline(cin,valore_temp);
				temp_valore = ControlloNumero(valore_temp);

			} while(temp_valore == -1.0);

			if(temp_valore == 0.0)
			{
				s = new Serie(valori,CONDENSATORE,this->frequenza);
				ComponenteInserito(s);
				temp_serie.push_back(s);
				valori.clear();
				cout<<endl;
				break;
			}
			else if(temp_valore > 0.0)
					valori.push_back(temp_valore);
			else
			{
				NonValido();
				continue;
			}
		}

		string scelta_temp;
		char scelta;

		cout<<"Nuovi elementi in serie connessi in parallelo al precedente?"<<endl;
		cout<<"[S per accettare, un tasto qualsiasi per uscire]"<<endl<<endl;

		do
		{
			cout<<"Scelta:\t";
			getline(cin,scelta_temp);

			scelta = ControlloCarattere(scelta_temp);

		} while(scelta == '0');

		cout<<endl;

		if(scelta == 's' || scelta == 'S')
			continue;
		else
		{
			p = new Parallelo(temp_serie);
			ComponenteInserito(p);
			temp_paralleli.push_back(p);
			cout<<endl;
			break;
		}

	} while(true);

	temp_serie.clear();
	SezioneQ();
}

void UIManager::Induttanze()
{
	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Inserimento della sezione induttiva del circuito."<<endl<<endl;

	string valore_temp;
	double temp_valore = 0.0;
	Serie *s;
	Parallelo *p;

	do
	{
		cout<<"Si inseriscano i valori delle induttanze seguite dall'identificativo"<<endl;
		cout<<"della unit\u00E0 di misura. Dopo l'inserimento del singolo valore"<<endl;
		cout<<"si prema INVIO."<<endl;
		cout<<"[Per terminare l'inserimento si inserisca il valore 0 (zero)]"<<endl<<endl;

		while(true)
		{
			do
			{
				getline(cin,valore_temp);
				temp_valore = ControlloNumero(valore_temp);

			} while(temp_valore == -1.0);

			if(temp_valore == 0.0)
			{
				s = new Serie(valori,INDUTTANZA,this->frequenza);
				ComponenteInserito(s);
				temp_serie.push_back(s);
				valori.clear();
				cout<<endl;
				break;
			}
			else if(temp_valore > 0.0)
				valori.push_back(temp_valore);
			else
			{
				NonValido();
				continue;
			}
		}

		string scelta_temp;
		char scelta;

		cout<<"Nuovi elementi in serie connessi in parallelo al precedente?"<<endl;
		cout<<"[S per accettare, un tasto qualsiasi per uscire]"<<endl<<endl;

		do
		{
			cout<<"Scelta:\t";
			getline(cin,scelta_temp);

			scelta = ControlloCarattere(scelta_temp);

		} while(scelta == '0');

		cout<<endl;

		if(scelta == 's' || scelta == 'S')
			continue;
		else
		{
			p = new Parallelo(temp_serie);
			ComponenteInserito(p);
			temp_paralleli.push_back(p);
			cout<<endl;
			break;
		}

	} while(true);

	temp_serie.clear();
	SezioneQ();
}

void UIManager::CircuitoQ()
{
	string temp_scelta;
	char scelta;

	cout<<"____________________________________________________________________________"<<endl;
	cout<<"Quale tipo di circuito si intende risolvere?"<<endl;
	cout<<"[Si utilizzi S = serie oppure P = parallelo]"<<endl<<endl;
	do
	{
		cout<<"Circuito:\t";
		getline(cin,temp_scelta);

		scelta = ControlloCarattere(temp_scelta);

	} while(scelta == '0');
	cout<<endl;
	cout<<"____________________________________________________________________________"<<endl;

	Circuito* c;

	switch(scelta)
	{
		case 's': case 'S':
		{
			c = new CircuitoSerie(temp_paralleli,potenziale);
			break;
		}

		case 'p': case 'P':
		{
			c = new CircuitoParallelo(temp_paralleli,potenziale);
			break;
		}

		default:
		{
			NonValido();
			CircuitoQ();
			break;
		}
	}

	c->stampaCircuito();

	char nomefile[256];

	cout<<"Si desidera stampare il risultato su file? [S/n]"<<endl<<endl;
	do
	{
		cout<<"Scelta:\t";
		getline(cin,temp_scelta);

		scelta = ControlloCarattere(temp_scelta);

	} while(scelta == '0');
	cout<<endl;

	do
	{
		if(scelta == 's' || scelta == 'S')
		{
			bool verifica;

			do
			{
				cout<<"Inserire il nome del file (max 256 caratteri): ";
				cin>>nomefile;
				cout<<endl;
				verifica = c->stampaFile(nomefile);

				if(!verifica)
					cout<<"Salvato con successo su "<<nomefile<<endl<<endl;

			} while(verifica);

			break;
		}
		else if(scelta == 'n' || scelta == 'N')
			break;
		else
		{
			NonValido();
			continue;
		}

	} while(true);

	cout<<"Il programma \u00E8 uscito con successo..."<<endl<<endl<<endl;
	exit(EXIT_SUCCESS);
}

void UIManager::NonValido() const
{
	cout<<endl<<endl;
	cout<<"\a************************************"<<endl;
	cout<<"   SCELTA NON VALIDA"<<endl;
	cout<<"************************************"<<endl<<endl;
}

void UIManager::ComponenteInserito( Componente* componente ) const
{
	cout<<endl<<endl;
	cout<<componente->getNome()<<" inserito:"<<endl;
	componente->stampaComponente();
	cout<<endl<<endl;
}

double UIManager::moltiplicatore( double& valore, char unita ) const
{
	switch(unita)
	{
		case 'y' : //yocto
		{
			return valore*pow(10,-24);
			break;
		}

		case 'z' : //zepto
		{
			return valore*pow(10,-21);
			break;
		}

		case 'a' : //atto
		{
			return valore*pow(10,-18);
			break;
		}

		case 'f' : //femto
		{
			return valore*pow(10,-15);
			break;
		}

		case 'p' : //pico
		{
			return valore*pow(10,-12);
			break;
		}

		case 'n' : //nano
		{
			return valore*pow(10,-9);
			break;
		}

		case 'u' : //micro
		{
			return valore*pow(10,-6);
			break;
		}

		case 'm' : //milli
		{
			return valore*pow(10,-3);
			break;
		}

		case 'c' : //centi
		{
			return valore*pow(10,-2);
			break;
		}

		case 'd' : //deci
		{
			return valore*pow(10,-1);
			break;
		}

		case 'h' : //etto
		{
			return valore*pow(10,2);
			break;
		}

		case 'k' : case 'K' : //chilo
		{
			return valore*pow(10,3);
			break;
		}

		case 'M' : //mega
		{
			return valore*pow(10,6);
			break;
		}

		case 'G' : //giga
		{
			return valore*pow(10,9);
			break;
		}

		case 'T' : //tera
		{
			return valore*pow(10,12);
			break;
		}

		case 'P' : //peta
		{
			return valore*pow(10,15);
			break;
		}

		case 'E' : //exa
		{
			return valore*pow(10,18);
			break;
		}

		case 'Z' : //zetta
		{
			return valore*pow(10,21);
			break;
		}

		case 'Y' : //yotta
		{
			return valore*pow(10,24);
			break;
		}

		default :
		{
			return valore;
			break;
		}
	}
}

char UIManager::ControlloCarattere(string s) const
{
	const char* str = s.c_str();

	for(int idx = 0; idx < (int)s.size(); idx++)
	{
		if((str[idx] >= '0' && str[idx] <= '9') || (int)s.size() != 1)
		{
			NonValido();
			cout<<endl;
			return '0';
		}
	}

	return *str;
}

double UIManager::ControlloNumero(string s) const
{
	// stringhe di appoggio
	string s2;
	string s3;

	// puntatore all'elemnto della stringa
	const char *str = s.c_str();

	//indice
	int idx;

	// scorre lungo la stringa fino al separatore dell'ordine
	// di grandezza e crea la nuova stringa numero
	for(idx = 0; idx < (int)s.size() && str[idx] != ' '; idx++)
	{
		if((str[idx] < '.' || str[idx] > '9') || str[idx] == '/')
		{
			NonValido();
			cout<<endl;
			return -1.0;
		}
		else
			s2.push_back(str[idx]);
	}

	// Scorre sui rimanenti elementi che formano un'altra stringa
	// se verificata questa genera l'ordine di grandezza
	for(int idy = idx; idy < (int)s.size()-1; idy++)
		s3.push_back(str[idx+1]);

	if(ControlloCarattere(s3) == '0')
	{
		NonValido();
		cout<<endl;
		return -1.0;
	}

	const char *str2 = s2.c_str();

	// restituisce il valore moltiplicato per il suo ordine di grandezza
	double d = strtod(str2,NULL);
	return moltiplicatore(d,ControlloCarattere(s3));
}
