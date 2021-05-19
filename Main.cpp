#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Utilities.h"

int main()
{
	StateMachine stateMachine;
	sf::RenderWindow window(sf::VideoMode(Utilities::screenResolutionX, Utilities::screenResolutionY), "Zaba na ulicy", sf::Style::Default);

	stateMachine.SetWindow(&window);
	stateMachine.SetState(new GameState(&stateMachine)); //new Menu    ale teraz niech od razu przechodzi do gry

	sf::Clock timer;
	sf::Time elapsedTime;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsedTime = timer.getElapsedTime();

		if (elapsedTime.asMicroseconds() > 16666)
		{
			window.clear();

			stateMachine.Update();

			window.display();
			timer.restart();
		}
	}

	return 0;
}