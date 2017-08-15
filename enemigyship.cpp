#include "enemigyship.h"
#include "Colision.h"
#include <string>
#include <iostream>
#include <math.h>
#include <time.h>


using namespace std;

Enemigyship::Enemigyship(std::string resource, int posX, int posY, int numberFil)
{
	if (!texture.loadFromFile("resources/enemy.png"))
		throw "Background error";
	else
		sprite.setTexture(texture);

	//posicionamos el sprite
	sprite.setPosition(posX, posY);

	alive = true;
	srand(time(NULL));
		healt = 3;

}


Enemigyship::~Enemigyship()
{

}

std::list<Bullet*> Enemigyship::update(float delta, std::list<Bullet*> bullets)
{

	BulletIndex firstBullet, lastBullet;

	//Borramos balas muertas
	//RECORRER ITERADOR DE BALAS
	firstBullet = bullets.begin();
	lastBullet = bullets.end();


	while (firstBullet != lastBullet)
	{
		Bullet* bullet = (*firstBullet);
		firstBullet++;

		//Detecion de la colision 
		sf::Sprite bulletSprite = bullet->getSprite();
		if (bullet->getIsBulletPlayer()) {
			bool Col = Collision::PixelPerfectTest(sprite, bulletSprite);
			if (Col) {
				alive = reduceHelt();
				bullet->setAlive(false);
			}
		}
		
	}

	
	int probBullet = rand() % 1000;
	if (probBullet < 1) {
		cout << probBullet << endl;
		Bullet *bullet = new Bullet(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + 30, false);
		bullets.push_back(bullet);

	}
	return bullets;
}

void Enemigyship::draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

bool Enemigyship::move(float delta, int direction)
{
	if (direction == 0) {
		float moveVelocity = -constants::GLOBAL_ENEMY_VELOCITY * delta;
		sprite.move(moveVelocity, 0.f);
	}
	else if (direction == 1) {
		float moveVelocity = constants::GLOBAL_ENEMY_VELOCITY * delta;
		sprite.move(moveVelocity, 0.f);
	}
	else if(direction == 2){
		float moveVelocity = constants::GLOBAL_ENEMY_V_VELOCITY * delta;
		sprite.move(0.f, moveVelocity*6);

	}
	return false;
}

bool Enemigyship::reduceHelt()
{
	healt = healt - 1;
	
	if (healt == 0) {
		return false;
	}
	else if (healt == 2) {
		if (!texture.loadFromFile("resources/enemy_1.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	else if (healt == 1) {
		if (!texture.loadFromFile("resources/enemy_2.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	return true;
}


