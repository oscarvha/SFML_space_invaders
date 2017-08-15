#include "bullet.h"
#include <string>
#include <iostream>
#include "config.h"


using namespace std;



Bullet::Bullet(int posx, int posy, bool bulletPlayer)
{
	alive = true; 
	isBulletPlayer = bulletPlayer;


	//CARGA DEL SPRITE
	if (!texture.loadFromFile("resources/bullet.png"))
		throw "Background error";
	else
		sprite.setTexture(texture);

	//  escala absoluta del objeto
	sprite.setScale(0.12f, 0.12f);

	//posicionamos el sprite
	sprite.setPosition(posx, posy);

	if (!isBulletPlayer) {
		sprite.setRotation(180);
	}

}


Bullet::~Bullet()
{

}

void Bullet::update(float delta)
{
	if (isBulletPlayer) {


		if (sprite.getPosition().y < -30) {
			alive = false;
			cout << "Boorrar bala" << endl;
		}
		else {
			float moveVelocity = -constants::GLOBAL_BULLET_VELOCITY * delta;
			sprite.move(0.f, moveVelocity);

		}
	}
	else {
		//ES BALA DE ENEMIGO
		if (sprite.getPosition().y > constants::GLOBAL_SCREEN_HEIGHT) {
			alive = false;
			cout << "Borrar bala enemigo" << endl;
		}
		else {
			float moveVelocity = constants::GLOBAL_BULLET_VELOCITY * delta;
			sprite.move(0.f, +moveVelocity);
		}
	}


}

void Bullet::draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

