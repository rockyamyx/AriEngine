#include "aepch.h"
#include "Application.h"

#include "AriEngine\Events\ApplicationEvent.h"
#include "Log.h"

namespace AriEngine
{


	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		AE_TRACE(e);

		while (true);
	}

}