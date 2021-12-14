#include "Cube.h"

Cube::Cube(float x, float y, float z, float size, float colors[6][3])
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->size = size;

	this->bottom[0] = colors[0][0];
	this->bottom[1] = colors[0][1];
	this->bottom[2] = colors[0][2];

	this->top[0] = colors[1][0];
	this->top[1] = colors[1][1];
	this->top[2] = colors[1][2];

	this->left[0] = colors[2][0];
	this->left[1] = colors[2][1];
	this->left[2] = colors[2][2];

	this->right[0] = colors[3][0];
	this->right[1] = colors[3][1];
	this->right[2] = colors[3][2];

	this->backward[0] = colors[4][0];
	this->backward[1] = colors[4][1];
	this->backward[2] = colors[4][2];

	this->forward[0] = colors[5][0];
	this->forward[1] = colors[5][1];
	this->forward[2] = colors[5][2];

	this->vectors.push_back(new sf::Vector3f(x - size / 2, y + size/2, z + size/2));
	this->vectors.push_back(new sf::Vector3f(x + size / 2, y + size/2, z + size/2));
	this->vectors.push_back(new sf::Vector3f(x + size / 2, y - size/2, z + size/2));
	this->vectors.push_back(new sf::Vector3f(x - size / 2, y - size/2, z + size/2));
	this->vectors.push_back(new sf::Vector3f(x - size / 2, y + size/2, z - size/2));
	this->vectors.push_back(new sf::Vector3f(x + size / 2, y + size/2, z - size/2));
	this->vectors.push_back(new sf::Vector3f(x + size / 2, y - size/2, z - size/2));
	this->vectors.push_back(new sf::Vector3f(x - size / 2, y - size/2, z - size/2));
}

std::vector<sf::Vector3f *> Cube::getPoints()
{
	return this->vectors;
}

float Cube::getX()
{
	return this->x;
}

float Cube::getY()
{
	return this->y;
}

float Cube::getZ()
{
	return this->z;
}
void Cube::setX(float x)
{
	this->x = x;
}

void Cube::setY(float y)
{
	this->y = y;
}

void Cube::setZ(float z)
{
	this->z = z;
}

void Cube::draw()
{

	float hs = this->size / 2;

	glBegin(GL_QUADS);
	{
		glColor3f(this->bottom[0], this->bottom[1], this->bottom[2]);
		glVertex3f(this->vectors[7]->x, this->vectors[7]->y, this->vectors[7]->z);
		glVertex3f(this->vectors[6]->x, this->vectors[6]->y, this->vectors[6]->z);
		glVertex3f(this->vectors[2]->x, this->vectors[2]->y, this->vectors[2]->z);
		glVertex3f(this->vectors[3]->x, this->vectors[3]->y, this->vectors[3]->z);

		glColor3f(this->top[0], this->top[1], this->top[2]);
		glVertex3f(this->vectors[4]->x, this->vectors[4]->y, this->vectors[4]->z);
		glVertex3f(this->vectors[5]->x, this->vectors[5]->y, this->vectors[5]->z);
		glVertex3f(this->vectors[1]->x, this->vectors[1]->y, this->vectors[1]->z);
		glVertex3f(this->vectors[0]->x, this->vectors[0]->y, this->vectors[0]->z);

		glColor3f(this->left[0], this->left[1], this->left[2]);
		glVertex3f(this->vectors[4]->x, this->vectors[4]->y, this->vectors[4]->z);
		glVertex3f(this->vectors[0]->x, this->vectors[0]->y, this->vectors[0]->z);
		glVertex3f(this->vectors[3]->x, this->vectors[3]->y, this->vectors[3]->z);
		glVertex3f(this->vectors[7]->x, this->vectors[7]->y, this->vectors[7]->z);

		glColor3f(this->right[0], this->right[1], this->right[2]);
		glVertex3f(this->vectors[5]->x, this->vectors[5]->y, this->vectors[5]->z);
		glVertex3f(this->vectors[1]->x, this->vectors[1]->y, this->vectors[1]->z);
		glVertex3f(this->vectors[2]->x, this->vectors[2]->y, this->vectors[2]->z);
		glVertex3f(this->vectors[6]->x, this->vectors[6]->y, this->vectors[6]->z);

		glColor3f(this->backward[0], this->backward[1], this->backward[2]);
		glVertex3f(this->vectors[0]->x, this->vectors[0]->y, this->vectors[0]->z);
		glVertex3f(this->vectors[1]->x, this->vectors[1]->y, this->vectors[1]->z);
		glVertex3f(this->vectors[2]->x, this->vectors[2]->y, this->vectors[2]->z);
		glVertex3f(this->vectors[3]->x, this->vectors[3]->y, this->vectors[3]->z);

		glColor3f(this->forward[0], this->forward[1], this->forward[2]);
		glVertex3f(this->vectors[4]->x, this->vectors[4]->y, this->vectors[4]->z);
		glVertex3f(this->vectors[5]->x, this->vectors[5]->y, this->vectors[5]->z);
		glVertex3f(this->vectors[6]->x, this->vectors[6]->y, this->vectors[6]->z);
		glVertex3f(this->vectors[7]->x, this->vectors[7]->y, this->vectors[7]->z);
	}
	glEnd();
}

Cube::~Cube()
{
	for (sf::Vector3f* v : this->vectors)
	{
		delete v;
		v = nullptr;
	}
}