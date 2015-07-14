#pragma once

#include <Engine/Window.h>
#include <Engine/GLSLProgram.h>
#include <Engine/Camera2D.h>
#include <Engine/InputManager.h>
#include <Engine/SpriteBatch.h>

#include "Player.h"
#include "Level.h"
#include "Bullet.h"

class Zombie;

enum class GameState {
	PLAY,
	EXIT
};

class MainGame
{
public:
	MainGame();
	~MainGame();

	/// Runs the game
	void run();

private:
	/// Initializes the core systems
	void initSystems();

	/// Initializes the level and sets up everything
	void initLevel();

	/// Initializes the shaders
	void initShaders();

	/// Main game loop for the program
	void gameLoop();

	/// Updates all agents
	void updateAgents();

	/// Updates all bullets
	void updateBullets();

	/// Checks the victory condition
	void checkVictory();

	/// Handles input processing
	void processInput();

	/// Renders the game
	void drawGame();

	/// Member Variables
	Engine::Window _window; ///< The game window

	Engine::GLSLProgram _textureProgram; ///< The shader program

	Engine::InputManager _inputManager; ///< Handles input

	Engine::Camera2D _camera; ///< Main Camera

	Engine::SpriteBatch _agentSpriteBatch; ///< Draws all agents

	std::vector<Level*> _levels; ///< vector of all levels

	int _screenWidth, _screenHeight;

	float _fps;

	int _currentLevel;

	Player* _player;
	std::vector<Human*> _humans; ///< Vector of all humans
	std::vector<Zombie*> _zombies; ///< Vector of all zombies
	std::vector<Bullet> _bullets;

	int _numHumansKilled; ///< Humans killed by player
	int _numZombiesKilled; ///< Zombies killed by player

	GameState _gameState;
};