#include "Player.h"
#include <SDL/SDL.h>

#include "Gun.h"

Player::Player() : _currentGunIndex(-1)
{
}


Player::~Player()
{
}

void Player::init(float speed, glm::vec2 position, Engine::InputManager* inputManager, Engine::Camera2D* camera, std::vector<Bullet>* bullets){
	_speed = speed;
	_position = position;
	_inputManager = inputManager;
	_camera = camera;
	_bullets = bullets;
	_color.r = 0;
	_color.g = 0;
	_color.b = 185;
	_color.a = 255;
}

void Player::addGun(Gun* gun){
	_guns.push_back(gun);
	if (_currentGunIndex == -1){
		_currentGunIndex = 0;
	}
}

void Player::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies){
	if (_inputManager->isKeyPressed(SDLK_w)){
		if (_currentGunIndex == 3){
			_position.y += (_speed / 3);
		}
		else{
			_position.y += _speed;
		}
	}
	else if (_inputManager->isKeyPressed(SDLK_s)){
		if (_currentGunIndex == 3){
			_position.y -= (_speed / 3);
		}
		else{
			_position.y -= _speed;
		}
	}
	if (_inputManager->isKeyPressed(SDLK_a)){
		if (_currentGunIndex == 3){
			_position.x -= (_speed / 3);
		}
		else{
			_position.x -= _speed;
		}
	}
	else if (_inputManager->isKeyPressed(SDLK_d)){
		if (_currentGunIndex == 3){
			_position.x += (_speed / 3);
		}
		else{
			_position.x += _speed;
		}
	}

	if (_inputManager->isKeyPressed(SDLK_1) && _guns.size() >= 0){
		_currentGunIndex = 0;
	}
	else if (_inputManager->isKeyPressed(SDLK_2) && _guns.size() >= 1){
		_currentGunIndex = 1;
	}
	else if (_inputManager->isKeyPressed(SDLK_3) && _guns.size() >= 2){
		_currentGunIndex = 2;
	}
	else if (_inputManager->isKeyPressed(SDLK_4) && _guns.size() >= 3){
		_currentGunIndex = 3;
	}

	if (_currentGunIndex != -1){
		glm::vec2 mouseCoords = _inputManager->getMouseCoords();
		mouseCoords = _camera->convertScreenToWorld(mouseCoords);

		glm::vec2 centerPos = _position + glm::vec2(AGENT_RADIUS);
		glm::vec2 direction = glm::normalize(mouseCoords - centerPos);

		_guns[_currentGunIndex]->update(_inputManager->isKeyPressed(SDL_BUTTON_LEFT), centerPos, direction, *_bullets);
	}

	collideWithLevel(levelData);
}