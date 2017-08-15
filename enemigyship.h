#pragma once
#pragma once
#include <list>
#include "objectInterface.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "bullet.h"

class Enemigyship : public
	objectInterface
{
public:
	Enemigyship(std::string resource, int posX, int posY, int numberFila);
	~Enemigyship();
	std::list<Bullet*> update(float delta, std::list<Bullet*> bullets);
	void draw(sf::RenderWindow *window);
	bool move(float delta, int direction);
	bool reduceHelt();
	sf::Sprite getSrpite() { return sprite; };
	bool getAlive() { return alive; };



private:
	//SPRITES 
	sf::Sprite sprite;
	sf::Texture texture;

	//ALIVE
	bool alive; 
	int healt;


	//INT COLISION 
	// 0 sin colision 1 izquierda 2 derecha


	//Definimos las listas de balas
	typedef std::list<Bullet*> bulletsList;
	typedef std::list<Bullet*>::iterator BulletIndex;

};


