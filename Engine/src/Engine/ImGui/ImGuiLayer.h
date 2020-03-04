#pragma once

#include "Engine/Layer.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/MouseEvent.h"
#include "Engine/Events/KeyEvent.h"

namespace Engine
{
	class ENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time = 0.0f;

		bool OnMouseReleasedEvent(MouseButtonReleasedEvent&);
		bool OnMousePressedEvent(MouseButtonPressedEvent&);
		bool OnMouseMovedEvent(MouseMovedEvent&);
		bool OnMouseScrolledEvent(MouseScrolledEvent&);
		bool OnKeyPressedEvent(KeyPressedEvent&);
		bool OnKeyReleasedEvent(KeyReleasedEvent&);
		bool OnKeyTypedEvent(KeyTypedEvent&);
		bool OnWindowResizedEvent(WindowResizeEvent&);
	};
}