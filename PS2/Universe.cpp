#include <iostream>
#include <string>
#include "Universe.hpp"
#include <math.h>

using namespace std;
void Universe::add(CelestialBody a){
	planets.push_back(a);
	}
	void Universe::draw(sf::RenderTarget &target, double radius){
	for(int i = 0; i < (int)planets.size(); i++){
	planets[i].draw(target, radius);
	}
	}
	
void Universe::step(double seconds){
	    // find force
	int i;
	double netx;
	double nety;
	double Gravity_Constant = 6.67*pow(10,-11);
	for (i = 0; i < (int)planets.size(); i++){
	netx = 0;
	nety = 0;
	for(int j = 0; j < (int)planets.size(); j++){
	if(i != j){
	double dx = planets[j].getx() - planets[i].getx();
	double dy = planets[j].gety() - planets[i].gety();
	double distance = sqrt(pow(dx,2) + pow(dy,2));
	double f = ((Gravity_Constant * planets[j].getmass() * 	   planets[i].getmass()) / pow(distance,2));
	netx += (f*(dx/distance));
	nety += (f*(dy/distance));
	}
	}
	planets[i].setxnetforce(netx);
	planets[i].setynetforce(nety);
}

//get acceleration
for(i = 0; i < (int)planets.size(); i++){
double a_x = planets[i].getxnetforce() / planets[i].getmass();
double a_y = planets[i].getynetforce() / planets[i].getmass();
planets[i].setax(a_x);
planets[i].setay(a_y);
}

//get velocity
for(i = 0; i < (int)planets.size(); i++){
double vx = (planets[i].getax()*seconds) + planets[i].getxvelocity();
double vy = (planets[i].getay()*seconds) + planets[i].getyvelocity();
planets[i].setxvelocity(vx);
planets[i].setyvelocity(vy);
}

//get new position
for(i = 0; i < (int)planets.size(); i++){
double new_x =  (planets[i].getxvelocity()*seconds)+planets[i].getx();
double new_y =  (planets[i].getyvelocity()*seconds)+planets[i].gety();
planets[i].setx(new_x);
planets[i].sety(new_y);
}
	}
