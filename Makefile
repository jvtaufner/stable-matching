tp01: main.o clinic.o person.o
	g++ -O3 main.o clinic.o person.o -o tp01
main.o: main.cpp
	g++ -c main.cpp
clinic.o: ./src/clinic.cpp
	g++ -c ./src/clinic.cpp
person.o: ./src/person.cpp
	g++ -c ./src/person.cpp
clean:
	rm *.o tp01