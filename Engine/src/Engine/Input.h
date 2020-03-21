#pragma once

#include "Engine/Core/Core.h"
#include "Engine/KeyCodes.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/KeyEvent.h"

namespace Engine
{
	class ENGINE_API Input
	{
	public:

		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMousePressed(int button) { return s_Instance->IsMousePressedImpl(button); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->GetMousePosImpl(); }

		static bool HandleKeyboardPressed(KeyPressedEvent& e) { return s_Instance->HandleKeyboardPressedImpl(e); }
		static bool HandleKeyboardReleased(KeyReleasedEvent& e) { return s_Instance->HandleKeyboardReleasedImpl(e); }
		static bool HandleKeyboardTyped(KeyTypedEvent& e) { return s_Instance->HandleKeyboardTypedImpl(e); }

		static KeyCode GetKeyCode(int);
	
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		
		virtual bool IsMousePressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;

		virtual bool HandleKeyboardPressedImpl(KeyPressedEvent&) = 0;
		virtual bool HandleKeyboardReleasedImpl(KeyReleasedEvent&) = 0;
		virtual bool HandleKeyboardTypedImpl(KeyTypedEvent&) = 0;

		bool keyState[316];
		int keyRepeats[316];

	

	private:
		static Input* s_Instance;
		
	};
}