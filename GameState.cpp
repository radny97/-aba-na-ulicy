#include "GameState.h"

GameState::GameState(StateMachine* stateMachine)
{
	this->stateMachine = stateMachine;
}

void GameState::Initialize(sf::RenderWindow* window)
{
	this->player = new Player();
	this->gameLogic = new GameLogic(this->player);
	this->gameGraphics = new GameGraphics();
	this->gameGraphics->SetPlaygroundGraphics(this->gameLogic->GetPlaygroundLogic());
}

void GameState::Update(sf::RenderWindow* window)
{
	//tu bêdzie coœ w rodzaju pobierz z game logic czy trwa gra, czy nowy lewel czy game over
	//if nowy lewel, to nowy playground
	//if gra to to co ni¿ej
	//if game over to zmieñ stan
	//mo¿e jeszcze pauza

	switch (this->gameLogic->GetSubStateOfGame())
	{
	case SubStateOfGame::game:
		this->gameLogic->UpdateLogic();

		this->gameGraphics->UpdateHud(this->gameLogic->player);
		this->gameGraphics->Update(this->gameLogic->GetAllObjects());
		this->gameGraphics->Render(window);
		break;
	case SubStateOfGame::pause:
		
		break;
	case SubStateOfGame::nextLevel:
		this->gameLogic = new GameLogic(this->player);
		this->gameGraphics = new GameGraphics();
		this->gameGraphics->SetPlaygroundGraphics(this->gameLogic->GetPlaygroundLogic());
		break;
	case SubStateOfGame::gameOver:

		break;
	default:
		break;
	}

	
}

void GameState::Destroy(sf::RenderWindow* window)
{
	delete this->gameLogic;
	delete this->gameGraphics;
}