#include <Monsuun.h>

class Sandbox : public Monsuun::Application
{
public:
	Sandbox()
	{}

	~Sandbox()
	{}

};

Monsuun::Application* Monsuun::CreateApplication()
{
	return new Sandbox();
}