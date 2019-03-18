all: main.out


main.out: main.o fonction.o Vect.o Tour.o Base.o Couleur.o Monstre.o Vague.o Bouton.o Menu.o Effet.o Attaque.o Sort.o  Chemin.o Carte.o 

	g++ -g main.o Vect.o Tour.o Base.o Couleur.o Monstre.o Vague.o Bouton.o Menu.o Effet.o Attaque.o Sort.o -o main.out

main.o: main.cpp Vect.h Tour.h Base.h
	g++ -g -Wall -c main.cpp

Tour.o: Tour.h Tour.cpp Vect.h
	g++ -g -Wall -c Tour.cpp

Base.o: Base.h Base.cpp Vect.h
	g++ -g -Wall -c Base.cpp

Bouton.o: Bouton.h Bouton.cpp Vect.h
	g++ -g -Wall -c Bouton.cpp

Vect.o: Vect.h Vect.cpp
	g++ -g -Wall -c Vect.cpp

Couleur.o: Couleur.h Couleur.cpp
	g++ -g -Wall -c Couleur.cpp
	
Monstre.o: Monstre.h Monstre.cpp Vect.h
	g++ -g -Wall -c Monstre.cpp
	
Vague.o: Vague.h Vague.cpp Monstre.h
	g++ -g -Wall -c Vague.cpp

Menu.o: Menu.h Menu.cpp Bouton.h Vect.h
	g++ -g -Wall -c Menu.cpp

Effet.o: Effet.h Effet.cpp
	g++ -g -Wall -c Effet.cpp

Attaque.o: Attaque.h Attaque.cpp Effet.h
	g++ -g -Wall -c Attaque.cpp

Sort.o: Sort.h Sort.cpp Attaque.h
	g++ -g -Wall -c Sort.cpp

#Hero.o: Hero.h Hero.cpp Sort.h Vect.h
	#g++ -g -Wall -c Hero.cpp
	
Carte.o: Carte.h Carte.cpp Tour.h Vague.h Chemin.h Vect.h
	g++ -g -Wall -c Carte.cpp

fonction.o: fonction.h 
	g++ -g -Wall -c fonction.cpp

Chemin.o: Chemin.h Chemin.cpp Vect.h
	g++ -g -Wall -c Chemin.cpp
	
clean:
	rm *.o

veryclean: clean
	rm *.out