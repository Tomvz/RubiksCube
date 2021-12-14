#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
class Cube
{

public:

	Cube(float x, float y, float z, float size, float colors[6][3]);
	float getX();
	float getY();
	float getZ();
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	std::vector<sf::Vector3f*> getPoints();
	void draw();
	~Cube();

private:

	float x;
	float y;
	float z;
	float size;
	float bottom[3];
	float top[3];
	float left[3];
	float right[3];
	float backward[3];
	float forward[3];
	std::vector<sf::Vector3f *> vectors;

};

