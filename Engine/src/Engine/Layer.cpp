#include "Enginepch.h"
#include "Engine/Layer.h"

namespace Engine
{
	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}
}