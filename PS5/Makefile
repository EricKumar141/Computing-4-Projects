CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = TextGenerator.o MModel.o
OBJECTSTEST = MModel.o test.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
TEST = -lboost_unit_test_framework
all: TextGenerator Unit_Test
TextGenerator: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o TextGenerator $(LFLAGS)
MModel.o: MModel.h MModel.cpp
	$(CC) $(CFLAGS) -c MModel.cpp -o MModel.o $(LFLAGS)
TextGenerator.o: TextGenerator.cpp MModel.h
	$(CC) $(CFLAGS) -c TextGenerator.cpp -o TextGenerator.o $(LFLAGS)
test.o: test.cpp MModel.h
	$(CC) $(CFLAGS) $(TEST) -c test.cpp -o test.o
Unit_Test: $(OBJECTSTEST)
	g++ -Wall $(OBJECTSTEST) -o Unit_Test $(LFLAGS) $(TEST)
clean:
	rm $(OBJECTS) test.o TextGenerator Unit_Test
