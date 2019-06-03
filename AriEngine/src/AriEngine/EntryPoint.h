#pragma once

#ifdef AE_PLATFORM_WINDOWS

extern AriEngine::Application* AriEngine::CreateApplication();

int main(int argc, char** argv)
{
	AriEngine::Log::Init();

	AE_CORE_TRACE("Initialized Log");
	AE_INFO("Client Log Init");


	auto app = AriEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // AE_PLATFORM_WINDOWS
