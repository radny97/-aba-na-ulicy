#pragma once
#include "FrogObject.h"
#include "CarObject.h"
#include "Playground.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

enum velocity
{
	verySlowVelocity = 1,
	slowVelocity = 3,
	mediumVelocity = 5,
	fastVelocity = 7,
	veryFastVelocity = 9
};

class GameLogic
{
public:
	GameLogic();
	void UpdateLogic();
	std::unordered_map<int, Object*> GetAllObjects();
	void UpdateCar();
	void AddCarToDeleteListIfItDroveOfPlayground(Object* car);
	bool IsTimeToGenerateCar();
	void GenerateCar(Track track);
	void InputControl();
	void DeleteObjects();

private:
	Object* frogObject;
	Playground* playground;

	std::unordered_map<int, Object*> allObjects;
	std::unordered_map<int, Object*> objectsToDelete;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool leftKeyPressed;
	bool rightKeyPressed;
	int positionOfFrogIterator;
};
