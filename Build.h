#pragma once
#include "objectInterface.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "bullet.h"
#include "objectInterface.h"
class Build : public objectInterface
{
public:
	Build(std::string resource, int posX, int posY);
	~Build();
	std::list<Bullet*> update(float delta, std::list<Bullet*> bullets);
	void draw(sf::RenderWindow *window);
	bool reduceHealt();
	bool isAlive() { return alive; };

private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool alive;
	int healt;
	typedef std::list<Bullet*> bulletsList;
	typedef std::list<Bullet*>::iterator BulletIndex;

};

