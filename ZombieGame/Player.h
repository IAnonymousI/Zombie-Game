#pragma once

#include "Human.h"
#include <Engine/InputManager.h>
#include <Engine/Camera2D.h>
#include "Bullet.h"

class Gun;

class Player : public Human
{
public:
	Player();
	virtual ~Player();

	void init(float speed, glm::vec2 position, Engine::InputManager* inputManager, Engine::Camera2D* camera, std::vector<Bullet>* bullets);
	void addGun(Gun* gun);
	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies) override;

private:
	Engine::InputManager* _inputManager;
	std::vector<Gun*> _guns;
	int _currentGunIndex;
	Engine::Camera2D* _camera;
	std::vector<Bullet>* _bullets;
};