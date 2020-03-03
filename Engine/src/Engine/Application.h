#pragma once
#include "Enginepch.h"

#include "Core.h"
#include "Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/LayerStack.h"
#include "Window.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//defined in client
	Application* CreateApplication();
}