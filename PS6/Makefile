CC = g++
Debug = -g
CFLAGS = -c -Wall -Werror -std=c++11
OBJECTS = PS6.o
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system 
REGEX = -lboost_regex -lboost_date_time
TEST = -lboost_unit_test_framework
all: ps6
ps6: $(OBJECTS)
	g++ -Wall $(OBJECTS) -o ps6 $(LFLAGS) $(REGEX)
PS6.o: PS6.cpp
	$(CC) $(CFLAGS) -c PS6.cpp -o PS6.o $(LFLAGS) $(REGEX)
clean:
	rm $(OBJECTS) ps6
