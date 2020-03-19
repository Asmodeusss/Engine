#include "Enginepch.h"

#include "Application.h"

#include "Engine/Log.h"

#include "Engine/Input.h"

#include "glm/glm.hpp"

#include "Engine/ImGui/ImGuiLayer.h"

#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Engine
{

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyboardPressed));
		dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(Application::OnKeyboardReleased));

		CORE_INFO("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled())
				break;
		}
	}

	void Application::Run()
	{	
		while (m_Running)
		{
			//HZ_PROFILE_SCOPE("RunLoop");

			//float time = (float)glfwGetTime();
			//Timestep timestep = time - m_LastFrameTime;
			//m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					//HZ_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->OnUpdate();//timestep);
				}

				/*m_ImGuiLayer->Begin();
				{
					//HZ_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
				m_ImGuiLayer->End();*/
			}

			m_Window->OnUpdate();
		}

		//auto [x, y] = Input::GetMousePos();
		//CORE_ERROR("{0}, {1}", x, y);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnKeyboardPressed(KeyPressedEvent& e)
	{
		Input::HandleKeyboardPressed(e);
		CORE_INFO("Key pressed {0}", e.GetKeyCode());
		return true;
	}

	bool Application::OnKeyboardReleased(KeyReleasedEvent& e)
	{
		Input::HandleKeyboardReleased(e);
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}