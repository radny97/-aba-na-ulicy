#include "GameLogic.h"

GameLogic::GameLogic()
{
	this->player = new Player();

	this->playground = new PlaygroundLogic();

	this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;

	this->frogObject = new FrogObject(
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX,
		this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateY,
		this->player
	);

	this->allObjects.insert(std::make_pair(this->frogObject->ID, this->frogObject));

	
}

void GameLogic::UpdateLogic()
{
	//bedzie coœ w rodzaju animacji, które bêd¹ polegaæ na zmianie "stanu" obiektu, po up³yniêciu czasu mierzonego tutaj

	//tu bêdzie pêtla wszystkich obiektów w której bêdzie coœ w stylu Object.Update()
	for (auto& iterator : this->allObjects)
	{
		AddCarToDeleteListIfItDroveOfPlayground(iterator.second);

		iterator.second->UpdateObject();
	}

	for (auto& firstLoopObject : this->allObjects)
	{
		for (auto& secondLoopObject : this->allObjects)
		{
			if (firstLoopObject.second != secondLoopObject.second)
			{
				if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == CollisionType::carCarColision)
				{
					//tutaj coœ ze zmian¹ prêdkoœci itp
				}
				if (CheckCollision(firstLoopObject.second, secondLoopObject.second) == CollisionType::frogCarCollision)
				{
					this->player->score -= (this->playground->frogStandingPoints.size() - 1 - this->positionOfFrogIterator);
					this->positionOfFrogIterator = this->playground->frogStandingPoints.size() - 1;
					this->frogObject->Death(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
					//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
					//if (this->player->lives != 0)
					//{
					//	this->player->lives -= 1;
					//}
				}
			}
		}
	}


	for (auto& track : this->playground->tracks)
	{
		if (IsTimeToGenerateCar(&track))
		{
			GenerateCar(track);
		}
	}

	InputControl();

	if (!this->objectsToDelete.empty())
	{
		DeleteObjects();
	}

}

std::unordered_map<int, Object*> GameLogic::GetAllObjects()
{
	return this->allObjects;
}

PlaygroundLogic* GameLogic::GetPlaygroundLogic()
{
	return this->playground;
}

CollisionType GameLogic::CheckCollision(Object* firstObject, Object* secondObject)
{
	if (firstObject->type == "car" && firstObject->collisional)
	{
		CarObject* car;
		car = dynamic_cast<CarObject*>(firstObject);
		if (secondObject->collisional &&
			(secondObject->CheckIfCollisionPointIsInBounds(*car->frontCollisionPoint) 
		|| secondObject->CheckIfCollisionPointIsInBounds(*car->backCollisionPoint)))
		{
			if (secondObject->type == "frog")
			{
				std::cout << "kolizja ¿aba samochód";// << std::endl << std::endl;
				return CollisionType::frogCarCollision;
			}
			if (secondObject->type == "car")
			{
				std::cout << "kolizja samochód samochód";// << std::endl << std::endl;
				return CollisionType::carCarColision;
			}
		}
	}
	return CollisionType::noCollision;
}

void GameLogic::InputControl()
{
	FrogObject* frog;
	frog = dynamic_cast<FrogObject*>(this->frogObject);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKeyPressed && frog->stateOfFrog == StateOfFrog::normalStanding)
	{
		if (this->positionOfFrogIterator > 0)
		{
			this->positionOfFrogIterator--;
			//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			this->frogObject->Jump(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			//this->player->score++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKeyPressed)
	{
		if (this->positionOfFrogIterator < this->playground->frogStandingPoints.size()-1 && frog->stateOfFrog == StateOfFrog::normalStanding)
		{
			this->positionOfFrogIterator++;
			//this->frogObject->SetPosX(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			this->frogObject->Jump(this->playground->frogStandingPoints.at(this->positionOfFrogIterator).coordinateX);
			//this->player->score--;
		}
	}

	this->leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

//void GameLogic::UpdateCar()
//{
//	for (auto& iterator : this->allObjects)
//	{
//		AddCarToDeleteListIfItDroveOfPlayground(iterator.second);
//		if (iterator.second->type == "car")
//		{
//			iterator.second->Move();
//		}
//	}
//}

bool GameLogic::IsTimeToGenerateCar(Track* track)
{
	track->elapsedTime = track->timer.getElapsedTime();

	if (track->elapsedTime.asMilliseconds() > track->randomNumber)
	{
		track->timer.restart();
		track->randomNumber = rand() % 5000 + 1000;
		return true;
	}	
	else
		return false;
}

void GameLogic::GenerateCar(Track track)
{
	Object* carObject = new CarObject(track.beginingOfTrack.coordinateX, track.beginingOfTrack.coordinateY, track.fromDownToUp);
	this->allObjects.insert(std::make_pair(carObject->ID, carObject));
}

void GameLogic::AddCarToDeleteListIfItDroveOfPlayground(Object *car)
{
	if (car->posY < -Utilities::carImageSizeY || car->posY > Utilities::screenResolutionY + Utilities::carImageSizeY)
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


SubStateOfGame GameLogic::GetSubStateOfGame()
{
	return this->subState;
}

void GameLogic::SetSubStateOfGame(SubStateOfGame subState)
{
	this->subState = subState;
}