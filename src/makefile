#compiler
CC=g++

#flags
CFLAGS=-c
SOURCES= Complex.cpp Componente.cpp Resistenza.cpp Condensatore.cpp \
	 Induttanza.cpp Serie.cpp Parallelo.cpp Circuito.cpp \
	 CircuitoSerie.cpp CircuitoParallelo.cpp  UIManager.cpp \
	 MainClass.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=rlcsolve

#makefile
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

install:
	cp $(EXECUTABLE) /usr/local/bin/

clean:
	rm -rf *.o
