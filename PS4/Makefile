CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = main.o ED.o
OBJECTSTEST = ED.o test.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
TEST = -lboost_unit_test_framework
all: ED Unit_Test
ED: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o ED $(LFLAGS)
ED.o: ED.h ED.cpp
	$(CC) $(CFLAGS) -c ED.cpp -o ED.o $(LFLAGS)
main.o: main.cpp ED.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LFLAGS)
test.o: test.cpp ED.h
	$(CC) $(CFLAGS) $(TEST) -c test.cpp -o test.o
Unit_Test: $(OBJECTSTEST)
	g++ -Wall $(OBJECTSTEST) -o Unit_Test $(LFLAGS) $(TEST)
clean:
	rm $(OBJECTS) test.o ED Unit_Test
