CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = CelestialBody.o main.o Universe.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
all: NBody
NBody: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o NBody $(LFLAGS)
CelestialBody.o: CelestialBody.cpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o $(LFLAGS)
main.o: CelestialBody.hpp main.cpp Universe.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LFLAGS)
Universe.o: CelestialBody.hpp Universe.hpp Universe.cpp
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o $(LFLAGS)
clean:
	rm $(OBJECTS) NBody
