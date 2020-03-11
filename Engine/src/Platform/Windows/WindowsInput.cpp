#include "Enginepch.h"
#include "WindowsInput.h"

#include <GLFW/glfw3.h>
#include "Engine/Application.h"

namespace Engine
{
	Input* Input::s_Instance = new WindowsInput();

	KeyCode Input::GetKeyCode(int key)
	{
		if ((key < 32) || (key > 348)) { return KeyCode::Unknown; }
		else return static_cast<KeyCode>(key);
	}

	WindowsInput::WindowsInput()
	{
		for (int i = 0; i < 316; i++)
		{
			keyState[i] = false;
			keyRepeats[i] = 0;
		}
	}

	WindowsInput::~WindowsInput()
	{
	}

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		//auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		//auto state = glfwGetKey(window, keycode);
		return keyState[keycode];// || GLFW_REPEAT;
	}

	bool WindowsInput::IsMousePressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePosImpl();
		return y;
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	bool WindowsInput::HandleKeyboardPressedImpl(KeyPressedEvent& e)
	{
		if (e.GetKeyCode() == GLFW_KEY_UNKNOWN) return false;

		Input::keyState[e.GetKeyCode()] = true;
		if (e.GetRepeatCount() > 0) Input::keyRepeats[e.GetKeyCode()]++;
		return true;
	}

	bool WindowsInput::HandleKeyboardReleasedImpl(KeyReleasedEvent& e)
	{
		if (e.GetKeyCode() == GLFW_KEY_UNKNOWN) return false;

		Input::keyState[e.GetKeyCode()] = false;
		Input::keyRepeats[e.GetKeyCode()] = 0;
		return true;
	}

	bool WindowsInput::HandleKeyboardTypedImpl(KeyTypedEvent& e)
	{
		return false;
	}
	

}