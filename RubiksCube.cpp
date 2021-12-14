#include "RubiksCube.h"

RubiksCube::RubiksCube()
{
	this->size = 5.f;
	this->initCubes();
}

void RubiksCube::shuffle()
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr_i(0, 5);
	std::uniform_int_distribution<> distr_s(0, 1);


	for (int i(0); i < 20; i++)
	{
		this->rotate(distr_i(gen), distr_s(gen));
	}
}

void RubiksCube::rotate(int i, int s)
{

	float d(90 * PI / 180);
	float g(270 * PI / 180);

	if (i == 0)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == -this->size)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(g) + z * sin(g)));
					c->setZ(round(-x * sin(g) + z * cos(g)));
				
					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(g) + z * sin(g));
						p->z = (-x * sin(g) + z * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == -this->size)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(d) + z * sin(d)));
					c->setZ(round(-x * sin(d) + z * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(d) + z * sin(d));
						p->z = (-x * sin(d) + z * cos(d));
					}
				}
			}
		}
	}

	if (i == 1)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == 0)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(g) + z * sin(g)));
					c->setZ(round(-x * sin(g) + z * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(g) + z * sin(g));
						p->z = (-x * sin(g) + z * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == 0)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(d) + z * sin(d)));
					c->setZ(round(-x * sin(d) + z * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(d) + z * sin(d));
						p->z = (-x * sin(d) + z * cos(d));
					}
				}
			}
		}
	}

	if (i == 2)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == this->size)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(g) + z * sin(g)));
					c->setZ(round(-x * sin(g) + z * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(g) + z * sin(g));
						p->z = (-x * sin(g) + z * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getY() == this->size)
				{
					float x = c->getX();
					float z = c->getZ();
					c->setX(round(x * cos(d) + z * sin(d)));
					c->setZ(round(-x * sin(d) + z * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float z = p->z;
						p->x = (x * cos(d) + z * sin(d));
						p->z = (-x * sin(d) + z * cos(d));
					}
				}
			}
		}
	}
	
	if (i == 3)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == -this->size)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(g) + y * sin(g)));
					c->setY(round(-z * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(g) + y * sin(g));
						p->y = (-z * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == -this->size)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(d) + y * sin(d)));
					c->setY(round(-z * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(d) + y * sin(d));
						p->y = (-z * sin(d) + y * cos(d));
					}
				}
			}
		}
	}
	
	if (i == 4)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == 0)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(g) + y * sin(g)));
					c->setY(round(-z * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(g) + y * sin(g));
						p->y = (-z * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == 0)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(d) + y * sin(d)));
					c->setY(round(-z * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(d) + y * sin(d));
						p->y = (-z * sin(d) + y * cos(d));
					}
				}
			}
		}
	}
	
	if (i == 5)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == this->size)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(g) + y * sin(g)));
					c->setY(round(-z * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(g) + y * sin(g));
						p->y = (-z * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getX() == this->size)
				{
					float z = c->getZ();
					float y = c->getY();
					c->setZ(round(z * cos(d) + y * sin(d)));
					c->setY(round(-z * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float z = p->z;
						float y = p->y;
						p->z = (z * cos(d) + y * sin(d));
						p->y = (-z * sin(d) + y * cos(d));
					}
				}
			}
		}
	}

	if (i == 6)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == -this->size)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(g) + y * sin(g)));
					c->setY(round(-x * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(g) + y * sin(g));
						p->y = (-x * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == -this->size)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(d) + y * sin(d)));
					c->setY(round(-x * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(d) + y * sin(d));
						p->y = (-x * sin(d) + y * cos(d));
					}
				}
			}
		}
	}

	if (i == 7)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == 0)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(g) + y * sin(g)));
					c->setY(round(-x * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(g) + y * sin(g));
						p->y = (-x * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == 0)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(d) + y * sin(d)));
					c->setY(round(-x * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(d) + y * sin(d));
						p->y = (-x * sin(d) + y * cos(d));
					}
				}
			}
		}
	}

	if (i == 8)
	{
		if (s == 0)
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == this->size)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(g) + y * sin(g)));
					c->setY(round(-x * sin(g) + y * cos(g)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(g) + y * sin(g));
						p->y = (-x * sin(g) + y * cos(g));
					}
				}
			}
		}
		else
		{
			for (Cube* c : this->cube_list)
			{
				if (c->getZ() == this->size)
				{
					float x = c->getX();
					float y = c->getY();
					c->setX(round(x * cos(d) + y * sin(d)));
					c->setY(round(-x * sin(d) + y * cos(d)));

					for (sf::Vector3f* p : c->getPoints())
					{
						float x = p->x;
						float y = p->y;
						p->x = (x * cos(d) + y * sin(d));
						p->y = (-x * sin(d) + y * cos(d));
					}
				}
			}
		}
	}
}

std::vector<Cube*> RubiksCube::getCubes()
{
	return this->cube_list;
}

void RubiksCube::draw()
{
	for (Cube *c : this->cube_list)
	{
		c->draw();
	}
}

void RubiksCube::control(sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::W)
		{
			this->rotate(0, 0);
		}
		else if (ev.key.code == sf::Keyboard::X)
		{
			this->rotate(0, 1);
		}
		else if (ev.key.code == sf::Keyboard::Q)
		{
			this->rotate(1, 0);
		}
		else if (ev.key.code == sf::Keyboard::S)
		{
			this->rotate(1, 1);
		}
		else if (ev.key.code == sf::Keyboard::A)
		{
			this->rotate(2, 0);
		}
		else if (ev.key.code == sf::Keyboard::Z)
		{
			this->rotate(2, 1);
		}
		else if (ev.key.code == sf::Keyboard::V)
		{
			this->rotate(3, 0);
		}
		else if (ev.key.code == sf::Keyboard::B)
		{
			this->rotate(3, 1);
		}
		else if (ev.key.code == sf::Keyboard::F)
		{
			this->rotate(4, 0);
		}
		else if (ev.key.code == sf::Keyboard::G)
		{
			this->rotate(4, 1);
		}
		else if (ev.key.code == sf::Keyboard::R)
		{
			this->rotate(5, 0);
		}
		else if (ev.key.code == sf::Keyboard::T)
		{
			this->rotate(5, 1);
		}
		else if (ev.key.code == sf::Keyboard::U)
		{
			this->rotate(6, 0);
		}
		else if (ev.key.code == sf::Keyboard::I)
		{
			this->rotate(6, 1);
		}
		else if (ev.key.code == sf::Keyboard::J)
		{
			this->rotate(7, 0);
		}
		else if (ev.key.code == sf::Keyboard::K)
		{
			this->rotate(7, 1);
		}
		else if (ev.key.code == sf::Keyboard::Comma)
		{
			this->rotate(8, 0);
		}
		else if (ev.key.code == sf::Keyboard::Period)
		{
			this->rotate(8, 1);
		}
	}
}

RubiksCube::~RubiksCube()
{
	for (Cube* c : this->cube_list)
	{
		delete c;
		c = nullptr;
	}
}

void RubiksCube::initCubes()
{

	float colors1[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, size, size, size, colors1));

	float colors2[6][3] = {
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
		{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
		{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(0, size, size, size, colors2));

	float colors3[6][3] = {
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
		{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
		{this->RED[0], this->RED[1], this->RED[2]},
		{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
		{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, size, size, size, colors3));

	float colors4[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, 0, size, size, colors4));

	float colors5[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(0, 0, size, size, colors5));

	float colors6[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, 0, size, size, colors6));

	float colors7[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, -size, size, size, colors7));

	float colors8[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(0, -size, size, size, colors8));

	float colors9[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->GREEN[0], this->GREEN[1], this->GREEN[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, -size, size, size, colors9));

	float colors10[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, size, 0, size, colors10));

	float colors11[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(size, size, -size, size, colors11));

	float colors12[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, 0, 0, size, colors12));

	float colors13[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(size, 0, -size, size, colors13));

	float colors14[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(size, -size, -0, size, colors14));

	float colors15[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->RED[0], this->RED[1], this->RED[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(size, -size, -size, size, colors15));

	float colors16[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(0, size, -size, size, colors16));

	float colors17[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(-size, size, -size, size, colors17));

	float colors18[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(0, 0, -size, size, colors18));

	float colors19[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(-size, 0, -size, size, colors19));

	float colors20[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(0, -size, -size, size, colors20));

	float colors21[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLUE[0], this->BLUE[1], this->BLUE[2]},
	};

	this->cube_list.push_back(new Cube(-size, -size, -size, size, colors21));

	float colors22[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, size, 0, size, colors22));

	float colors23[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, 0, 0, size, colors23));

	float colors24[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->ORANGE[0], this->ORANGE[1], this->ORANGE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(-size, -size, 0, size, colors24));

	float colors25[6][3] = {
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->WHITE[0], this->WHITE[1], this->WHITE[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(0, size, 0, size, colors25));

	float colors26[6][3] = {
	{this->YELLOW[0], this->YELLOW[1], this->YELLOW[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	{this->BLACK[0], this->BLACK[1], this->BLACK[2]},
	};

	this->cube_list.push_back(new Cube(0, -size, 0, size, colors26));

}