#pragma once

#include <list>
#include "objectInterface.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
#include "bullet.h"

class objectInterface
{
public:
	virtual ~objectInterface() {}	
	virtual std::list<Bullet*> update(float delta , std::list<Bullet*> bullets)=0;
	virtual void draw(sf::RenderWindow *window) {};

private:




};

