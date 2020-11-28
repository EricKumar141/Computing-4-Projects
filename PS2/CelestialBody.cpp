#include <iostream>
#include <string>
#include "CelestialBody.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
CelestialBody::CelestialBody(double _x, double _y, double _xvelocity, double _yvelocity, double _mass, string _filename){
	x = _x;
	y = _y;
	xvelocity = _xvelocity;
	yvelocity = _yvelocity;
	mass = _mass;
	filename = _filename;
	sf::Image _image;
	//sprite.setPosition(200,-200);
	_image.loadFromFile(_filename);
	texture.loadFromImage(_image);
	sprite.setTexture(texture);	
}
