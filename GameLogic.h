#pragma once
#include "FrogObject.h"
#include "CarObject.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class GameLogic
{
public:
	GameLogic();
	void UpdateLogic();
	std::unordered_map<int, Object*> GetAllObjects();
	void UpdateCar();
	void AddCarToDeleteListIfItDroveOfPlayground(Object* car);
	bool IsTimeToGenerateCar();
	void GenerateCar();
	void InputControl();
	void DeleteObjects();

private:
	Object* frogObject;
	std::unordered_map<int, Object*> allObjects;
	std::unordered_map<int, Object*> objectsToDelete;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool leftKeyPressed;
	bool rightKeyPressed;
};
