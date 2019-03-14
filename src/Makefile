all: main.out

main.out: main.o Vect.o Tour.o
	g++ -g main.o Vect.o Tour.o -o main.out

main.o: main.cpp Vect.h Tour.h
	g++ -g -Wall -c main.cpp

Tour.o: Tour.h Tour.cpp Vect.h
	g++ -g -Wall -c Tour.cpp

Vect.o: Vect.h Vect.cpp
	g++ -g -Wall -c Vect.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out