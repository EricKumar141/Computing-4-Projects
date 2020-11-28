#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
class CelestialBody
{  
public:
	CelestialBody() = default;
	CelestialBody(double _x, double _y, double _xvelocity, double _yvelocity, double _mass, string _filename);
	void setx(double _x){
	x = _x;
	}
	void sety(double _y){
	y = _y;
	}
	void setax(double _ax){
	ax = _ax;
	}
	void setay(double _ay){
	ay = _ay;
	}
	void setxvelocity(double _xvelocity){
	xvelocity = _xvelocity;
	}
	void setyvelocity(double _yvelocity){
	yvelocity = _yvelocity;
	}
	void setxnetforce(double _xforce){
	netforcex = _xforce;
	}
	void setynetforce(double _yforce){
	netforcey = _yforce;
	}
	double getx(){
	return x;
	}
	double gety(){
	return y;
	}
	double getxvelocity(){
	return xvelocity;
	}
	double getyvelocity(){
	return yvelocity;
	}
	double getxnetforce(){
	return netforcex;
	}
	double getynetforce(){
	return netforcey;
	}
	double getax(){
	return ax;
	}
	double getay(){
	return ay;
	}
	double getmass(){
	return mass;
	}
	
	friend istream &operator>>(istream &input, CelestialBody &p){
	input >> p.x;
	input.ignore(1, ' ');
	input >> p.y;
	input.ignore(1, ' ');
	input >> p.xvelocity;
	input.ignore(1, ' ');
	input >> p.yvelocity;
	input.ignore(1, ' ');
	input >> p.mass;
	input.ignore(1, ' ');
	input >> p.filename;
	sf::Image _image;
	_image.loadFromFile(p.filename);
	p.texture.loadFromImage(_image);
	p.sprite.setTexture(p.texture);
	return input;
	}
	
	friend ostream &operator<<(ostream &output, CelestialBody &p){
	output << p.x << " " << p.y << " " << p.xvelocity << " " << p.yvelocity << " " << p.mass << " " << p.filename <<endl;
	return output;
	}
virtual void draw(sf::RenderTarget &target, double radius){
	sf::Image _image;
	_image.loadFromFile(filename);
	texture.loadFromImage(_image);
	sprite.setTexture(texture); // had to reload sprite and texture otherwise blank image would show
	sf::Vector2u size = target.getSize(); 

	double x_adjust = (x/radius) * (size.x/2) + (size.x/2); // scales postion to window radius
	double y_adjust = (y/radius) * (size.y/2) + (size.y/2);
	sf::FloatRect dimensions = sprite.getGlobalBounds();
	x_adjust -= (dimensions.width/2); // adjust positon from center
	y_adjust -= (dimensions.height/2);
	y_adjust = size.y-y_adjust; //flips y positon so orbits counterclockwise
	sprite.setPosition(x_adjust, y_adjust);
	target.draw(sprite);
}


private:

	double x;
	double y;
	double xvelocity;
	double yvelocity;
	double mass;
	string filename;
	sf::Texture texture;
	sf::Sprite sprite;
	double netforcex;
	double netforcey;
	double ax;
	double ay;
};

