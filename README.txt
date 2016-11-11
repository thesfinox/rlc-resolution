///////////////////////////////////////////////

Università degli studi di Torino
Corso di Laurea in Fisica

Esame di Tecniche di Calcolo
anno accademico 2014 - 2015

        ******  *       ******
        *    *  *       *
        ******  *       *
        * *     *       *
        *  *    *       *
        *    *  ******  ******

///////////////////////////////////////////////

Autori:
        Alessandra Cappati
        Luca Gambarana
        Riccardo Caramellino
        Riccardo Finotello
        

***********************
1. INTRODUZIONE
***********************

Il programma risolve un arbitrario circuito elettrico di tipo
RLC: vengono restituiti in output (con la possibilità di salvare
su file di testo) i parametri del circuito (impedenza totale,
corrente circolante e suo sfasamento).

***********************
2. INSTALLAZIONE
***********************

a)      Da terminale entrare nella cartella dei file sorgenti in cui
        è presente anche questo README.
b)      Digitare 'make' (senza apici) nel terminale ed attendere la 
        fine della compilazione (deve essere installato g++).
c)      Digitare './rlc-resolution' (senza apici) per avviare il programma.

Eventualmente:
        c.1)    Digitare 'make clean' (senza apici) per eliminare i
                file *.o generati dalla compilazione dei file sorgente.
        c.2)    Digitare 'sudo make install' (senza apici) per copiare
                l'eseguibile del programma nella cartella /usr/bin/ e
                averlo sempre disponibile da terminale come comando.
                        
***********************
3. ISTRUZIONI
***********************
Il programma guida ad ogni passo l'utente nell'inserimento, 
consentendo di non necessitare di una guida completa all'uso.
Tuttavia si tenga conto della possibilità di inserire valori tramite
il prefisso dell'unità di misura dopo avere interposto uno
spazio. In particolare:
        
        Potenziale [V]: 1.45 k          CORRETTO
        Potenziale [V]: 1.45k           SBAGLIATO
                
L'elenco degli identificativi delle unità di misura è:

        PREFISSO                SIMBOLO                 Ordine (10^n)
        yotta                   Y                               24
        zetta                   Z                               21
        exa                     E                               18
        peta                    P                               15
        tera                    T                               12
        giga                    G                               9
        mega                    M                               6
        chilo                   k                               3
        hecto                   h                               2
                                                                0
        deci                    d                               -1
        centi                   c                               -2
        milli                   m                               -3
        micro                   u                               -6
        nano                    n                               -9
        pico                    p                               -12
        femto                   f                               -15
        atto                    a                               -18
        zepto                   z                               -21
        yocto                   y                               -24

