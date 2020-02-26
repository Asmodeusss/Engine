#pragma once
#include "Enginepch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//defined in client
	Application* CreateApplication();
}