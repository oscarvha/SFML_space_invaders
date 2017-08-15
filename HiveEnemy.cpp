#include "HiveEnemy.h"
#include <string>
#include <iostream>


using namespace std;



HiveEnemy::HiveEnemy()
{

	colisonLeft = true;

	for (int i = 0; i < 4; i++) {
		for (int e = 0; e < 7; e++) {
			Enemigyship *enemy = new Enemigyship("resources/enemy.png", 0 + e * 100, 0 + i * 80, true);
			listEnemy.push_back(enemy);
		}
	}

	cout << listEnemy.size() << endl;



}


HiveEnemy::~HiveEnemy()
{
}

std::list<Bullet*> HiveEnemy::update(float delta, std::list<Bullet*> bullets)
{

	bool detectColision = false;
	int direction = 0;

	int enemyVelocity = 100;


	BulletIndex firstEnemy, lastEnemy;

	firstEnemy = listEnemy.begin();
	lastEnemy = listEnemy.end();

	//DETECTAMOS LA COLISION PARA EL MOVIMIENTO CONJUNTO
	while (firstEnemy != lastEnemy)
	{
		Enemigyship* enemy = (*firstEnemy);
		sf::Sprite sprite = enemy->getSrpite();

		if (sprite.getPosition().x < 0 - sprite.getGlobalBounds().width/2)
		{
			if (detectColision == false) {
			
				colisonLeft = true;
				detectColision = true;
				//Right
				

			}
		}
		else if (sprite.getPosition().x + sprite.getGlobalBounds().width * 1 > constants::GLOBAL_SCREEN_WIDTH)
			{
			if (detectColision == false) {
			
					colisonLeft = false;
					detectColision = true;
			
				}
	
		}
		firstEnemy++;
	}


	firstEnemy = listEnemy.begin();
	lastEnemy = listEnemy.end();


	//MOVEMOS EN FUNCION DEL RESULTADO ANTERIOR
	while (firstEnemy != lastEnemy)
	{
		Enemigyship* enemy = (*firstEnemy);

		sf::Sprite sprite = enemy->getSrpite();
		//PARA COMPROBAR COLISIONES Y DISPARO
		bullets = enemy->update(delta, bullets);
		if (colisonLeft == false) {
			//nos movemos a la derecha
			enemy->move(delta,0);
		}
		else {
			if (detectColision) {
				enemy -> move(delta, 2);
			}
			enemy->move(delta, 1);
		}
		firstEnemy++;
	}
	firstEnemy = listEnemy.begin();
	lastEnemy = listEnemy.end();


	//BUSCAMOS LOS ELEMENTOS VIVOS 
	while (firstEnemy != lastEnemy)
	{
		cout << colisonLeft << endl;
		Enemigyship* enemy = (*firstEnemy);
		firstEnemy++;
		if (!enemy->getAlive()) {
			listEnemy.remove(enemy);
			delete enemy;
		}

	}

	return bullets;

}

void HiveEnemy::draw(sf::RenderWindow * window)
{
	BulletIndex firstEnemy, lastEnemy;

	listEnemy.size();

	firstEnemy = listEnemy.begin();
	lastEnemy = listEnemy.end();



	while (firstEnemy != lastEnemy)
	{
		Enemigyship* enemy = (*firstEnemy);
		enemy->draw(window);
		firstEnemy++;
	}

}
