#pragma once

#include "Core.h"

#ifdef PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{


	Engine::Log::Init();
	CORE_WARN("Initialized Loging");
	APP_INFO("initialized app log");

	Engine::Application* app = Engine::CreateApplication();
	app->Run();
	delete app;
}

#endif