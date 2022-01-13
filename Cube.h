#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
class Cube
{

public:

	//Constructeur
	Cube(const float x, const float y, const float z, const float size, const float colors[6][3]);

	//Getters / Setters
	float getX();
	float getY();
	float getZ();
	void setX(const float x);
	void setY(const float y);
	void setZ(const float z);
	std::vector<sf::Vector3f*> getPoints();

	//Dessin du cube.
	void draw();
	
	//Destructeur
	~Cube();

private:

	//Déclaration des attributs.
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

