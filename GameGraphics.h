#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <regex>
#include "FrogObject.h"
#include "CarObject.h"
#include "FrogObjectSprite.h"
#include "CarObjectSprite.h"

class GameGraphics
{
public:
	GameGraphics();
	void Update(sf::RenderWindow* window, std::unordered_map<std::string, Object*> allModels);

	std::list<ObjectSprite*> listOfObjectSprites;

};
