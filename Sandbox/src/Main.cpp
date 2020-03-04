#include "Engine.h"
#include <iostream>


class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		APP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Engine::Event& event) override
	{
		APP_INFO("{0}", event);
	}
};

class Game : public Engine::Application
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());

	}

	~Game()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Game();
}