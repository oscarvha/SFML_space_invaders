#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "bullet.h"
#include <list>
#include "enemigyship.h"
#include "HiveEnemy.h"
#include "Build.h"


class Game
{
public:
	//Constructor
	Game(unsigned int witdh, unsigned int height, bool verticalSync, std::string fondo);

	//Clase lanzar juego
	void run();

	void createBackground(std::string resource);

	void mainMenu();
	void gameMode();
	void deadMode();
	void victoryMode();

private:

	//CLASE VENTANA 
	sf::RenderWindow window;
	//RELOJ PARA CONTROLAR EL CICLO DEL JUEGO
	sf::Clock clock;
	//TIME PARA CONTROLAR EL TIEMPO
	sf::Time time;
	//BACKGROUND
	sf::Texture tex_background;
	sf::Sprite background;

	//JUGADOR
	Player *player; 

	//Definimos las listas de balas
	typedef std::list<Bullet*> bulletsList;
	typedef std::list<Bullet*>::iterator BulletIndex;


	//Definimos las listas de los edificios
	typedef std::list<Build*> buildList;
	typedef std::list<Build*>::iterator BuildIndex;

	bulletsList bullets;


	buildList builds;


	HiveEnemy *enemys;

	int gameState; 

	sf::Font MyFont;






};