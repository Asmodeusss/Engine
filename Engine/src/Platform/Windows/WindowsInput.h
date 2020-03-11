#pragma once

#include "Engine/Input.h"

namespace Engine
{
	class WindowsInput : public Input
	{
	public:
		WindowsInput();
		~WindowsInput();
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMousePressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual std::pair<float, float> GetMousePosImpl() override;

		virtual bool HandleKeyboardPressedImpl(KeyPressedEvent&) override;
		virtual bool HandleKeyboardReleasedImpl(KeyReleasedEvent&) override;
		virtual bool HandleKeyboardTypedImpl(KeyTypedEvent&) override;

		virtual KeyCode GetKeyCode(int) override;

	private:
	};
}