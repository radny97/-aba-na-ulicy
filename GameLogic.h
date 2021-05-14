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
	std::unordered_map<std::string, Object*> GetAllObjects(); //póŸniej tê funkcjê porozdzielaæ na update, getModel itd
	bool IsTimeToGenerateCar();
	void GenerateCar();
	void InputControl();

private:
	Object* frogObject;
	std::unordered_map<std::string, Object*> allObjects;

	sf::Clock timer;
	sf::Time elapsedTime;

	bool leftKeyPressed;
	bool rightKeyPressed;
};
