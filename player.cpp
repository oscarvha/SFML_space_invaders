#include "player.h"
#include "config.h"
#include <string>
#include <iostream>
#include "Colision.h"


using namespace std;



Player::Player(std::string resource,int posX, int posY)
{
	//CARGA DEL SPRITE
	if (!texture.loadFromFile("resources/player.png"))
		throw "Background error";
	else
		sprite.setTexture(texture);

	//  escala absoluta del objeto
	sprite.setScale(0.12f, 0.12f);

	//posicionamos el sprite
	sprite.setPosition(600, 650);

	alive = true;
	healt = 3;
}

Player::~Player()
{
}

std::list<Bullet*> Player::update(float delta, std::list<Bullet*> bullets)
{
	timeCount += delta;
	//TEST RIGHT MOVE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// Comprobamos que este en los limites de la pantalla
		if (sprite.getPosition().x + sprite.getGlobalBounds().width < constants::GLOBAL_SCREEN_WIDTH)
		{
			// velocidad pro el tiempo delta para controlar que siempre se mueva la misma cantidad de tiempo
			float moveVelocity = constants::GLOBAL_PLAYER_VELOCITY * delta;
			sprite.move(moveVelocity, 0.f);
		}
	}
	//LEFT MOVE
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{    
		if (sprite.getPosition().x  > 0)
		{
			float moveVelocity = -constants::GLOBAL_PLAYER_VELOCITY * delta;
			sprite.move(moveVelocity, 0.f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (timeCount > 1) {
			cout << sprite.getPosition().x << endl;
			Bullet *bullet;
			bullet = new Bullet(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + 30, true);
			bullets.push_back(bullet);
			timeCount = 0;
		}

	}

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
		if (!bullet->getIsBulletPlayer()) {
			bool Col = Collision::PixelPerfectTest(sprite, bulletSprite);
			if (Col) {
				cout << "hay colision " << endl;
				alive = reduceHealt();
				bullet->setAlive(false);
			}
		}
	}

	return bullets;
}

void Player::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}

bool Player::reduceHealt()
{
	healt = healt - 1;

	if (healt == 0) {
		return false;
	}
	else if (healt == 2) {
		if (!texture.loadFromFile("resources/player_1.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	else if (healt == 1) {
		if (!texture.loadFromFile("resources/player_2.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	return true;
}






