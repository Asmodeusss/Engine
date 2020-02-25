#include "Application.h"
namespace Engine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true);
	}

	//must be defined in client;
	Application* CreateApplication();
}