#include "enginepch.h"
#include "Engine/Core/Window.h"

#ifdef PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Engine
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}