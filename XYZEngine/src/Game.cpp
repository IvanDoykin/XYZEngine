#include "Game.h"

namespace Engine
{
	void Game::Run()
	{
		sf::Clock deltaClock;

		float fixedCounter = 0.f;

		while (RenderSystem::Instance()->GetMainWindow().isOpen())
		{
			sf::Event event;
			while (RenderSystem::Instance()->GetMainWindow().pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					RenderSystem::Instance()->GetMainWindow().close();
				}
			}

			sf::Time dt = deltaClock.restart();
			float deltaTime = dt.asSeconds();

			RenderSystem::Instance()->GetMainWindow().clear();

			GameWorld::Instance()->Update(deltaTime);
			GameWorld::Instance()->FixedUpdate(deltaTime);
			GameWorld::Instance()->Render();
			GameWorld::Instance()->LateUpdate();

			RenderSystem::Instance()->GetMainWindow().display();
		}
	}
}