#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "RubiksCube.h"
#include <iostream>

sf::Window* initOpenglWindow()
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

	return window;
}

void controlCamera(float cs)
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

	sf::Window *window = initOpenglWindow();

	glTranslatef(0, 0, -40);

	float cameraSpeed(0.01);
	sf::Event e;

	RubiksCube* rc = new RubiksCube(window);

	while (window->isOpen())
	{
		while (window->pollEvent(e))
		{
			rc->control(e);
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		controlCamera(cameraSpeed);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		rc->draw();

		window->display();

	}

	delete rc;
	rc = nullptr;
	delete window;
	window = nullptr;

	return 0;
}
