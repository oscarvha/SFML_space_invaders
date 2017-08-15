#include "Build.h"
#include "Colision.h"


Build::Build(std::string resource, int posX, int posY)
{
	//CARGA DEL SPRITE
	if (!texture.loadFromFile("resources/base_0.png"))
		throw "Background error";
	else
		sprite.setTexture(texture);

	//  escala absoluta del objeto
	sprite.setScale(0.12f, 0.12f);

	//posicionamos el sprite
	sprite.setPosition(posX, posY);

	alive = true;
	healt = 4;

}

Build::~Build()
{
}

std::list<Bullet*> Build::update(float delta, std::list<Bullet*> bullets)
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
		if (!bullet->getIsBulletPlayer()) {
			bool Col = Collision::PixelPerfectTest(sprite, bulletSprite);
			if (Col) {
				alive = reduceHealt();
				bullet->setAlive(false);
			}
		}
		else {
			bool Col = Collision::PixelPerfectTest(sprite, bulletSprite);
			if (Col) {
				bullet->setAlive(false);
			}

		}

	}
	return bullets;


}

void Build::draw(sf::RenderWindow * window)
{
	window->draw(sprite);
}

bool Build::reduceHealt()
{
	healt = healt - 1;

	if (healt == 0) {
		return false;
	}
	else if (healt == 3) {
		if (!texture.loadFromFile("resources/base_1.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	else if (healt == 2) {
		if (!texture.loadFromFile("resources/base_2.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	else if (healt == 1) {
		if (!texture.loadFromFile("resources/base_3.png"))
			throw "Background error";
		else
			sprite.setTexture(texture);
	}
	return true;
}

