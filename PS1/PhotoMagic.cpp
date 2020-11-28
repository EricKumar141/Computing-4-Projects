#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include "FibLFSR.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;
void transform(sf::Image& image, FibLFSR* seed);

void transform(sf::Image& image, FibLFSR* seed)
{
unsigned int x;
unsigned int y;
sf::Vector2u size = image.getSize();
sf::Color change;
for(x = 0; x < size.x; x++){
	for(y = 0; y < size.y; y++)
	{
	change = image.getPixel(x,y);
	change.r = change.r ^ seed->generate(8); //255 options for color thus generate 8 bit number
	change.b = change.b ^ seed->generate(8);
	change.g = change.g ^ seed->generate(8);
	image.setPixel(x,y,change);
	}
}
}
int main()
{
string input;
string output;
string LSFR;

cout <<" % PhotoMagic ";
std::cin>>input;
std::cin.ignore(1, ' ');
std::cin>>output;
std::cin.ignore(1, ' ');
std::cin>>LSFR;

sf::String input_image = input;
sf::String output_image = output;
FibLFSR seed(LSFR);

sf::Image input_file;
if(!input_file.loadFromFile(input_image)){
return -1;
}
sf::Image output_file;
if(!output_file.loadFromFile(input_image)){
return -1;
}
transform(output_file, &seed);

sf::Vector2u size = input_file.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Original Photo");
	sf::Texture texture;
	texture.loadFromImage(input_file);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
sf::Vector2u size1 = output_file.getSize();
sf::RenderWindow window2(sf::VideoMode(size1.x, size1.y), "Transformed");
	sf::Texture texture1;
	texture1.loadFromImage(output_file);
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);

while (window1.isOpen() && window2.isOpen()) {                                
sf::Event event;
while (window1.pollEvent(event))
 {
 if (event.type == sf::Event::Closed)
 window1.close();
        }        
while (window2.pollEvent(event)) 
{
if (event.type == sf::Event::Closed)
window2.close();       
}
window1.clear();       
window1.draw(sprite);       
window1.display();       
window2.clear();       
window2.draw(sprite1);       
window2.display();   
}

if(!output_file.saveToFile(output_image)){
return -1;
}
return 0;
}
