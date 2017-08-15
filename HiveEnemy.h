#pragma once
#include "config.h"
#include "objectInterface.h"
#include "enemigyship.h"

class HiveEnemy :public objectInterface	
{
public:
	HiveEnemy();
	~HiveEnemy();
	std::list<Bullet*> update(float delta, std::list<Bullet*> bullets);
	void draw(sf::RenderWindow *window);
	int getTotalEnemy() { return listEnemy.size(); };

private:
	//Definimos las listas de balas
	typedef std::list<Enemigyship*> EnemyList;
	typedef std::list<Enemigyship*>::iterator BulletIndex;
	EnemyList listEnemy;
	bool colisonLeft;

};

