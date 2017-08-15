#include "game.h"
#include "player.h"
#include "bullet.h"

#include <string>
#include <iostream>


using namespace std;



Game::Game(unsigned int witdth, unsigned int height, bool verticalSync, std::string fondo)
{
	//CREAR VENTANA
	window.create(sf::VideoMode(witdth, height), "SPACE INVADERS", sf::Style::Close);

	//SINCRONIZACION VERTICAL
	window.setVerticalSyncEnabled(verticalSync);

	//CREAR BACKGROUND
	createBackground(fondo);

	//Crear player
	player = new Player("resources/player.png", 350,480);
	

	enemys = new HiveEnemy();

	gameState = 0;

	
	

	for (int i = 0; i < 8; i++) {
		Build *edificio2 = new Build("buld.png", i*185, 550);

		builds.push_back(edificio2);

	}

	cout << builds.size() << endl;
	
}

void Game::run()
{

	// Game Loop mientras la ventana esté abierta
	while (window.isOpen())
	{
		if (gameState == 0) {
		
			mainMenu();

		}
		else if (gameState==2){
			
			gameMode();
		

		}else if (gameState == 4) {
		
			deadMode();

		}
		else if (gameState == 6) {

			victoryMode();

		}
	}

}

void Game::createBackground(std::string resource)
{

	if (!tex_background.loadFromFile("resources/space.png"))
		throw "Background error";
	else
		background.setTexture(tex_background);
}

void Game::mainMenu()
{
	sf::Font MyFont;
	if (!MyFont.loadFromFile("resources/dead.ttf"))
	{
		// Error...
	}

	sf::Text text;
	text.setFont(MyFont);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setString("Space Invasors  TFG");
	text.setPosition(400, 300);

	sf::Text textdos;
	textdos.setFont(MyFont);
	textdos.setCharacterSize(20);
	textdos.setString("Pulsa espacio para empezar");
	textdos.setPosition(550, 450);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		gameState = 2;
	}

	window.clear();
	window.draw(background);
	window.draw(text);
	window.draw(textdos);
	window.display();


}

void Game::gameMode()
{
	BulletIndex firstBullet, lastBullet;
	BuildIndex firstBuild, lastBuild;
	float deltaTime = clock.restart().asSeconds();
	if (!player->getAlive()) {
		gameState = 4;
	}

	if (enemys->getTotalEnemy() == 0) {
		gameState = 6;
	}

	//Borramos balas muertas
	//RECORRER ITERADOR DE BALAS
	firstBullet = bullets.begin();
	lastBullet = bullets.end();

	while (firstBullet != lastBullet)
	{
		Bullet* bullet = (*firstBullet);
		firstBullet++;
		if (!bullet->getAlive()) {
			bullets.remove(bullet);
			delete bullet;
		}
	}

	firstBuild = builds.begin();
	lastBuild = builds.end();
	while (firstBuild != lastBuild)
	{
		Build* build = (*firstBuild);
		firstBuild++;
		if (!build->isAlive()) {
			builds.remove(build);
			delete build;
		}


	}


	// Creamos un objeto evento
	sf::Event event;
	// Procesamos la pila de eventos
	while (window.pollEvent(event))
	{
		// Si el evento es de tipo Closed cerramos la ventana
		if (event.type == sf::Event::Closed)
			window.close();


	}

	// Actualizamos los elementos del juego
	bullets = player->update(deltaTime, bullets);
	bullets = enemys->update(deltaTime, bullets);



	firstBuild = builds.begin();
	lastBuild = builds.end();

	while (firstBuild != lastBuild)
	{
		Build* build = (*firstBuild);
		build->update(deltaTime, bullets);
		firstBuild++;

	}

	//RECORRER ITERADOR DE BALAS

	//Primer elemento de la lista
	firstBullet = bullets.begin();

	//Ultimo elemento de la lista
	lastBullet = bullets.end();

	//Mientras el primer y el ultimo elemento sean distintos bucle
	while (firstBullet != lastBullet)
	{
		//Si queremos operar con el objeto debemos hacer asignarlo a un objeto tipo bullet
		Bullet* bullet = (*firstBullet);
		//Accion del objeto
		bullet->update(deltaTime);
		//Pasamos al siguiente 
		firstBullet++;
	}

	// Actualizamos la ventana
	window.clear();
	window.draw(background);

	//Borramos balas muertas
	//RECORRER ITERADOR DE BALAS

	//Primer elemento de la lista
	firstBuild = builds.begin();
	
	//Ultimo elemento de la lista
	lastBuild = builds.end();

	//Mientras el primer y el ultimo elemento sean distintos bucle
	while (firstBuild != lastBuild)
	{
		//Si queremos operar con el objeto 
		Build* build = (*firstBuild);
		build->draw(&window);
		firstBuild++;

	}


	firstBullet = bullets.begin();
	lastBullet = bullets.end();

	while (firstBullet != lastBullet)
	{
		Bullet* bullet = (*firstBullet);
		bullet->draw(&window);
		firstBullet++;
	}

	enemys->draw(&window);
	player->draw(&window);
	window.display();

}

void Game::deadMode()
{
	sf::Font MyFont;
	if (!MyFont.loadFromFile("resources/dead.ttf"))
	{
		// Error...
	}

	sf::Text text;
	text.setFont(MyFont);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setString("HAS MUERTO");
	text.setPosition(200, 150);

	sf::Text textdos;
	textdos.setFont(MyFont);
	textdos.setCharacterSize(20);
	textdos.setString("Pulsa ESC para salir");
	textdos.setPosition(250, 250);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
		exit(0);
	}

	window.clear();
	window.draw(background);
	window.draw(text);
	window.draw(textdos);
	window.display();


}

void Game::victoryMode()
{
	sf::Font MyFont;
	if (!MyFont.loadFromFile("resources/dead.ttf"))
	{
		// Error...
	}

	sf::Text text;
	text.setFont(MyFont);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setString("HAS GANADO");
	text.setPosition(200, 150);

	sf::Text textdos;
	textdos.setFont(MyFont);
	textdos.setCharacterSize(20);
	textdos.setString("Pulsa ESC para salir");
	textdos.setPosition(250, 250);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
		exit(0);
	}

	window.clear();
	window.draw(background);
	window.draw(text);
	window.draw(textdos);
	window.display();

}


