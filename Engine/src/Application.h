#pragma once

#include "Core.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		virtual void Run();
	};

	
	Application* CreateApplication();
}