#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "CelestialBody.hpp"
using namespace std;
class Universe
{
public:

	void add(CelestialBody a);
	void draw(sf::RenderTarget &target, double radius);
	void step(double seconds);
	void print(){
	for(int i = 0; i < (int)planets.size(); i++){
	cout << planets[i];
	}
	}
	
private:
	vector<CelestialBody> planets;
};
