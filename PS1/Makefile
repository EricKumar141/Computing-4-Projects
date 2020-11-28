CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = FibLFSR.o PhotoMagic.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
all: PhotoMagic
PhotoMagic: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o PhotoMagic $(LFLAGS)
PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o $(LFLAGS)
FibLFSR.o: FibLFSR.hpp FibLFSR.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o $(LFLAGS)
clean:
	rm $(OBJECTS) PhotoMagic
