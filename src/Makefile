all: main.out

main.out: main.o Vect.o Tour.o Base.o Couleur.o Monstre.o Vague.o
	g++ -g main.o Vect.o Tour.o Base.o Couleur.o -o main.out

main.o: main.cpp Vect.h Tour.h Base.h
	g++ -g -Wall -c main.cpp

Tour.o: Tour.h Tour.cpp Vect.h
	g++ -g -Wall -c Tour.cpp

Base.o: Base.h Base.cpp Vect.h
	g++ -g -Wall -c Base.cpp

Vect.o: Vect.h Vect.cpp
	g++ -g -Wall -c Vect.cpp

Couleur.o: Couleur.h Couleur.cpp
	g++ -g -Wall -c Couleur.cpp
	
Monstre.o: Monstre.h Monstre.cpp Vect.h
	g++ -g -Wall -c Monstre.cpp
	
Vague.o: Vague.h Vague.cpp Monstre.h
	g++ -g -Wall -c Vague.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out