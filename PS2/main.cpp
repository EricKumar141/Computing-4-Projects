#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Universe.hpp"
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <memory>
using namespace std;
int main(int argc, char* argv[]){

double current_time = 0;
double max_time = atof(argv[1]); 
double change_time = atof(argv[2]);
string filename;
int i;
int num_planets;
cin >> num_planets;
float radius;
cin >> radius;
Universe my_space;
CelestialBody temp;

for(i = 0; i < num_planets; i++){
cin >> temp;
my_space.add(temp);
}

sf::RenderWindow window(sf::VideoMode(radius, radius), "Universe");
sf::Texture t;
t.loadFromFile("universe.png");
sf::Sprite s(t);
    while (window.isOpen() && current_time < max_time)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(s);
        my_space.draw(window, radius);
        window.display();
       my_space.step(change_time);
       current_time += change_time;
    }
my_space.print();
return 0;
}
