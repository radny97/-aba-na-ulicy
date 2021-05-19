#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->frogObject = new FrogObject(100,100);
	this->allObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));

}

void GameLogic::UpdateLogic()
{
	UpdateCar();

	if (IsTimeToGenerateCar())
	{
		GenerateCar();
	}

	InputControl();

	DeleteObjects();
}

std::unordered_map<int, Object*> GameLogic::GetAllObjects()
{
	return this->allObjects;
}

void GameLogic::InputControl()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKeyPressed)
	{
		this->frogObject->posX -= 50;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKeyPressed)
	{
		this->frogObject->posX += 50;
	}

	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

void GameLogic::UpdateCar()
{
	for (auto& iterator : this->allObjects)
	{
		AddCarToDeleteListIfItDroveOfPlayground(iterator.second);
		if (iterator.second->type == "car")
		{
			iterator.second->posY += 4;
		}
	}
}

bool GameLogic::IsTimeToGenerateCar()
{
	srand(time(0));
	int randomNumber = rand() % 3 + 1;

	this->elapsedTime = this->timer.getElapsedTime();

	if (this->elapsedTime.asSeconds() > randomNumber)
	{
		this->timer.restart();
		return true;
	}	
	else
		return false;
}

void GameLogic::GenerateCar()
{
	Object* carObject = new CarObject(350, 0);
	this->allObjects.insert(std::make_pair(carObject->ID, carObject));
}

void GameLogic::AddCarToDeleteListIfItDroveOfPlayground(Object *car)
{
	if (car->posY < 0 || car->posY>720)
	{
		this->objectsToDelete.insert(std::make_pair(car->ID, car));
	}
}

void GameLogic::DeleteObjects()
{
	for (auto& iterator : this->objectsToDelete)
	{
		Object* toDelete = this->allObjects.at(iterator.second->ID);
		this->allObjects.erase(iterator.second->ID);
		delete toDelete;
	}
	this->objectsToDelete.clear();
}