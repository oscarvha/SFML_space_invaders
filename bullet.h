#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "config.h"
class Bullet 
{
public:
	Bullet(int posx, int posy, bool bulletPlayer);
	~Bullet();

	void update(float delta);
	void draw(sf::RenderWindow *window);

	//geters y setters
	bool getAlive(){ return alive; };
	sf::Sprite getSprite() { return sprite; };
	bool getIsBulletPlayer() { return isBulletPlayer; };
	void setAlive(bool aliv) { alive = aliv; };

private:
	//BALA VIVA O NO
	bool alive; 
	//Saber si la bala es del jugador o no 
	bool isBulletPlayer;
	sf::Sprite sprite;
	sf::Texture texture;
};

