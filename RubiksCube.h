#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include "Cube.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>
#include <tuple>
#include <math.h>
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
# define PI          3.141592653589793238462643383279502884

class RubiksCube
{

public:

	RubiksCube(sf::Window *window);
	void shuffle();
	void rotate(int i, int s, float speed);
	std::vector<Cube*> getCubes();
	void draw();
	void control(sf::Event ev);
	~RubiksCube();

	float size;

	//COLORS IN FLOAT :
	float BLACK[3] = { 0.f, 0.f, 0.f };
	float WHITE[3] = { 1.f, 1.f, 1.f };
	float GREEN[3] = { 0.3451, 0.8353, 0.4078 };
	float YELLOW[3] = { 0.949, 0.949, 0.0824 };
	float ORANGE[3] = { 0.9099, 0.6196, 0.0824 };
	float RED[3] = { 0.9294, 0.1882, 0.1882 };
	float BLUE[3] = { 0.1099, 0.3725, 0.9961 };

private:

	sf::Window *window;
	void initCubes();
	std::vector<Cube *> cube_list;

};

