#pragma once
#include "Cube.h"
#include <vector>
#include <math.h>
#include <random>
# define PI          3.141592653589793238462643383279502884

class RubiksCube
{

public:

	//Constructeur
	RubiksCube();

	//Déclaration des méthodes publics nécéssaires au fonctionnement du Rubiks Cube.
	void draw();
	void control();

	//Destructeur (Détruit proprement les cubes du Rubiks Cube)
	~RubiksCube();

	//COULEURS EN FLOAT (Utiles pour colorier les faces des cubes):
	float BLACK[3] = { 0.f, 0.f, 0.f };
	float WHITE[3] = { 1.f, 1.f, 1.f };
	float GREEN[3] = { 0.3451, 0.8353, 0.4078 };
	float YELLOW[3] = { 0.949, 0.949, 0.0824 };
	float ORANGE[3] = { 0.9099, 0.6196, 0.0824 };
	float RED[3] = { 0.9294, 0.1882, 0.1882 };
	float BLUE[3] = { 0.1099, 0.3725, 0.9961 };

private:

	//Initialisation des cubes et de leur taille et les met dans une liste.
	float size;
	void initCubes();
	std::vector<Cube*> cube_list;

	//Initialisation d'une horloge propre au Rubiks Cube pour gérer les temps de rotations.
	sf::Clock clock;

	//Déclaration des methodes de rotation.
	void shuffle();
	void rotate(const __int8 i, const __int8 s);

	//Création des attributs nécéssaires au fonctionnement des rotations du Rubiks Cube.
	int rotation_count;
	float rotation_speed;
	bool rotating;
	sf::Time last_rotation_timing;
	std::vector<int> current_rotation;

	//Création des attributs nécéssaires au fonctionnement du mélange du Rubiks Cube.
	int shuffling_count;
	bool shuffling;

};

