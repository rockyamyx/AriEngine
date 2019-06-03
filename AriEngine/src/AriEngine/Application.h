#pragma once

#include "Core.h"
#include "Events\Event.h"

namespace AriEngine
{

	class ARI_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();


}

