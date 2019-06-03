
#include <AriEngine.h>

class Sandbox : public AriEngine::Application
{
	public:
		Sandbox()
		{}
		~Sandbox()
		{}

	private:

};

AriEngine::Application* AriEngine::CreateApplication()
{
	return new Sandbox();
}