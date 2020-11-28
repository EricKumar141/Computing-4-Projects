CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = CircularBuffer.o StringSound.o KSGuitarSim.o
OBJECTSTEST = CircularBuffer.o StringSound.o test.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
TEST = -lboost_unit_test_framework
all: KSGuitarSim Unit_Test
KSGuitarSim: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o KSGuitarSim $(LFLAGS)
CircularBuffer.o: CircularBuffer.h CircularBuffer.cpp
	$(CC) $(CFLAGS) -c CircularBuffer.cpp -o CircularBuffer.o $(LFLAGS)
StringSound.o: StringSound.h CircularBuffer.h StringSound.cpp
	$(CC) $(CFLAGS) -c StringSound.cpp -o StringSound.o $(LFLAGS)
KSGuitarSim.o: KSGuitarSim.cpp StringSound.h CircularBuffer.h
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp -o KSGuitarSim.o $(LFLAGS)
test.o: test.cpp CircularBuffer.h StringSound.h
	$(CC) $(CFLAGS) $(TEST) -c test.cpp -o test.o
Unit_Test: $(OBJECTSTEST)
	g++ -Wall $(OBJECTSTEST) -o Unit_Test $(LFLAGS) $(TEST)
clean:
	rm $(OBJECTS) test.o KSGuitarSim Unit_Test
