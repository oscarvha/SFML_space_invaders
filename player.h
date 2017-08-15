#pragma once
#include "objectInterface.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "bullet.h"

class Player : public
	objectInterface
{
public:
	Player(std::string resource,int posX, int posY);
	~Player();
	std::list<Bullet*> update(float delta, std::list<Bullet*> bullets);
	void draw(sf::RenderWindow *window);

	bool reduceHealt();

	bool getAlive() { return alive; };



private:
	//SPRITES
	sf::Sprite sprite;
	sf::Texture texture;
	bool alive;
	int healt;
	float timeCount = 0; 

	typedef std::list<Bullet*> bulletsList;
	typedef std::list<Bullet*>::iterator BulletIndex;

	
};

