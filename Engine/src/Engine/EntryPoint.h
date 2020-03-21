#pragma once

#include "Engine/Core/Core.h"

#ifdef PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{

	try
	{

		Engine::Log::Init();
		CORE_WARN("Initialized Loging");
		APP_INFO("initialized app log");

		Engine::Application* app = Engine::CreateApplication();
		app->Run();
		delete app;
	}
	catch (std::exception e)
	{
		CORE_ERROR("GLFW ERROR: {}", e.what());
	}
}

#endif