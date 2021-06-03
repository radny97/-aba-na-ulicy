#pragma once
#include <SFML/Graphics.hpp>
#include "ApplicationState.h"
#include "StateMachine.h"

class GameOverState : public ApplicationState
{
public:
	GameOverState(StateMachine* core_state);

	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	StateMachine* stateMachine;
};

