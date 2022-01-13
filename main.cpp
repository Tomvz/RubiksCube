#include "RubiksCube.h"

sf::Window* initOpenglWindow() //Cr�ation de la fen�tre et appel des fonctions OpenGL n�c�ssaires.
{
	sf::ContextSettings settings;
	settings.depthBits = 24;

	sf::Window* window = new sf::Window(sf::VideoMode(800, 800), "Rubiks Cube", sf::Style::Close, settings);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearDepth(1.f);
	glClearColor(0.5, 0.5, 0.5, 0.f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.f, window->getSize().x / window->getSize().y, 1.f, 500.f);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -40);

	return window;
}

void controlCamera(float cs) //G�re les inputs d�di�s au mouvement de la cam�ra.
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		glRotated(cs, 1, 0, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		glRotated(-cs, 1, 0, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
	{
		glRotated(cs, 0, 1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
	{
		glRotated(-cs, 0, 1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		glRotated(cs, 0, 0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
	{
		glRotated(-cs, 0, 0, 1);
	}
}

int main()
{

	//Cr�ation des variables de bases n�c�ssaires au fonctionnement du programme.

	sf::Window *window = initOpenglWindow();
	sf::Event e;

	sf::Clock clock;
	sf::Time camera_last_tick(sf::seconds(0));

	RubiksCube* rc = new RubiksCube(); //Cr�ation du Rubiks Cube.

	while (window->isOpen()) //Boucle principale
	{
		//G�re la fermeture de la fen�tre.
		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		rc->control();

		if (clock.getElapsedTime() >  camera_last_tick + sf::Time(sf::seconds(0.01))) //G�re le temps entre chaque d�placements de cam�ra (1� / 0.01s)
		{
			camera_last_tick = clock.getElapsedTime();
			controlCamera(1);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Nettoyage de la fen�tre.

		rc->draw();

		window->display(); //Affiche la fen�tre.

	}

	//Suppresion des variables cr��es par allocation dynamique.
	delete rc;
	rc = nullptr;
	delete window;
	window = nullptr;

	//FIN
	return 0;
}