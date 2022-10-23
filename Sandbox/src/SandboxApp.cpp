#include <Raven.h>

class Sandbox : public Raven::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Raven::Application* Raven::CreateApplication()
{
	return new Sandbox();
}