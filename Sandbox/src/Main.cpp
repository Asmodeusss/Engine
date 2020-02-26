#include "Engine.h"
#include <iostream>

class Game : public Engine::Application
{
public:
	Game()
	{
		std::cout << "Game is running\n";
	}

	~Game()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}